#include "IceZombie.h"


CIceZombie::CIceZombie(void)
{
	initStatus();
}


CIceZombie::~CIceZombie(void)
{
}

void CIceZombie::initStatus( void )
{
	m_zombieType = ICE_ZOMBIE;
	m_HealthPoint = 100;
	m_HPRatioPer100 = m_HealthPoint/100.f;
	m_MovingSpeed = 30.0f;
	m_AttackPower = 5;
	m_DefensivePower = 1;
	m_AttackRange = 100.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = false;
	m_FreezingAttackDuration = 5000;
	m_FreezingAttack = true;

	ApplyZombieLevel();
}


void CIceZombie::Render()
{
	NNObject::Render();
}

void CIceZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}