#pragma once
#include "character.h"
class CBase : public CCharacter
{
public:
	CBase(void);	
	virtual ~CBase(void);


public:
	void Render();
	void Update( float dTime );
	
	NNCREATE_FUNC(CBase);

protected :
	virtual void initStatus(void);	
};

