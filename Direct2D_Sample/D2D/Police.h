#pragma once
#include "character.h"

class CPolice : public CCharacter
{
public:
	CPolice(void);
	virtual ~CPolice(void);

public:
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CPolice);

public:
	bool IsInfected() {return m_infected;};
	float GetInfectingEvationRate() {return m_infectingEvationRate;};

private:
	bool m_infected;
	float m_infectingEvationRate;

};


