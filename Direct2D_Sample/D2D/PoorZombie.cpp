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
	m_HealthPoint = 100;
	m_MovingSpeed = 2.0f;
	m_AttackPoint = 10;
	m_DefensivePower = 2;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 1;
	m_Identity = Zombie;
}


void CPoorZombie::Render()
{
	NNObject::Render();
}

void CPoorZombie::Update( float dTime )
{

}
