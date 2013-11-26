#include "NextStageScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"


CNextStageScene::CNextStageScene(void)
{
	m_pPlayer = CPlayer::GetInstance();
	
	InitButtons();
	ShowResults();
	SetNextStage();
}

void CNextStageScene::InitButtons(void )
{
	std::wstring buttonpath_normal[NUMBER_OF_ZOMBIE_TYPES];
	std::wstring buttonpath_pressed[NUMBER_OF_ZOMBIE_TYPES];

	buttonpath_normal[POOR_ZOMBIE] = L"wugargar/UIbuttons/button_normal_poorZombie.png";
	buttonpath_pressed[POOR_ZOMBIE]  = L"wugargar/UIbuttons/button_pressed_poorZombie.png";
	buttonpath_normal[VOMIT_ZOMBIE] = L"wugargar/UIbuttons/button_normal_vomitZombie.png";
	buttonpath_pressed[VOMIT_ZOMBIE] = L"wugargar/UIbuttons/button_pressed_vomitZombie.png";
	buttonpath_normal[MUSCLE_ZOMBIE] = L"wugargar/UIbuttons/button_normal_muscleZombie.png";
	buttonpath_pressed[MUSCLE_ZOMBIE] = L"wugargar/UIbuttons/button_pressed_muscleZombie.png";
	buttonpath_normal[KAMIKAJE_ZOMBIE] = L"wugargar/UIbuttons/button_normal_kamikazeZombie.png";
	buttonpath_pressed[KAMIKAJE_ZOMBIE] = L"wugargar/UIbuttons/button_pressed_kamikazeZombie.png";
	buttonpath_normal[SMOG_ZOMBIE] = L"wugargar/UIbuttons/button_normal_smogZombie.png";
	buttonpath_pressed[SMOG_ZOMBIE] = L"wugargar/UIbuttons/button_pressed_smogZombie.png";
	buttonpath_normal[ICE_ZOMBIE] = L"wugargar/UIbuttons/button_normal_iceZombie.png";
	buttonpath_pressed[ICE_ZOMBIE] = L"wugargar/UIbuttons/button_pressed_iceZombie.png";
	buttonpath_normal[HERO_ZOMBIE_SM9] = L"wugargar/UIbuttons/button_normal_sm9.png";
	buttonpath_pressed[HERO_ZOMBIE_SM9] = L"wugargar/UIbuttons/button_pressed_sm9.png";
	buttonpath_normal[BABY_HUMAN] = L"wugargar/UIbuttons/button_normal_baby.png";
	buttonpath_pressed[BABY_HUMAN] = L"wugargar/UIbuttons/button_pressed_baby.png";

	for (int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i) {

		float xCoordOfButton = static_cast<float>(GAP_BETWEEN_UPGRADE_BUTTONS + i*(GAP_BETWEEN_UPGRADE_BUTTONS+SIZE_OF_UPGRADE_BUTTONS) );
		float yCoordOfButton = static_cast<float>(FIRST_Y_COORD_OF_UPGRADE_BUTTONS);

		// Upgrade button 생성
		m_pUpgradeButtons[i] = CUIButton::Create(buttonpath_normal[i], buttonpath_pressed[i]);
		m_pUpgradeButtons[i]->SetPosition(xCoordOfButton, yCoordOfButton);
		AddChild( m_pUpgradeButtons[i] , 20);

		// Upgrade 비용 산출
		SetUpgradeText(static_cast<ZombieType>(i));
		
		// Upgrade Label 생성


		m_pUpgradeButtonLabel[i] = NNLabel::Create(m_LabelBuffer[i], L"맑은 고딕", 15.0f);
		m_pUpgradeButtonLabel[i]->SetPosition(xCoordOfButton, yCoordOfButton + SIZE_OF_UPGRADE_BUTTONS);
		AddChild( m_pUpgradeButtonLabel[i] );
	}

}

