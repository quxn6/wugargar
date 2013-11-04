#pragma once
#include "Police.h"
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

	//CPolice *GetCloserEnemy();

private:
	float m_infectingAccuracyRate;

public:
	float GetInfectingAccuracyRate() {return m_infectingAccuracyRate;};

};

