#include "Character.h"
#include "Wugargar.h"

CCharacter::CCharacter(void)
{
}


CCharacter::~CCharacter(void)
{
}

void CCharacter::Render()
{

}

void CCharacter::Update( float dTime )
{

}


/*
함수명 : GetCloseEnemy
반환값 : 해당 객체(경찰/좀비)로부터 가장 가까운 객체(경찰/좀비)을 반환
사용법 : 이 객체의 attack_target을 설정하는 함수로 사용하면 된다.
이후에는 GoAttackTarget같은 함수를 사용하면 될 듯
주요 로직 : 싱글톤으로 선언한 Scene에 있는 모든 Police배열을 돌면서 NNPoint의 함수를 이용해
거리를 측정하고 가장 가까운 거리로 갱신하여 해당하는 idx를 가진 타겟을 반환한다.

최초 수정일 : 2013/11/03
최종 수정일 : 2013/11/04

ISSUE : 1차 통합. switch문의 반복되는 For문을 하나로 줄일 방법을 찾아야 됨.
*/
CCharacter * CCharacter::GetCloseEnemy()
{


	float return_distnace = 1000000.0f;
	float next_distance;
	CZombie *tmp_closer_target_zombie = NULL;
	CPolice *tmp_closer_target_police = NULL;
	CCharacter *return_target = NULL;

	switch(this->GetIdentity())
	{
	case Zombie:
		for(const auto& child : CWugargar::GetInstance()->GetPoliceList())
		{
				next_distance = this->GetPosition().GetDistance(child->GetPosition());
			 		if(return_distnace > next_distance)
			 		{
			 			return_distnace = next_distance;
			 			tmp_closer_target_police = child;
			 		}

				
		}
		return_target = tmp_closer_target_police;
		break;

	case Police:
		for(const auto& child : CWugargar::GetInstance()->GetZombieList())
		{
				next_distance= this->GetPosition().GetDistance(child->GetPosition());
			 		if(return_distnace > next_distance)
			 		{
			 			return_distnace = next_distance;
			 			tmp_closer_target_zombie = child;
			 		}

		}
		return_target = tmp_closer_target_zombie;
		break;
	default:
		break;
	}

	return return_target;

}
