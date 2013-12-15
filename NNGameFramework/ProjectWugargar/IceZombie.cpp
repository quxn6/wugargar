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
	m_zombieType = ICE_ZOMBIE;
	m_HealthPoint = 100;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 20;
	m_DefensivePower = 1;
	m_AttackRange = 100.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
	m_CreateCost = 300;
	m_Identity = Zombie;
	m_SplashAttack = false;
	m_FreezingAttackDuration = 3000;
	m_FreezingAttack = true;

	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/2.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/3.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/4.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/5.png");

	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/6.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/7.png");

	InitZombieAnimation();
	ApplyZombieLevel();
}


void CIceZombie::Render()
{
	NNObject::Render();
}

void CIceZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}