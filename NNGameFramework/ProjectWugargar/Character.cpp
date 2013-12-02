#include "Character.h"
#include "PlayScene.h"
#include <math.h>


CCharacter::CCharacter(void)
{	
	m_SplashAttack = false;
	m_SuicideBomber = false;
	m_FreezingAttack = false;

	m_AttackTarget = nullptr;
	m_LastAttackTime = 0;
	m_Freeze = false;
	m_BeginFreezingTIme = 0;
	m_TotalFreezingTime = 0;
	m_Sight = 0;
	//sight는 철저하게 캐릭터가 안 겹치게 보이기 위한 연출을 위한 변수
	//m_sight = 100.0f + rand() % 50;
}

CCharacter::~CCharacter(void)
{
}


void CCharacter::InitSprite( std::wstring imagePath )
{
	m_Sprite = NNSprite::Create(imagePath);
	

	// 부모 노드의 위치에 영향을 받기 때문에 
	// 부모인 캐릭터 노드의 위치를 설정하고 
	// 자식인 sprite는 (0, 0)으로 초기화한다.
	// 이것때문에 한시간 반을 헤맴 ㅠㅠ

	m_Sprite->SetPosition(0.0f, 0.0f);	
	AddChild(m_Sprite, 1);

	/*
	m_pShowHP = NNLabel::Create(L"HP", L"맑은 고딕", 10.f);
	m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY()+10.f);
	AddChild(m_pShowHP, 20);
	*/
	m_pShowHP = NNSpriteAtlas::Create(L"wugargar/HPbar.png");
	m_pShowHP->SetCutSize(0,0,50.f,5.f);
	m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY()+10.f);
	AddChild(m_pShowHP, 20);

}

// 기지주변에서 캐릭터 랜덤 생성
void CCharacter::SetRandomPositionAroundBase()
{
	NNPoint baseLocation;

	switch (m_Identity)
	{
	case Zombie:
		baseLocation = CPlayScene::GetInstance()->GetMapCreator()->GetZombieBase()->GetPosition();
		baseLocation.SetX(baseLocation.GetX()+TILE_SIZE_X);
		baseLocation.SetY(baseLocation.GetY()+TILE_SIZE_Y);
		break;
	case Police:
		baseLocation = CPlayScene::GetInstance()->GetMapCreator()->GetPoliceBase()->GetPosition();
		baseLocation.SetX(baseLocation.GetX()-TILE_SIZE_X);
		break;
	default:
		break;
	}

	int random_location_x = rand() % TILE_SIZE_X;
	int random_location_y = rand() % TILE_SIZE_Y;

	SetPosition((baseLocation.GetX()+random_location_x),(baseLocation.GetY()+random_location_y));
}


void CCharacter::Render()
{
	NNObject::Render();
}

void CCharacter::Update( float dTime )
{
	clock_t currentTime = clock();

	UpdateHPBar();	
	DetermineAttackTarget();

	//현재 얼어있는 상태라면 이동/공격이 불가
	if(m_Freeze) {
		CheckMeltingTime(currentTime);
	} else {
		//AttackTarget을 설정하고 Attack이 가능하면(사정거리 체크)
		//공격하고 그렇지 않으면 Attack Target에게 접근
		if(TargetInRange()) {
			if( CheckAttackSpeed(currentTime) ) { 
				Attack(currentTime);				
			}
		} else {
			GoToAttackTarget(dTime);
		}
	}
}

void CCharacter::UpdateHPBar( void )
{
	float HP = m_HealthPoint;
	if( HP/m_HPRatioPer100 >= 70 ) {// HP 상태에 따라 파란색, 노란색, 빨간색으로 표시
		m_pShowHP->SetCutSize(0,0,HP/2,5.f);
		m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
	} else if( HP/m_HPRatioPer100 < 70 && HP/m_HPRatioPer100 >= 30){
		m_pShowHP->SetCutSize(0,21,HP/2,26.f);
		m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY()-21.f);
	} else {
		m_pShowHP->SetCutSize(0,35,HP/2,40.f);
		m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY()-35.f);
	}
}


