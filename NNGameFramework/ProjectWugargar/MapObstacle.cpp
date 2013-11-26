#include "MapObstacle.h"
#include "GameConfig.h"
#include "PlayScene.h"
#include "NNInputSystem.h"
#include "NNPoint.h"

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
	NNPoint obstacle_position = m_pObstacle_sprite->GetPosition();

	for (const auto& child : CPlayScene::GetInstance()->GetZombieList())
	{
		if(obstacle_position.GetX()<=(child->GetPositionX()+10) && 
			obstacle_position.GetX()>=(child->GetPositionX()-10) &&
			obstacle_position.GetY()<=(child->GetPositionY()+10) && 
			obstacle_position.GetY()>=(child->GetPositionY()-10))
		{
			Boom(child);
			break;
		}


	}
	
}

void CMapObstacle::Boom( CCharacter* boom_target )
{
	boom_target->SetHP(boom_target->GetHP() - m_obstacle_damage);

}

void CMapObstacle::InitSprite(std::wstring imagePath )
{
	m_pObstacle_sprite = NNSprite::Create(imagePath);

	m_pObstacle_sprite->SetPosition(RandomMapPosition());
	AddChild(m_pObstacle_sprite, 10);

}



NNPoint CMapObstacle::RandomMapPosition()
{
	return (NNPoint(rand() % (MAP_SIZE_X-1) * TILE_SIZE_X, 270 + rand()%(MAP_SIZE_Y-1)*TILE_SIZE_Y));
}

//юс╫ц
bool CMapObstacle::CheckClickArea()
{
	if(NNInputSystem::GetInstance()->GetKeyState(VK_BACK) == KEY_DOWN)
	{
		return true;
	}

	return false;
}
