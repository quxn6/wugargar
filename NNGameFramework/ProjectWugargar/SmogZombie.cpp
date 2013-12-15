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
	m_zombieType = SMOG_ZOMBIE;
	m_HealthPoint = 800;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 80.0f;
	m_AttackPower = 20;
	m_DefensivePower = 1;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 5;
	m_AttackSpeed = 3000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = true;
	m_SplashAttackRange = 100.0f;

	ApplyZombieLevel();
	
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/2.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/3.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/4.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/5.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/6.png");
	WalkAnimationImagePath.push_back(L"wugargar/smog/walk/7.png");

	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/smog/dead/6.png");

	InitZombieAnimation();
}


void CSmogZombie::Render()
{
	NNObject::Render();
}

void CSmogZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
