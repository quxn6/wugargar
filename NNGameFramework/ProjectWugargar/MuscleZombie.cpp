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

	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/0.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/1.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/2.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/3.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/4.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/5.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/6.png");
	DeadAnimationImagePath.push_back(L"wugargar/mom/dead/7.png");

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

	m_pShowHP->SetCutSize(0,0,50.f,5.f);
	m_pShowHP->SetPosition(m_Animation->GetPositionX(), m_Animation->GetPositionY()); //스프라이트와 이미지 크기에 맞게 배치는 나중에 고려
}


void CMuscleZombie::Render()
{
	NNObject::Render();
}

void CMuscleZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}
