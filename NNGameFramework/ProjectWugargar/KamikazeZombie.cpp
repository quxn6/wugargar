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
	m_HealthPoint = 30;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 100.0f;
	m_AttackPower = 100;
	m_DefensivePower = 10;
	m_AttackRange = 40.0f;
	m_NumberOfTarget = 3;
	m_AttackSpeed = 10;
	m_CreateCost = 250;
	m_Identity = Zombie;
	m_SplashAttack = true;
	m_SplashAttackRange = 50.0f;
	m_SuicideBomber = true;

	ApplyZombieLevel();
	
	WalkAnimationImagePath.push_back(L"wugargar/bomb/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/bomb/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/bomb/walk/2.png");

	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/bomb/bomb/6.png");

	InitZombieAnimation();
}


void CKamikazeZombie::Render()
{
	NNObject::Render();
}

void CKamikazeZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}