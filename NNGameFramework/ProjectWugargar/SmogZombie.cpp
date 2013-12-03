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
	m_zombieType = SMOG_ZOMBIE;
	m_HealthPoint = 800;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 80.0f;
	m_AttackPower = 10;
	m_DefensivePower = 1;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 5;
	m_AttackSpeed = 3000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = true;
	m_SplashAttackRange = 100.0f;

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
