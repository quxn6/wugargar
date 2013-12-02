#include "PoorZombie.h"

CPoorZombie::CPoorZombie(void)
{
	initStatus();
}


CPoorZombie::~CPoorZombie(void)
{

}


void CPoorZombie::initStatus( void )
{
	m_zombieType = POOR_ZOMBIE;
	m_HealthPoint = 100;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 8;
	m_DefensivePower = 2;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = false;

	ApplyZombieLevel();
}


void CPoorZombie::Render()
{
	NNObject::Render();
}

void CPoorZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
