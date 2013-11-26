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
	float x = (obstacle_position.GetX() + m_pObstacle_sprite->GetImageWidth());
	float y = (obstacle_position.GetY() + m_pObstacle_sprite->GetImageHeight());


	for (const auto& child : CPlayScene::GetInstance()->GetZombieList())
	{
		if(obstacle_position.GetX()+ m_pObstacle_sprite->GetImageWidth()<=(child->GetPositionX()) && 
			obstacle_position.GetX()>=(child->GetPositionX()) &&
			obstacle_position.GetY()+m_pObstacle_sprite->GetImageHeight()<=(child->GetPositionY()+10) && 
			obstacle_position.GetY()>=(child->GetPositionY()))
		{
			printf_s("Boom!\n");
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
	AddChild(m_pObstacle_sprite);

}



NNPoint CMapObstacle::RandomMapPosition()
{
	return (NNPoint(static_cast<float>(rand() % (MAP_SIZE_X-1) * TILE_SIZE_X), static_cast<float>(270 + rand()%(MAP_SIZE_Y-1)*TILE_SIZE_Y)));
}

//Area내부가 클릭되었는지 체크
bool CMapObstacle::CheckClickArea()
{
	NNPoint cursorPosition = NNInputSystem::GetInstance()->GetMousePosition();

	bool isInXCoordRange = (m_pObstacle_sprite->GetPositionX() < cursorPosition.GetX()) && ( ( m_pObstacle_sprite->GetPositionX() + m_pObstacle_sprite->GetImageWidth() ) > cursorPosition.GetX() );
	bool isInYCoordRange = (m_pObstacle_sprite->GetPositionY() < cursorPosition.GetY()) && ( ( m_pObstacle_sprite->GetPositionY() + m_pObstacle_sprite->GetImageHeight() ) > cursorPosition.GetY() );

	if ( !(isInXCoordRange && isInYCoordRange))
	{
		return false;
	}
	else
	{
		if (NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_UP )
			return true;
	}
	
	return false;

}
