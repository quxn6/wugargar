#include "Police.h"
#include "Zombie.h"
#include "Wugargar.h"


CPolice::CPolice(void)
{
}


CPolice::~CPolice(void)
{
}

void CPolice::Render()
{

}

void CPolice::Update( float dTime )
{

}



/*
함수명 : GetCloseEnemy
반환값 : 해당 객체(경찰)로부터 가장 가까운 객체(좀비)을 반환
사용법 : 이 객체의 attack_target을 설정하는 함수로 사용하면 된다.
이후에는 GoAttackTarget같은 함수를 사용하면 될 듯
주요 로직 : 싱글톤으로 선언한 Scene에 있는 모든 Police배열을 돌면서 NNPoint의 함수를 이용해
거리를 측정하고 가장 가까운 거리로 갱신하여 해당하는 idx를 가진 타겟을 반환한다.

최초 수정일 : 2013/11/03
최종 수정일 : 2013/11/03
*/
CCharacter * CPolice::GetCloseEnemy()
{


	float return_distnace = 1000000.0f;
	float next_distance;
	CZombie *tmp_closer_target = NULL;
	NNPoint* tmppoint = nullptr;

	for(const auto& child : CWugargar::GetInstance()->GetZombieList())
	{
	//	next_distance = tmppoint->GetDistanceTwoPoint(this->GetPositionX(), this->GetPositionY(), child->GetPositionX(), child->GetPositionY());
// 		if(return_distnace > next_distance)
// 		{
// 			return_distnace = next_distance;
// 			tmp_closer_target = child;
// 		}

	}

	return tmp_closer_target;

}