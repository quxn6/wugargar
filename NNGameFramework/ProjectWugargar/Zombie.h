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
	float GetInfectingAccuracyRate() {return m_infectingAccuracyRate;};
	void SetInfectingAccuracyRate(float IAR) {m_infectingAccuracyRate = IAR;};	

private:
	float m_infectingAccuracyRate;
};

