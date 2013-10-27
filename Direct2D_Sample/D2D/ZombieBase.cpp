#include "ZombieBase.h"


CZombieBase::CZombieBase(void)
{
	m_ZombieBase = NNSprite::Create(L"wugargar/zombie_base.png");
	m_ZombieBase->SetPosition(800.0f, 300.0f);
	AddChild( m_ZombieBase );
}


CZombieBase::~CZombieBase(void)
{

}


void CZombieBase::Render()
{
	NNObject::Render();
}

void CZombieBase::Update( float dTime )
{
	
}

