#pragma once
#include "mapobstacle.h"
class CMine :
	public CMapObstacle
{
public:
	CMine(void);
	~CMine(void);

public:

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CMine);
	virtual void Boom(CZombie* boom_target);
	void InitStatus();



};

