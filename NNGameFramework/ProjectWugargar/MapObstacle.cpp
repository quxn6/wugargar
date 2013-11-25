#include "MapObstacle.h"
#include "GameConfig.h"


CMapObstacle::CMapObstacle(void)
{
}


CMapObstacle::~CMapObstacle(void)
{
}

void CMapObstacle::Render()
{
	NNObject::Render();
}

void CMapObstacle::Update( float dTime )
{

}

void CMapObstacle::Boom( CZombie* boom_target )
{

}

void CMapObstacle::InitSprite(std::wstring imagePath )
{
	m_pObstacle_sprite = NNSprite::Create(imagePath);

	m_pObstacle_sprite->SetPosition(RandomMapPosition());
	AddChild(m_pObstacle_sprite, 1);

}



NNPoint CMapObstacle::RandomMapPosition()
{
	return (NNPoint(rand() % (MAP_SIZE_X-1) * TILE_SIZE_X, rand()%(MAP_SIZE_Y-1)*TILE_SIZE_Y));
}
