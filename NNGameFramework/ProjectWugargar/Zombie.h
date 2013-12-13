#pragma once
#include "Character.h"

class CZombie : public CCharacter
{
public:
	CZombie(void);
	virtual ~CZombie(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CZombie);

public:
	int		GetCreateCost() {return m_CreateCost;};
	void	SetCreateCost(int cost) {m_CreateCost = cost;};

	void	ApplyZombieLevel();

	void	PlayCreationSound();

protected:
	int			m_CreateCost;
	ZombieType	m_zombieType;
	NNSprite*	m_Shadow;
};

