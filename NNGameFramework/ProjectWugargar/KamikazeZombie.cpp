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
	m_zombieType = KAMIKAJE_ZOMBIE;
	m_HealthPoint = 50;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 50.0f;
	m_AttackPower = 50;
	m_DefensivePower = 3;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 3;
	m_AttackSpeed = 2000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = true;
	m_SplashAttackRange = 50.0f;
	m_SuicideBomber = true;

	ApplyZombieLevel();
}


void CKamikazeZombie::Render()
{
	NNObject::Render();
}

void CKamikazeZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}