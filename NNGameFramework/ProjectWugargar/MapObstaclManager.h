#pragma once
#include <list>
#include "MapObstacle.h"
class MapObstaclManager
{
public:
	MapObstaclManager(void);
	~MapObstaclManager(void);

protected:
	std::list<CMapObstacle*> m_pList_mapObstacle;


};

