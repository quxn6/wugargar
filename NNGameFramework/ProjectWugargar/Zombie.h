#pragma once
#include "Character.h"
#include "CharacterConfig.h"

class NNSprite;
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

	virtual void initStatus( CharacterInfo *zombieInfo, int zombie_type_idx );

protected:
	int			m_CreateCost;
	ZombieType	m_zombieType;
	NNSprite*	m_Shadow;

	void InitAttackEffect();
};

