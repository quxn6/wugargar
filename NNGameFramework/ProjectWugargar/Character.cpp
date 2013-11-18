#include "Character.h"
#include "PlayScene.h"


CCharacter::CCharacter(void)
{
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
	DetermineAttackTarget();

	if(IsAttack())
		Attack();
	else
		GoToAttackTarget(dTime);
}

void CCharacter::Attack()
{
	CCharacter* target = this->m_AttackTarget;

	if(this->m_AttackTarget){
		int damage = this->GetAttackPower() - target->GetDefensivePower();
		target->SetHP(target->GetHP()-damage) ;
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
	
	switch (m_Identity)
	{
	case Zombie:
		this->SetPosition(this->m_Position - NNPoint( -(m_MovingSpeed*t_x),-( m_MovingSpeed*t_y) )*dTime);
		break;
	case Police:
		this->SetPosition(this->m_Position - NNPoint( (m_MovingSpeed*t_x),( m_MovingSpeed*t_y) )*dTime);
		break;
	default:
		break;
	}
	
	
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
