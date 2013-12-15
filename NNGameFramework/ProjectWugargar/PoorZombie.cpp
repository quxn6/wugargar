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
	m_zombieType = POOR_ZOMBIE;
	m_HealthPoint = 100;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 40.0f;
	m_AttackPower = 20;
	m_DefensivePower = 2;
	m_AttackRange = 30.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = false;

	ApplyZombieLevel();

	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/2.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/3.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/4.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/5.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/6.png");
	WalkAnimationImagePath.push_back(L"wugargar/poor/walk/7.png");

	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/6.png");
	DeadAnimationImagePath.push_back(L"wugargar/poor/dead/7.png");

	InitZombieAnimation();
}


void CPoorZombie::Render()
{
	NNObject::Render();
}

void CPoorZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
