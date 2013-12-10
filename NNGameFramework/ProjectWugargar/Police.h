#pragma once
#include "character.h"
#include "NNXML.h"
#include "GameConfig.h"
#include "CharacterConfig.h"



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
	void SetInfectedStatus(bool infected) {m_infected = infected;};

	virtual void initStatus( PoliceInfo *policeInfo, int police_type_idx );
protected:
	bool m_infected;
	PoliceType m_policeType;

	NNSprite* FrozenStatus;

};
