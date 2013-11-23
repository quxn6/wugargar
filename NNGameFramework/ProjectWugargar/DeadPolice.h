#pragma once
#include "nnobject.h"
#include "NNSprite.h"
class CDeadPolice :
	public NNObject
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

