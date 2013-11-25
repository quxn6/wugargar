#include "MapObstaclManager.h"
#include "Mine.h"
#include "Trap.h"


MapObstaclManager::MapObstaclManager(void)
{
	m_obstacle_start_time = clock_t();
}


MapObstaclManager::~MapObstaclManager(void)
{
}

void MapObstaclManager::Update( float dTime )
{

	if(m_obstacle_start_time/CLOCKS_PER_SEC - clock_t()/CLOCKS_PER_SEC <= REGEN_TIME)
	{
		CMapObstacle *tmpMapObstacle = nullptr;
		if(rand()%2)
			tmpMapObstacle = CMine::Create();
		else
			tmpMapObstacle = CTrap::Create();

		m_pList_mapObstacle.push_back(tmpMapObstacle);
		AddChild(tmpMapObstacle,10);

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