/*
함수명 : DetermineAttackTarget
사용법 : 이 객체의 attack_target을 설정하는 함수로 사용하면 된다.
이후에는 GoAttackTarget같은 함수를 사용하면 될 듯
주요 로직 : 싱글톤으로 선언한 Scene에 있는 모든 Police배열을 돌면서 NNPoint의 함수를 이용해
거리를 측정하고 가장 가까운 거리로 갱신하여 해당하는 idx를 가진 타겟을 반환한다.

최초 수정일 : 2013/11/03
최종 수정일 : 2013/11/14

ISSUE : 1차 통합. switch문의 반복되는 For문을 하나로 줄일 방법을 찾아야 됨.
수정 요망.

11/14 : Enemy가 존재하지 않을 때(NULL) attackTarget을 상대의 Base로 설정하도록 변경
*/
void  CCharacter::DetermineAttackTarget()
{
	float return_distnace = 1000000.0f;
	float next_distance;
	CZombie *tmp_closer_target_zombie = NULL;
	CPolice *tmp_closer_target_police = NULL;
	CCharacter *return_target = NULL;



	switch(this->GetIdentity())
	{
	case Zombie:
		for(const auto& enemy : CPlayScene::GetInstance()->GetPoliceList())
		{
			next_distance = this->GetPosition().GetDistance(enemy->GetPosition());
			if(return_distnace > next_distance)
			{
				return_distnace = next_distance;
				m_AttackTarget = enemy;
			}
		}
// 		if(m_AttackTarget == NULL)
// 			m_AttackTarget = CPlayScene::GetInstance()->GetMapCreator()->GetPoliceBase();
		break;

	case Police:
		for(const auto& enemy : CPlayScene::GetInstance()->GetZombieList())
		{
			next_distance= this->GetPosition().GetDistance(enemy->GetPosition());
			if(return_distnace > next_distance)
			{
			 	return_distnace = next_distance;
			 	m_AttackTarget = enemy;
			}
		}
// 		if(m_AttackTarget == NULL)
// 			m_AttackTarget = CPlayScene::GetInstance()->GetMapCreator()->GetZombieBase();
 		break;
	default:
		break;
	}
}


void CCharacter::Attack( clock_t currentTime )
{
	// When character has freezing attack
	if (m_FreezingAttack) {
		m_AttackTarget->SetFreeze(true);
		m_AttackTarget->SetBeginFreezingTime(currentTime);
		m_AttackTarget->SetTotalFreezingTime(m_FreezingAttackDuration);
	}

	
	//splash속성이 true인 몬스터면 splash어택
	if(m_SplashAttack) {
		SplashAttack(m_AttackTarget->GetPosition());
	} else { // 아니면 normal attack
		NormalAttack(m_AttackTarget);
	}	

	// 자폭 공격 캐릭터일 경우 hp를 0으로..
	if (m_SuicideBomber) {
		m_HealthPoint = 0.0f;
	}

	// set the last attack time
	m_LastAttackTime = currentTime;
}

// 일반 공격, 나의 공격력과 적의 방어력 차이 만큼을 적 HP에서 빼준다.
void CCharacter::NormalAttack( CCharacter* target )
{
	int damage = m_AttackPower - target->GetDefensivePower();
	float targetHP = target->GetHP(); 
	target->SetHP(targetHP-damage) ;
}


 /*
 정인호. 11/20
 광역 공격 처리. 현재 로직은 PlayScene의 모든 Enemy를 리스트로 돌면서
 지정된 SplashRange내부에 있는 적들은 모두 데미지를 받도록 처리함
 */
