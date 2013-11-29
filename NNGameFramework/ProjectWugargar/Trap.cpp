#include "Trap.h"


CTrap::CTrap(void)
{
	InitSprite(L"wugargar/trap.png");
	InitStatus();
}


CTrap::~CTrap(void)
{
}

void CTrap::Render()
{
	NNObject::Render();
}

void CTrap::Update( float dTime )
{
	CMapObstacle::Update(dTime);
}

void CTrap::Boom( CZombie* boom_target )
{
	CMapObstacle::Boom(boom_target);
}

void CTrap::InitStatus()
{
	m_boom_range = 0;
	m_obstacle_damage = 50;

}