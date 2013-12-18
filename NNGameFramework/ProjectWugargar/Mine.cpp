#include "Mine.h"
#include "PlayScene.h"


CMine::CMine(void)
{
	InitSprite(L"wugargar/mine.png");
	InitStatus();
}


CMine::~CMine(void)
{
}

void CMine::Render()
{
	NNObject::Render();
}

void CMine::Update( float dTime )
{
	CMapObstacle::Update(dTime);
}

void CMine::Boom( CZombie* boom_target )
{
	CMapObstacle::Boom(boom_target);

	//지뢰는 덫과 달리 폭파시 주위의 적에게 스플래쉬 데미지를 준다.
	for (const auto& child : *(CPlayScene::GetInstance()->GetZombieList()))
	{
		float distance_attacktarget;
		distance_attacktarget = boom_target->GetPosition().GetDistance(child->GetPosition());

		if(this->m_boom_range >= distance_attacktarget)
			child->SetHP(child->GetHP()-m_obstacle_damage);
	}
}

//폭파 반경과 데미지 설정
void CMine::InitStatus()
{
	m_boom_range = 20.0f;
	m_obstacle_damage = 100;
}
