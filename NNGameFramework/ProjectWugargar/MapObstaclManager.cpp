#include "MapObstaclManager.h"
#include "Mine.h"
#include "Trap.h"


MapObstaclManager::MapObstaclManager(void)
{
	m_obstacle_start_time = clock();
}


MapObstaclManager::~MapObstaclManager(void)
{
}

void MapObstaclManager::Update( float dTime )
{
	
	if(clock()/CLOCKS_PER_SEC - m_obstacle_start_time/CLOCKS_PER_SEC  > REGEN_TIME)
	{
		CMapObstacle *tmpMapObstacle = nullptr;
		if(rand()%2)
			tmpMapObstacle = CMine::Create();
		else
			tmpMapObstacle = CTrap::Create();

		printf_s("»ý¼º! %d %d\n", tmpMapObstacle->GetSprite()->GetPositionX(), tmpMapObstacle->GetPositionY());
		m_pList_mapObstacle.push_back(tmpMapObstacle);
		AddChild(tmpMapObstacle,10);
		m_obstacle_start_time = clock();
	}
	
	for(auto& iter = m_pList_mapObstacle.begin() ; iter != m_pList_mapObstacle.end() ; iter++ )
	{
		if((*iter)->CheckClickArea())
		{
			CMapObstacle *tmp_obstacle;
			tmp_obstacle = *iter;
			printf_s("Obstacle Click Check\n");
			m_pList_mapObstacle.erase(iter);
			RemoveChild(tmp_obstacle, true);
		}
	}
	

}
