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
	m_HealthPoint = 50;
	m_FullHP = m_HealthPoint;
	m_MovingSpeed = 50.0f;
	m_AttackPower = 50;
	m_DefensivePower = 3;
	m_AttackRange = 10.0f;
	m_NumberOfTarget = 3;
	m_AttackSpeed = 2000;
	m_CreateCost = 100;
	m_Identity = Zombie;
	m_SplashAttack = true;
	m_SplashAttackRange = 50.0f;
	m_SuicideBomber = true;

	ApplyZombieLevel();
	
	WalkAnimationImagePath.push_back(L"wugargar/bomb/walk/0.png");
	WalkAnimationImagePath.push_back(L"wugargar/bomb/walk/1.png");
	WalkAnimationImagePath.push_back(L"wugargar/bomb/walk/2.png");

	m_Animation = NNAnimation::Create();
	int i = 0;
	for(auto &iter = WalkAnimationImagePath.begin(); iter != WalkAnimationImagePath.end(); ++iter)
	{
		m_Animation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_Animation->GetSpriteList()[i++]->SetFrameTime( 0.2f );
	}
	AddChild(m_Animation);
}


void CKamikazeZombie::Render()
{
	NNObject::Render();
}

void CKamikazeZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}