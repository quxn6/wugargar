#pragma once
#include "NNObject.h"
#include "NNPoint.h"
#include "NNSprite.h"
#include "Character.h"

class CDeadPolice :	public CCharacter
{
public:
	CDeadPolice(void);
	~CDeadPolice(void);

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CDeadPolice);	
	void SetDeadPosition(NNPoint DeadPosition);
	NNPoint GetDeadPosition() { return DeadPoliceSprite->GetPosition();}
	
private:
	NNSprite* DeadPoliceSprite;

};

