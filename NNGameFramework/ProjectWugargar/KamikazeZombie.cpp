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
	m_Type = KAMIKAJE_ZOMBIE;
	m_HealthPoint = 50;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = 50.0f;
	m_AttackPower = 50;
	m_DefensivePower = 3;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 3;
	m_AttackSpeed = 2;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_is_splashAttack = true;
	m_splash_range = 200.0f;

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

//11.21 정인호
//Attack함수 오버로딩. KamikazeZombie는 공격 후 HP가 0이됨
void CKamikazeZombie::Attack()
{
	CCharacter::Attack();

	this->SetHP(0);

}
