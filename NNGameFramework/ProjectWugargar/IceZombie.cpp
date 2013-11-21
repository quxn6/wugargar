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
	m_HealthPoint = 100;
	m_MovingSpeed = 30.0f;
	m_AttackPower = 5;
	m_DefensivePower = 1;
	m_AttackRange = 100.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_is_splash = false;
}


void CIceZombie::Render()
{
	NNObject::Render();
}

void CIceZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}

void CIceZombie::Attack()
{
	CCharacter::Attack();

	m_AttackTarget->SetIceStartTime(clock());
	m_AttackTarget->SetIceNowTime(clock());
	m_AttackTarget->SetIceState(true);
	

}