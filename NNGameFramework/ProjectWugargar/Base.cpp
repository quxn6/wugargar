#include "Base.h"


CBase::CBase(void)
{
	initStatus();
}

void CBase::initStatus( void )
{
	m_HealthPoint = 1000;
	m_MovingSpeed = 0.0f;
	m_AttackPower = 0;
	m_DefensivePower = 0;
	m_AttackRange = 0.0f;
	m_NumberOfTarget = 0;
	m_AttackSpeed = 0;	
	m_AttackTarget = nullptr;
}



CBase::~CBase(void)
{
}


void CBase::Render()
{
	NNObject::Render();
}

void CBase::Update( float dTime )
{

}

