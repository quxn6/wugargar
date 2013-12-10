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
	m_MovingSpeed = 30.0f;
	m_AttackPower = 5;
	m_DefensivePower = 1;
	m_AttackRange = 100.0f;
	m_NumberOfTarget = 1;
	m_AttackSpeed = 2000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = false;
	m_FreezingAttackDuration = 5000;
	m_FreezingAttack = true;

	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/2.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/3.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/4.png");
	WalkAnimationImagePath.push_back(L"wugargar/ice/walk/5.png");

	m_Animation = NNAnimation::Create();
	int i = 0;
	for(auto &iter = WalkAnimationImagePath.begin(); iter != WalkAnimationImagePath.end(); ++iter)
	{
		m_Animation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_Animation->GetSpriteList()[i++]->SetFrameTime( 0.2f );
	}
	m_Animation->SetPosition(-((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageWidth()/2), -((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageHeight()/2));
	AddChild(m_Animation);

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