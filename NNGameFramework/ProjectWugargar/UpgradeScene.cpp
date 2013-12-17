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
	ShowGlobalMoney();
	UpgradeCostSet();
	OperateUpgradeButton();
}

void CUpgradeScene::InitUpgradeUI()
{	
	//background set
	m_pBackground = NNSprite::Create(L"wugargar/upgrade.png");
	m_pBackground->SetPosition(0,0);
	AddChild(m_pBackground);

	//zombie animation path set
	int zombieCount = NUMBER_OF_ZOMBIE_TYPES-1; //enum °ªÀÌ ¾È¸Â¾Æ¼­ -1
	int count[NUMBER_OF_ZOMBIE_TYPES-1] ;
	std::wstring path[NUMBER_OF_ZOMBIE_TYPES-1] = {
		L"wugargar/poor/walk/",
		L"wugargar/vomit/walk/",
		L"wugargar/mom/walk/",
		L"wugargar/bomb/walk/",
		L"wugargar/smog/walk/",
		L"wugargar/ice/walk/",
		L"wugargar/hero/"};

	count[POOR_ZOMBIE] = 8;
	count[VOMIT_ZOMBIE] = 4;
	count[MUSCLE_ZOMBIE] = 4;
	count[KAMIKAJE_ZOMBIE] = 3;
	count[SMOG_ZOMBIE] = 8;
	count[ICE_ZOMBIE] = 6;
	count[HERO_ZOMBIE_SM9] = 1;

	//frame Set
	for ( int i=0; i< zombieCount; ++i )
	{
		m_Frame[i] = NNSprite::Create(L"wugargar/UpgradeFrame.png");
		AddChild(m_Frame[i]);
	}
	for(int i=0; i<zombieCount; ++i)
		m_Frame[i]->SetPosition(100.f * (i+1) + 20.f*i, 250.f);

	//Animation Set
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

	//coin animation set
	m_CoinAnimation = NNAnimation::Create();
	for(int i=0; i<10; ++i)
	{
		wchar_t temp[256] = {0, };
		swprintf_s(temp, _countof(temp), L"wugargar/coin/%d.png",i);
		m_CoinAnimation->AddSpriteNode(temp);
	}
	m_CoinAnimation->SetFrameTimeInSection(0.05f, 0, 9);
	AddChild(m_CoinAnimation);
	m_CoinAnimation->SetPosition(700,100);

	//set global money label
	m_ShowGlobalMoney = NNLabel::Create(L"global money", L"¸¼Àº °íµñ", 25.f);
	m_ShowGlobalMoney -> SetPosition(750.f , 100.f);
	AddChild(m_ShowGlobalMoney);

	for(int i = 0; i<(NUMBER_OF_ZOMBIE_TYPES - 1); ++i){
		m_UpgradeButton[i] = CUIButton::Create(L"wugargar/upgrade_button.png",L"wugargar/upgrade_button_pressed.png");
		m_UpgradeButton[i] -> SetPosition(100.f * (i+1) + 20.f*i, 370.f);
		AddChild(m_UpgradeButton[i]);
	}
}

void CUpgradeScene::ShowGlobalMoney()
{
	static wchar_t globalMoney[256];
	ZeroMemory(globalMoney, 256);	
	swprintf_s(globalMoney, _countof(globalMoney), L"%d", CPlayer::GetInstance()->GetGlobalMoney() );
	m_ShowGlobalMoney->SetString(globalMoney);
}

void CUpgradeScene::OperateUpgradeButton()
{
	if ( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		for ( int i=0 ; i<(NUMBER_OF_ZOMBIE_TYPES -1); ++i ) {		
			if ( m_UpgradeButton[i]->CheckButtonArea() && (CPlayer::GetInstance()->GetGlobalMoney() >= m_UpgradeCost[i]) ) {							
				CPlayer::GetInstance()->SetGlobalMoney( CPlayer::GetInstance()->GetGlobalMoney() - m_UpgradeCost[i] );
				CPlayer::GetInstance()->IncreaseZombieLevel(static_cast<ZombieType>(i));
			}
		}
	}
}

void CUpgradeScene::UpgradeCostSet()
{
	for(int i = 0; i < (NUMBER_OF_ZOMBIE_TYPES - 1) ; ++i) 
	{
		m_UpgradeCost[i] = 200 + 100*CPlayer::GetInstance()->GetZombieLevel(static_cast<ZombieType>(i));
	}
}
