#include "NormalPolice.h"



CNormalPolice::CNormalPolice(void)
{
	initStatus();
}


CNormalPolice::~CNormalPolice(void)
{

}

void CNormalPolice::Render()
{
	NNObject::Render();
}

void CNormalPolice::Update( float dTime )
{
	CCharacter::Update(dTime);
}

void CNormalPolice::initStatus( void )
{
	m_HealthPoint = 100;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 35.0f;
	m_AttackPower = 10;
	m_DefensivePower = 2;
	m_AttackRange = 200.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
	m_Identity = Police;
	m_SplashAttack = false;
}
