#pragma once
#include "character.h"
class CPolice :
	public CCharacter
{
public:
	CPolice(void);
	~CPolice(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CPolice);
};

