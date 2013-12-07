#pragma once
#include "mapobstacle.h"
class CTrap :
	public CMapObstacle
{
public:
	CTrap(void);
	~CTrap(void);

public:

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CTrap);
	void Boom(CZombie* boom_target);
	void InitStatus();
};

