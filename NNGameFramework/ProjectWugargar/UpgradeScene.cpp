#include "UpgradeScene.h"
#include "NNAnimation.h"
#include <windows.h>


CUpgradeScene::CUpgradeScene(void)
{
	InitUpgradeUI();
}


CUpgradeScene::~CUpgradeScene(void)
{
}

void CUpgradeScene::Render()
{
	NNObject::Render();
}

void CUpgradeScene::Update( float dTime )
{
	NNScene::Update(dTime);
}

void CUpgradeScene::InitUpgradeUI()
{
	int zombieCount = NUMBER_OF_ZOMBIE_TYPES-1;
	int count[NUMBER_OF_ZOMBIE_TYPES-1] ;
	std::wstring path[NUMBER_OF_ZOMBIE_TYPES-1] = {
		L"wugargar/poor/walk/",
		L"wugargar/vomit/walk/",
		L"wugargar/mom/walk/",
		L"wugargar/bomb/walk/",
		L"wugargar/smog/walk/",
		L"wugargar/ice/walk/",
		L"wugargar/hero/"};
	m_pBackground = NNSprite::Create(L"wugargar/upgrade.png");
	m_pBackground->SetPosition(0,0);
	AddChild(m_pBackground);

	count[POOR_ZOMBIE] = 8;
	count[VOMIT_ZOMBIE] = 4;
	count[MUSCLE_ZOMBIE] = 4;
	count[KAMIKAJE_ZOMBIE] = 3;
	count[SMOG_ZOMBIE] = 8;
	count[ICE_ZOMBIE] = 6;
	count[HERO_ZOMBIE_SM9] = 1;

	for ( int i=0; i< zombieCount; ++i )
	{
		m_Frame[i] = NNSprite::Create(L"wugargar/UpgradeFrame.png");
		AddChild(m_Frame[i]);
	}
	for(int i=0; i < zombieCount; ++i)
	{
		m_ZombieAnimation[i] = NNAnimation::Create();
		for(int j=0;j<count[i]; ++j)
		{
			wchar_t temp[256] = {0, };
			swprintf_s(temp, _countof(temp), L"%s%d.png",path[i].c_str(),j);
			m_ZombieAnimation[i]->AddSpriteNode(temp);
		}
		m_ZombieAnimation[i]->SetFrameTimeInSection(0.2f,0, count[i]-1);
		m_Frame[i]->AddChild(m_ZombieAnimation[i]);
	}
	m_ZombieAnimation[0]->SetCenter( -30.f, -10.f);
	m_ZombieAnimation[1]->SetCenter( -20.f, -10.f);
	m_ZombieAnimation[2]->SetCenter( -10.f, -10.f);
	m_ZombieAnimation[3]->SetCenter( -25.f,  0.f);
	m_ZombieAnimation[4]->SetCenter( -20.f, 0.f);
	m_ZombieAnimation[5]->SetCenter( -25.f, 0.f);
	m_ZombieAnimation[6]->SetCenter( -5.f, -5.f);

	m_CoinAnimation = NNAnimation::Create();
	for(int i=0; i<10; ++i)
	{
		wchar_t temp[256] = {0, };
		swprintf_s(temp, _countof(temp), L"wugargar/coin/%d.png",i);
		m_CoinAnimation->AddSpriteNode(temp);
	}
	m_CoinAnimation->SetFrameTimeInSection(0.05f, 0, 9);
	AddChild(m_CoinAnimation);

	for(int i=0; i<zombieCount; ++i)
		m_Frame[i]->SetPosition(100.f * (i+1) + 20.f*i, 250.f);

	m_CoinAnimation->SetPosition(100,200);
}
