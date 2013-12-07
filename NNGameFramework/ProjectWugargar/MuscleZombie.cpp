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
	m_HealthPoint = 300;
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

	m_Animation = NNAnimation::Create();
	int i = 0;
	for(auto &iter = WalkAnimationImagePath.begin(); iter != WalkAnimationImagePath.end(); ++iter)
	{
		m_Animation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_Animation->GetSpriteList()[i++]->SetFrameTime( 0.2f );
	}
	AddChild(m_Animation);
}


void CMuscleZombie::Render()
{
	NNObject::Render();
}

void CMuscleZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
