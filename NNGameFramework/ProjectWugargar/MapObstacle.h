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
	void InitStatus(); // virtual 로 하면 에러남.
	void InitSprite(std::wstring imagePath);
	NNPoint RandomMapPosition();

protected:
	NNSprite*	m_pObstacle_sprite;
	int			m_obstacle_damage;
};

