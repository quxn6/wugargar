#include "Mine.h"


CMine::CMine(void)
{
	m_pObstacle_sprite = NNSprite::Create("wugargar/mine.png");
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

}

void CMine::InitStatus()
{

}
