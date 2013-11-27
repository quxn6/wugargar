#include "VomitZombie.h"


CVomitZombie::CVomitZombie(void)
{
	initStatus();
}


CVomitZombie::~CVomitZombie(void)
{
}

void CVomitZombie::initStatus( void )
{
	m_Type = VOMIT_ZOMBIE;
	m_HealthPoint = 100;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 8;
	m_DefensivePower = 2;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 3;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_is_splash = false;

	ApplyZombieLevel();
}


void CVomitZombie::Render()
{
	NNObject::Render();
}

void CVomitZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
