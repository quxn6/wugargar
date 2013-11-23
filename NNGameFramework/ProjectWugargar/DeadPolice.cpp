#include "DeadPolice.h"


CDeadPolice::CDeadPolice(void)
{
	DeadPoliceSprite = NNSprite::Create(L"wugargar/deadPodori.png");
}


CDeadPolice::~CDeadPolice(void)
{
}

void CDeadPolice::Render()
{
	NNObject::Render();
}

void CDeadPolice::Update( float dTime )
{
	NNObject::Update(dTime);
}

void CDeadPolice::SetDeadPosition( NNPoint DeadPosition )
{
	DeadPoliceSprite->SetPosition(DeadPosition);
	AddChild(DeadPoliceSprite);
}
