#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "Zombie.h"
class CMapObstacle :
	public NNObject
{
public:
	CMapObstacle(void);
	virtual ~CMapObstacle(void);

public:
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CMapObstacle);
	virtual void Boom(CZombie* boom_target);
	virtual void InitStatus();


private:
	NNSprite*	m_pObstacle_sprite;
	int			m_obstacle_damage;
};

