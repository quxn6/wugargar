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

		m_pList_mapObstacle.push_back(tmpMapObstacle);
		AddChild(tmpMapObstacle,10);
		m_obstacle_start_time = clock();
	}
	
	for(const auto& child : m_pList_mapObstacle)
	{
		if(child->CheckClickArea())
		{
			m_pList_mapObstacle.remove(child);
			RemoveChild(child);
		}
	}
	

}
