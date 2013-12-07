#include "MapObstacle.h"
#include "GameConfig.h"
#include "PlayScene.h"
#include "NNInputSystem.h"
#include "NNPoint.h"

#define BATTALE_LINE 100

/*
MapObstacle은 화면에 랜덤하게 뿌려지는 지뢰, 덫 의미
*/

CMapObstacle::CMapObstacle(void)
{
	is_boom = false;
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

	//Zombie리스트를 돌면서 좀비가 Obstacle에 닿았는지를 체크
	for (const auto& child : CPlayScene::GetInstance()->GetZombieList())
	{
		if(child != CPlayScene::GetInstance()->GetMapCreator()->GetZombieBase())
		if(IsCrash(child))
		{
			printf_s("Boom!\n");
			Boom(child);
			break;
		}


	}
	
}

//좀비가 obstacle에 닿았으면 HP를 깎고 폭파상태를 true로 (이 함수는 오버로딩됨)
void CMapObstacle::Boom( CCharacter* boom_target )
{
	boom_target->SetHP(boom_target->GetHP() - m_obstacle_damage);
	is_boom = true;
}

void CMapObstacle::InitSprite(std::wstring imagePath )
{
	m_pObstacle_sprite = NNSprite::Create(imagePath);

	m_pObstacle_sprite->SetPosition(RandomMapPosition());
	AddChild(m_pObstacle_sprite, 0);

}


//맵 상 랜덤하게 뿌려지는 부분. 가능하면 전투가 자주 이뤄지는 구역(BattleLine)에 뿌려지도록 수정할 예정
NNPoint CMapObstacle::RandomMapPosition()
{
	return (NNPoint(static_cast<float>(rand() % (MAP_SIZE_X-1) * TILE_SIZE_X), static_cast<float>(FIRST_Y_COORDINATE_OF_MAPTILE + rand()%(MAP_SIZE_Y-1)*TILE_SIZE_Y)));
}

//Area내부가 클릭되었는지 체크. UIBUTTION클래스 함수 참조함
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

//충돌 체크 함수. 현재는 임의로 둘 사이의 거리가 10정도로 가까워질때 반응하도록 되어있음.
//좀 더 정밀해지도록 로직 수정이 필요할 듯.
bool CMapObstacle::IsCrash( CCharacter *crash_check_character)
{
	float distance_attacktarget;
	distance_attacktarget = m_pObstacle_sprite->GetPosition().GetDistance(crash_check_character->GetPosition());

	if(distance_attacktarget <= 10/*this->GetSprite()->GetImageWidth()*/)
		return true;
	
	return false;

	/*if(((thi->GetCenterX() + thi->GetImageWidth()/2) > (crash_check_sprite->GetCenterX() - crash_check_sprite->GetImageWidth()/2)) &&
		(((thi->GetCenterX() + thi->GetImageWidth()/2) <= (crash_check_sprite->GetCenterX() + crash_check_sprite->GetImageWidth()/2)) &&
		((thi->GetCenterY() <= (crash_check_sprite->GetCenterY() + crash_check_sprite->GetImageHeight()/2)) &&
		((thi->GetCenterX() > (crash_check_sprite->GetCenterY() - crash_check_sprite->GetImageHeight()/2)) ))))
		return true;

	return false;*/
}
