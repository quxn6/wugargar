#include "Character.h"
#include "PlayScene.h"
#include <math.h>


CCharacter::CCharacter(void)
{	
	/* 적을 발견한 순간부터가 아닌 캐릭터가 만들어지고나서 부터의 시간으로 어택을 구현. 
	타겟이 사정거리 안으로 들어온 순간부터의 시간을 기준으로 하는 것이 맞지만, update 안에서 공격 관련 함수가 계속 갱신되는 특성 때문에
	생성자 안에서 m_CreateTime을 고정시키는 방법으로 우선 구현. ㅠㅠ
	*/
	SetCreateTime(clock()); 
	SetNowTime(clock());
	m_is_iceState = false;
	//sight는 철저하게 캐릭터가 안 겹치게 보이기 위한 연출을 위한 변수
	m_sight = 500.0f + rand() % 20;
}

CCharacter::~CCharacter(void)
{
}

void CCharacter::initStatus( void )
{

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
		for(const auto& child : CPlayScene::GetInstance()->GetPoliceList())
		{
			next_distance = this->GetPosition().GetDistance(child->GetPosition());
			 	if(return_distnace > next_distance)
			 	{
			 		return_distnace = next_distance;
			 		m_AttackTarget = child;
			 	}
		}
		if(m_AttackTarget == NULL)
			m_AttackTarget = CPlayScene::GetInstance()->GetMapCreator()->GetPoliceBase();
		break;

	case Police:
		for(const auto& child : CPlayScene::GetInstance()->GetZombieList())
		{
			next_distance= this->GetPosition().GetDistance(child->GetPosition());
			 	if(return_distnace > next_distance)
			 	{
			 		return_distnace = next_distance;
			 		m_AttackTarget = child;
			 	}
		}
		if(m_AttackTarget == NULL)
			m_AttackTarget = CPlayScene::GetInstance()->GetMapCreator()->GetZombieBase();
		break;
	default:
		break;
	}
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

	m_pShowHP = NNLabel::Create(L"HP", L"맑은 고딕", 10.f);
	m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY()+10.f);
	AddChild(m_pShowHP, 20);


}



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
	//AttackTarget을 설정하고 Attack이 가능하면(사정거리 체크)
	//공격하고 그렇지 않으면 Attack Target에게 접근

	
	ZeroMemory(temp_HP, 256);	
	swprintf_s(temp_HP, _countof(temp_HP), L"%d",	m_HealthPoint );
	m_pShowHP->SetString(temp_HP);
	m_pShowHP->SetPosition(m_Sprite->GetPositionX(), m_Sprite->GetPositionY()+10.f);
	
	int CheckTimeChange = GetNowTimeSEC();
	SetNowTime(clock());
	DetermineAttackTarget();
	CheckIceState();


	//현재 얼어있는 상태라면 이동/공격이 불가
	if(!m_is_iceState)
		if(IsAttack())
		{
			if((GetNowTimeSEC() - GetCreateTimeSEC()) % GetAttackSpeed() == 0 && CheckTimeChange != GetNowTimeSEC()) // 초단위로 시간이 변했는가도 함께 체크한다 (dTime이 너무 작아 int로 반환하는 Get~TimeSEC 함수는 1초 내에 같은값을 dTime마다 반환한다.)
				Attack();
		}
		else
			GoToAttackTarget(dTime);


}

 void CCharacter::Attack()
{
	CCharacter* target = this->m_AttackTarget;
	int damage;

	if(this->m_AttackTarget){
		damage = this->GetAttackPower() - target->GetDefensivePower();
		target->SetHP(target->GetHP()-damage) ;
	}

	//Splash속성이 true인 몬스터면 Splash어택
	if(this->m_is_splash)
		SplashAttack(damage);
		

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
	/*
	if(distance_attacktarget <= m_sight)
	{
		MakeCharacterWalk(dTime);
		return ;
	}
	*/
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
정인호. 11/14
현재 상황에서 AttackTarget이 공격 사정거리 안에 들어가있는지 체크.
공격이 가능하면 True, 가능하지 않으면(멀어서) False
*/
bool CCharacter::IsAttack()
{
	float distance_attacktarget;
	distance_attacktarget = this->GetPosition().GetDistance(m_AttackTarget->GetPosition());

	

	if(distance_attacktarget <= m_AttackRange)
		return true;
	else
		return false;
}

/*
정인호. 11/20
광역 공격 처리. 현재 로직은 PlayScene의 모든 Enemy를 리스트로 돌면서
지정된 SplashRange내부에 있는 적들은 모두 데미지를 받도록 처리함
*/
void CCharacter::SplashAttack(int damage)
{

	switch (m_Identity)
	{
	case Zombie:
		for (const auto& child : CPlayScene::GetInstance()->GetPoliceList())
		{
			float distance_attacktarget;
			distance_attacktarget = this->GetPosition().GetDistance(child->GetPosition());

			if(this->m_splash_range >= distance_attacktarget)
				child->SetHP(child->GetHP()-damage);
		}
		break;
	case Police:
		for (const auto& child : CPlayScene::GetInstance()->GetZombieList())
		{
			float distance_attacktarget;
			distance_attacktarget = this->GetPosition().GetDistance(child->GetPosition());

			if(this->m_splash_range >= distance_attacktarget)
				child->SetHP(child->GetHP()-damage);
		}
		break;
	case Base:
		break;
	default:
		break;
	
	}
}


/*
11.21 정인호
얼게 된 시간, 현재 시간과 얼어있는 상태를 체크하여 현재 상태가 
아직도 냉동상태인지 해동상태인지 체크하고 반영.
*/
void CCharacter::CheckIceState()
{
	if(!m_is_iceState)
		return ;

	SetIceNowTime(clock());
	printf_s("ICETIME : %d, NOWTIME : %d\n", m_iceStartTime/CLOCKS_PER_SEC, m_iceNowTime/CLOCKS_PER_SEC);


	if(m_iceNowTime/CLOCKS_PER_SEC - m_iceStartTime/CLOCKS_PER_SEC > ICE_TIME)
	{
		printf_s("UNICE\n");
		m_is_iceState = false;
	}

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
	case Base:
		break;
	default:
		break;
	}

}
