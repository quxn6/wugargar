#include "VomitZombie.h"


CVomitZombie::CVomitZombie(void)
{
	initStatus();
}


CVomitZombie::~CVomitZombie(void)
{
}

void CVomitZombie::initStatus( void )
{
	m_zombieType = VOMIT_ZOMBIE;
	m_HealthPoint = 100;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 35;
	m_DefensivePower = 2;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 3000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = false;

	ApplyZombieLevel();

	WalkAnimationImagePath.push_back(L"wugargar/vomit/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/vomit/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/vomit/walk/2.png");
	WalkAnimationImagePath.push_back(L"wugargar/vomit/walk/3.png");

	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/6.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/7.png");
	DeadAnimationImagePath.push_back(L"wugargar/vomit/dead/8.png");

	InitZombieAnimation();
}


void CVomitZombie::Render()
{
	NNObject::Render();
}

void CVomitZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
