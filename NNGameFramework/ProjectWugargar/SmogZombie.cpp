#include "SmogZombie.h"


CSmogZombie::CSmogZombie(void)
{
	initStatus();
}


CSmogZombie::~CSmogZombie(void)
{
}

void CSmogZombie::initStatus( void )
{
	m_Type = SMOG_ZOMBIE;
	m_HealthPoint = 80;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 80.0f;
	m_AttackPower = 10;
	m_DefensivePower = 1;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 5;
	m_AttackSpeed = 3;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_is_splash = true;
	m_splash_range = 30.0f;

	ApplyZombieLevel();
}


void CSmogZombie::Render()
{
	NNObject::Render();
}

void CSmogZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