void CCharacter::SplashAttack( NNPoint splashPoint )
{
// 	for (const auto& enemy : (*enemyList) {		 
// 		 if(this->m_SplashAttackRange >= splashPoint.GetDistance(enemy->GetPosition())) {
// 			 NormalAttack(enemy);
// 		 }
// 	}
	
	 switch (m_Identity)
	 {
	 case Zombie:
		 for (const auto& enemy : CPlayScene::GetInstance()->GetPoliceList()) {		 
			 if(this->m_SplashAttackRange >= splashPoint.GetDistance(enemy->GetPosition())) {
				 NormalAttack(enemy);
			 }
		 }
		 break;
	 case Police:
		 for (const auto& enemy : CPlayScene::GetInstance()->GetZombieList()) {
			 if(this->m_SplashAttackRange >= splashPoint.GetDistance(enemy->GetPosition())) {
				 NormalAttack(enemy);
			 }
		 }
		 break;
	 default:
		 break;

	 }
}


/*
정인호. 11/14
Attack_target과의 거리를 계산하여 그쪽 방향으로 접근하도록 함.
Issue : 기존에 존재하는 MakeCharacterWalk와 어떤식으로 연계될지
*/
void CCharacter::GoToAttackTarget(float dTime)
{
	float gap_x = m_AttackTarget->GetPositionX() - m_Position.GetX();
	float gap_y = m_AttackTarget->GetPositionY() - m_Position.GetY();
	float t_x = (gap_x) / (gap_x+gap_y);
	float t_y = (gap_y) / (gap_x+gap_y);


	float distance_attacktarget;
	distance_attacktarget = this->GetPosition().GetDistance(m_AttackTarget->GetPosition());
	//Character가 안겹치게 하기 위한 연출을 위한 코드
	
	/*if(distance_attacktarget > m_sight)
	{
		MakeCharacterWalk(dTime);
		return ;
	}*/
	
	if(this->GetPositionX() < m_AttackTarget->GetPositionX())
		this->SetPosition(this->m_Position - NNPoint( -(m_MovingSpeed*t_x),-( m_MovingSpeed*t_y) )*dTime);
	else
		this->SetPosition(this->m_Position - NNPoint( (m_MovingSpeed*t_x),( m_MovingSpeed*t_y) )*dTime);

	//switch (m_Identity)
	//{
	//case Zombie:
	//	this->SetPosition(this->m_Position - NNPoint( -(m_MovingSpeed*t_x),-( m_MovingSpeed*t_y) )*dTime);
	//	break;
	//case Police:
	//	this->SetPosition(this->m_Position - NNPoint( (m_MovingSpeed*t_x),( m_MovingSpeed*t_y) )*dTime);
	//	break;
	//default:
	//	break;
	//}
	//

	
}





/*
11.21 정인호
얼게 된 시간, 현재 시간과 얼어있는 상태를 체크하여 현재 상태가 
아직도 냉동상태인지 해동상태인지 체크하고 반영.
*/
void CCharacter::CheckMeltingTime( clock_t currentTime )
{
	if( (currentTime - m_BeginFreezingTIme) >= m_TotalFreezingTime)	{
		m_Freeze = false;		
	}


#ifdef _DEBUG
	if( (currentTime - m_BeginFreezingTIme) >= m_TotalFreezingTime) {
		printf_s("UNICE\n");
	}
	if ( currentTime % 1000 == 0) {
		printf_s("ICETIME : %d, NOWTIME : %d\n", m_BeginFreezingTIme, currentTime);
	}	
#endif

}


void CCharacter::MakeCharacterWalk(float dTime)
{
	switch (m_Identity)
	{
	case Zombie:
		this->SetPosition(this->GetPosition() + NNPoint( (this->GetMovingSpeed()), 0.0f) * dTime);
		break;
	case Police:
		this->SetPosition(this->GetPosition() - NNPoint( (this->GetMovingSpeed()), 0.0f) * dTime);
		break;
	default:
		break;
	}

}
