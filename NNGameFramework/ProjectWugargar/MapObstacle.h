#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "Zombie.h"
#include "Character.h"
class CMapObstacle :
	public NNObject
{
public:
	CMapObstacle(void);
	virtual ~CMapObstacle(void);

public:
	virtual void Render();
	virtual void Update( float dTime );
	NNCREATE_FUNC(CMapObstacle);
	void Boom(CCharacter* boom_target);
	bool IsCrash( CCharacter *crash_check_character);
	NNSprite* GetSprite(){return m_pObstacle_sprite;}
	void InitStatus(); // virtual 로 하면 에러남.
	void InitSprite(std::wstring imagePath);
	bool CheckClickArea();

public:
	bool		is_boom;

private:
	NNPoint RandomMapPosition();

	
	


	

protected:
	NNSprite*	m_pObstacle_sprite;
	int			m_obstacle_damage;
	float		m_boom_range;
	
};

