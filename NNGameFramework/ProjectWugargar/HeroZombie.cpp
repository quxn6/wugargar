#include "HeroZombie.h"
#include "NNAnimation.h"

CHeroZombie::CHeroZombie(void)
{
	initStatus();
}


CHeroZombie::~CHeroZombie(void)
{
}

void CHeroZombie::initStatus( void )
{
	m_zombieType = HERO_ZOMBIE_SM9;

	m_HealthPoint = 1000;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 100;
	m_DefensivePower = 8;
	m_AttackRange = 50.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 500;
	m_CreateCost = 0;
	m_Identity = Zombie;
	m_SplashAttack = false;
}


void CHeroZombie::Render()
{
	NNObject::Render();
}

void CHeroZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
