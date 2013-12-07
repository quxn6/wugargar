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
	m_AttackPower = 10;
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

	m_Animation = NNAnimation::Create();
	int i = 0;
	for(auto &iter = WalkAnimationImagePath.begin(); iter != WalkAnimationImagePath.end(); ++iter)
	{
		m_Animation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_Animation->GetSpriteList()[i++]->SetFrameTime( 0.2f );
	}
	AddChild(m_Animation);
}


void CSmogZombie::Render()
{
	NNObject::Render();
}

void CSmogZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
