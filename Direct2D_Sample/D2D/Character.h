#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"
class CCharacter : public NNObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);



public:
	void Render();
	void Update( float dTime );


	NNCREATE_FUNC(CCharacter);
};

