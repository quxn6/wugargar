#include "MuscleZombie.h"


CMuscleZombie::CMuscleZombie(void)
{
	initStatus();
}


CMuscleZombie::~CMuscleZombie(void)
{
}

void CMuscleZombie::initStatus( void )
{
	m_Type = MUSCLE_ZOMBIE;
	m_HealthPoint = 300;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 5;
	m_DefensivePower = 5;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_is_splash = false;

	ApplyZombieLevel();
}


void CMuscleZombie::Render()
{
	NNObject::Render();
}

void CMuscleZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
