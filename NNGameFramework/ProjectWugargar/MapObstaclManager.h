#pragma once
#include <list>
#include "MapObstacle.h"
#define REGEN_TIME 3

class MapObstaclManager : 
	public NNObject
{
public:
	MapObstaclManager(void);
	~MapObstaclManager(void);

	void Update(float dTime);

	NNCREATE_FUNC(MapObstaclManager);
protected:
	std::list<CMapObstacle*> m_pList_mapObstacle;
	clock_t m_obstacle_start_time;
	//clock_t now_time;

};

