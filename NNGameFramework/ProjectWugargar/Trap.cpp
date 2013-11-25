#include "Trap.h"


CTrap::CTrap(void)
{
	InitSprite(L"wugargar/trap.png");
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

}

void CTrap::InitStatus()
{

}