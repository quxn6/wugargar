#include "KamikazeZombie.h"


CKamikazeZombie::CKamikazeZombie(void)
{
	initStatus();
}


CKamikazeZombie::~CKamikazeZombie(void)
{
}

void CKamikazeZombie::initStatus( void )
{
	m_HealthPoint = 50;
	m_MovingSpeed = 50.0f;
	m_AttackPower = 50;
	m_DefensivePower = 3;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 3;
	m_AttackSpeed = 2;
	m_CreateCost = 100;
	m_Identity = Zombie;
}


void CKamikazeZombie::Render()
{
	NNObject::Render();
}

void CKamikazeZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}

void CKamikazeZombie::Attack()
{
	CCharacter::Attack();

	this->SetHP(0);

}
