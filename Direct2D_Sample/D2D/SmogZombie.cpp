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
	m_HealthPoint = 80;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 20;
	m_DefensivePower = 1;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 5;
	m_AttackSpeed = 1;
	m_Identity = Zombie;
}


void CSmogZombie::Render()
{
	NNObject::Render();
}

void CSmogZombie::Update( float dTime )
{

}
