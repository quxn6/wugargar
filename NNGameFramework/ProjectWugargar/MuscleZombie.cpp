#include "MuscleZombie.h"


CMuscleZombie::CMuscleZombie(void)
{
	initStatus();
}


CMuscleZombie::~CMuscleZombie(void)
{
}

void CMuscleZombie::initStatus( void )
{
	m_zombieType = MUSCLE_ZOMBIE;
	m_HealthPoint = 800;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 5;
	m_DefensivePower = 5;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = false;

	ApplyZombieLevel();

	WalkAnimationImagePath.push_back(L"wugargar/mom/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/mom/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/mom/walk/2.png");
	WalkAnimationImagePath.push_back(L"wugargar/mom/walk/3.png");

	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/6.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/7.png");

	InitZombieAnimation();
}


void CMuscleZombie::Render()
{
	NNObject::Render();
}

void CMuscleZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
