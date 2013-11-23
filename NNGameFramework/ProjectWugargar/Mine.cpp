#include "Mine.h"


CMine::CMine(void)
{
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
