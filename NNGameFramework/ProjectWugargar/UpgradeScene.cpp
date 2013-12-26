#include "UpgradeScene.h"
#include "NNAnimation.h"
#include <windows.h>
#include "NNSceneDirector.h"
#include "PlayScene.h"
#include "StageSelectScene.h"


CUpgradeScene::CUpgradeScene(void)
{
	InitUpgradeUI();
	CPlayer::GetInstance()->ReadyToUpgrade();
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
	int zombieCount = NUMBER_OF_ZOMBIE_TYPES-1; //enum 값이 안맞아서 -1
	int count[NUMBER_OF_ZOMBIE_TYPES-1] ;
	std::wstring path[NUMBER_OF_ZOMBIE_TYPES-1] = {
		L"wugargar/zombie/poor/walk/",
		L"wugargar/zombie/vomit/walk/",
		L"wugargar/zombie/mom/walk/",
		L"wugargar/zombie/bomb/walk/",
		L"wugargar/zombie/smog/walk/",
		L"wugargar/zombie/ice/walk/",
		L"wugargar/zombie/hero/"};

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
	m_ShowGlobalMoney = NNLabel::Create(L"global money", L"맑은 고딕", 25.f);
	m_ShowGlobalMoney -> SetPosition(750.f , 100.f);
	AddChild(m_ShowGlobalMoney);
	
	//upgrade button set
	for(int i = 0; i<(NUMBER_OF_ZOMBIE_TYPES - 1); ++i){
		m_UpgradeButton[i] = CUIButton::Create(L"wugargar/upgrade_button.png",L"wugargar/upgrade_button_pressed.png");
		m_UpgradeButton[i] -> SetPosition(100.f * (i+1) + 20.f*i, 370.f);
		AddChild(m_UpgradeButton[i]);
	}

	for(int i = 0; i<(NUMBER_OF_ZOMBIE_TYPES-1);++i){
		//show upgrade cost
		m_ShowUpgradeCost[i] = NNLabel::Create(L"cost",L"맑은 고딕",20.f);
		m_ShowUpgradeCost[i] -> SetPosition(100.f * (i+1) + 20.f*i + 35, 220.f);
		AddChild(m_ShowUpgradeCost[i]);
		//show upgrade level
		m_ShowUpgradeLevel[i] = NNLabel::Create(L"level",L"맑은 고딕",20.f);
		m_ShowUpgradeLevel[i] ->SetPosition(100.f * (i+1) + 20.f*i +10, 250.f);
		AddChild(m_ShowUpgradeLevel[i]);
	}

	// 임시로 다음 스테이지 버튼 만들었음
	m_pNextStageButton = CUIButton::Create(L"wugargar/arrow.png", L"wugargar/arrow.png");
	m_pNextStageButton->SetPosition(GAME_SCREEN_MAX_SIZE_X-240.0f,GAME_SCREEN_MAX_SIZE_Y-200.0f );
	AddChild(m_pNextStageButton, 100);

	m_pPreStageButton = CUIButton::Create(L"wugargar/arrow-opp.png", L"wugargar/arrow-opp.png");
	m_pPreStageButton->SetPosition(80.f, GAME_SCREEN_MAX_SIZE_Y-200.0f);
	AddChild(m_pPreStageButton, 100);


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

		// 다음 스테이지 버튼 클릭시
		if ( m_pNextStageButton->CheckButtonArea() ) {
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
			return; 
		}

		//이전 스테이지 버튼 클릭시
		if ( m_pPreStageButton->CheckButtonArea() ) {
			NNSceneDirector::GetInstance()->ChangeScene(CStageSelectScene::Create());
			return;
		}
	}
}

void CUpgradeScene::UpgradeCostSet()
{
	static wchar_t UpgradeCost[256][NUMBER_OF_ZOMBIE_TYPES-1];
	static wchar_t ZombieLevel[256][NUMBER_OF_ZOMBIE_TYPES-1];
	for(int i = 0; i < (NUMBER_OF_ZOMBIE_TYPES - 1) ; ++i) 
	{
		m_UpgradeCost[i] = 200 + 100*CPlayer::GetInstance()->GetZombieLevel(static_cast<ZombieType>(i));
		swprintf_s( UpgradeCost[i], L"%d", m_UpgradeCost[i]);
		m_ShowUpgradeCost[i] -> SetString(UpgradeCost[i]);
		swprintf_s( ZombieLevel[i], L"Lv.%d", CPlayer::GetInstance()->GetZombieLevel(static_cast<ZombieType>(i)));
		m_ShowUpgradeLevel[i] -> SetString(ZombieLevel[i]);
	}
}
