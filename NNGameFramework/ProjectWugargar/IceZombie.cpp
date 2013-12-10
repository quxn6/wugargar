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

	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/6.png");
	DeadAnimationImagePath.push_back(L"wugargar/ice/dead/7.png");

	m_Animation = NNAnimation::Create();
	int i = 0;
	for(auto &iter = WalkAnimationImagePath.begin(); iter != WalkAnimationImagePath.end(); ++iter)
	{
		m_Animation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_Animation->GetSpriteList()[i++]->SetFrameTime( 0.2f );
	}
	m_Animation->SetPosition(-((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageWidth()/2), -((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageHeight()/2));

	m_DeadAnimation = NNAnimation::Create();
	i=0;
	for(auto &iter = DeadAnimationImagePath.begin(); iter != DeadAnimationImagePath.end(); ++iter)
	{
		m_DeadAnimation->AddSpriteNode(const_cast<wchar_t*>((*iter).c_str()));
		m_DeadAnimation->GetSpriteList()[i++]->SetFrameTime( 0.1f );
	}
	m_DeadAnimation->SetLoop(false);

	m_Animation->SetPosition(-((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageWidth()/2), -((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageHeight()/2));
	AddChild(m_Animation);

	m_DeadAnimation->SetPosition(-((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageWidth()/2), -((m_Animation->GetSpriteList()[0])->GetSprite()->GetImageHeight()/2));
	m_DeadAnimation->SetVisible(false);
	AddChild(m_DeadAnimation);

	m_pShowHP->SetCutSize(0,0,50.f,5.f);
	m_pShowHP->SetPosition(m_Animation->GetPositionX(), m_Animation->GetPositionY()); //스프라이트와 이미지 크기에 맞게 배치는 나중에 고려

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