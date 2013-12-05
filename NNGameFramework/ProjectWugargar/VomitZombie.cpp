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
	m_AttackPower = 8;
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

	m_Animation = NNAnimation::Create();
	int i = 0;
	for(auto &iter = WalkAnimationImagePath.begin(); iter != WalkAnimationImagePath.end(); ++iter)
	{
		m_Animation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_Animation->GetSpriteList()[i++]->SetFrameTime( 0.2f );
	}
	AddChild(m_Animation);
}


void CVomitZombie::Render()
{
	NNObject::Render();
}

void CVomitZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
