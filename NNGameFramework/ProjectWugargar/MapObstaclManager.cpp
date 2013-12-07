#include "MapObstaclManager.h"
#include "Mine.h"
#include "Trap.h"



/*
MapObstacle들을 관리하고 소유하는 클래스
PlayScene은 이 클래스를 하나 멤버 변수로 소유하며
이 클래스는 MapObstacle들을 LinkedList로 소유하고 관리한다.
REGEN_TIME이 지날 때마다 MapObstacle을 생성,
생성된 MapObstacle이 클릭시 지워지는 부분을 담당한다.
*/

MapObstaclManager::MapObstaclManager(void)
{
	m_obstacle_start_time = clock(); //시간측정을 위한 변수 설정
}


MapObstaclManager::~MapObstaclManager(void)
{
}



void MapObstaclManager::Update( float dTime )
{
	
	//REGEN_TIME마다 Obstacle 생성
	if(clock()/CLOCKS_PER_SEC - m_obstacle_start_time/CLOCKS_PER_SEC  > REGEN_TIME)
	{
		CMapObstacle *tmpMapObstacle = nullptr;

		//랜덤하게 지뢰 또는 덫을 생성한다.
		if(rand()%2)
			tmpMapObstacle = CMine::Create();
		else
			tmpMapObstacle = CTrap::Create();

		//생성한 obstacle은 리스트에 넣어진다.
		printf_s("생성! %d %d\n", tmpMapObstacle->GetSprite()->GetPositionX(), tmpMapObstacle->GetPositionY());
		m_pList_mapObstacle.push_back(tmpMapObstacle);
		AddChild(tmpMapObstacle,10);
		m_obstacle_start_time = clock();
	}
	
	//Obstacle list를 매번 돌면서 Click여부를 확인한다.
	for(auto& iter = m_pList_mapObstacle.begin() ; iter != m_pList_mapObstacle.end() ; iter++ )
	{
		(*iter)->Update(dTime);
		//Obstacle의 Update함수가 저절로 동작하지 않아 임의로 넣은 코드

		//obstacle이 클릭되었거나 Zombie가 접근하여 폭파되었을 때 제거해준다.
		if((*iter)->CheckClickArea() || (*iter)->is_boom)
		{
			CMapObstacle *tmp_obstacle;
			tmp_obstacle = *iter;
			if(!(*iter)->is_boom)
				printf_s("Obstacle Click Check\n");

			m_pList_mapObstacle.erase(iter);
			RemoveChild(tmp_obstacle, true);
			break; //오류가 났었던 부분
		}


	}
}
