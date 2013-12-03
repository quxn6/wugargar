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
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 8;
	m_DefensivePower = 2;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
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