void CNextStageScene::ShowResults( void )
{
	swprintf_s(
		m_ResultBuffer, 
		_countof(m_ResultBuffer), 
		L"Results\nGlobalMoney : %d \nTotal Kill : %d\nTotal Loss : %d\n", 
		m_pPlayer->GetGlobalMoney(),
		m_pPlayer->GetNumberOfKillInStage(), 
		m_pPlayer->GetNumberOfLossInStage()
		);
	m_pResults = NNLabel::Create(m_ResultBuffer, L"맑은 고딕", 15.0f);
	m_pResults->SetPosition(15, FIRST_Y_COORD_OF_RESULTS);

	AddChild(m_pResults);
}


// 유닛 별 업그레이드 비용 산정
void CNextStageScene::SetUpgradeText(ZombieType zombietype)
{
	m_UpgradeCost[zombietype] = 200 + 100*m_pPlayer->GetZombieLevel(zombietype);
	swprintf_s(
		m_LabelBuffer[zombietype], 
		_countof(m_LabelBuffer[zombietype]), 
		L"Level : %d\nCost : $%d", 
		m_pPlayer->GetZombieLevel(zombietype), 
		m_UpgradeCost[zombietype]
	);
}


void CNextStageScene::SetNextStage( void )
{
	std::wstring saveButtonPath = L"wugargar/UIbuttons/savegame.png";
	std::wstring nextLevelButtonPath = L"wugargar/UIbuttons/nextlevel.png";
	std::wstring tryagainButtonPath = L"wugargar/UIbuttons/tryagain.png";

	if ( m_pPlayer->GetPlayerStatus() == WIN ) {
		m_pNextStageButton = CUIButton::Create(nextLevelButtonPath, nextLevelButtonPath);
		m_pPlayer->IncreaseStage();
	} else {		
		m_pNextStageButton = CUIButton::Create(tryagainButtonPath, tryagainButtonPath);
	}
	m_pNextStageButton->SetPosition(static_cast<float> (GAME_SCREEN_MAX_SIZE_X/2), static_cast<float> (GAME_SCREEN_MAX_SIZE_Y/2) );
	AddChild(m_pNextStageButton);

	m_pGameSaveButton = CUIButton::Create(saveButtonPath, saveButtonPath);
	m_pGameSaveButton->SetPosition(static_cast<float> (GAME_SCREEN_MAX_SIZE_X/2), static_cast<float> (GAME_SCREEN_MAX_SIZE_Y/2 + 100) );
	AddChild(m_pGameSaveButton);

}


CNextStageScene::~CNextStageScene(void)
{
}




void CNextStageScene::Render()
{
	NNObject::Render();
}

void CNextStageScene::Update( float dTime )
{
	// zombie upgrade 


	if ( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {
		// 업그레이드 버튼 처리		
		for ( int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i ) {		
			if ( m_pUpgradeButtons[i]->CheckButtonArea() && (m_pPlayer->GetGlobalMoney() >= m_UpgradeCost[i]) ) {							
				m_pPlayer->SetGlobalMoney( m_pPlayer->GetGlobalMoney() - m_UpgradeCost[i] );
				m_pPlayer->IncreaseZombieLevel(static_cast<ZombieType>(i));
				SetUpgradeText(static_cast<ZombieType>(i));				

				// global money 표시용 임시 나중에 적당한 위치에 라벨로 빼는 것이 좋겠음.
				swprintf_s(
					m_ResultBuffer, 
					_countof(m_ResultBuffer), 
					L"Results\nGlobalMoney : %d \nTotal Kill : %d \nTotal Loss : %d \n", 
					m_pPlayer->GetGlobalMoney(),
					m_pPlayer->GetNumberOfKillInStage(), 
					m_pPlayer->GetNumberOfLossInStage()
					);
			}		
		}
		
		// 세이브 버튼 클릭시
		if ( m_pGameSaveButton->CheckButtonArea() ) {
			//save logic 처리
		}
		
		// 다음 스테이지 버튼 클릭시
		if ( m_pNextStageButton->CheckButtonArea() ) {
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
		}
	}


	if( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_DOWN ) {
		NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
	}
}
