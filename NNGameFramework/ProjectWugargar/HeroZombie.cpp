#include "HeroZombie.h"


CHeroZombie::CHeroZombie(void)
{
	initStatus();
}


CHeroZombie::~CHeroZombie(void)
{
}

void CHeroZombie::initStatus( void )
{
	m_Type = HERO_ZOMBIE_SM9;

	m_HealthPoint = 300;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 20.0f;
	m_AttackPower = 30;
	m_DefensivePower = 5;
	m_AttackRange = 120.0f;
	m_NumberOfTarget = 5;
	m_AttackSpeed = 3;
	m_CreateCost = 1;
	m_Identity = Zombie;
	m_is_splash = false;
}


void CHeroZombie::Render()
{
	NNObject::Render();
}

void CHeroZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
