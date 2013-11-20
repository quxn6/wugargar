#include "NextStageScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"


CNextStageScene::CNextStageScene(void)
{
	InitButtons();
}


void CNextStageScene::InitButtons( void )
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
	

	for (int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i) {
		
		float xCoordOfButton = static_cast<float>(GAP_BETWEEN_UPGRADE_BUTTONS + i*(GAP_BETWEEN_UPGRADE_BUTTONS+SIZE_OF_UPGRADE_BUTTONS) );
		float yCoordOfButton = static_cast<float>(FIRST_Y_COORD_OF_UPGRADE_BUTTONS);

		// Upgrade button »ý¼º
		m_pUpgradeButtons[i] = CUIButton::Create(buttonpath_normal[i], buttonpath_pressed[i]);
		m_pUpgradeButtons[i]->SetPosition(xCoordOfButton, yCoordOfButton);
		AddChild( m_pUpgradeButtons[i] , 20);
		
		// Upgrade Label »ý¼º
		// PlayerÀÇ ÇöÀç levelÀ» °¡Á®¿È
		int currentLevel = CPlayer::GetInstance()->GetZombieLevel( static_cast<ZombieType>(i) );
		swprintf_s(m_LabelBuffer[i], _countof(m_LabelBuffer[i]), L"Current Level : %d\n$%d", currentLevel , 200+i );

		m_pUpgradeButtonLabel[i] = NNLabel::Create(m_LabelBuffer[i], L"¸¼Àº °íµñ", 15.0f);
		m_pUpgradeButtonLabel[i]->SetPosition(xCoordOfButton, yCoordOfButton + SIZE_OF_UPGRADE_BUTTONS);
				
		AddChild( m_pUpgradeButtonLabel[i] );
	}

	swprintf_s(
		m_ResultBuffer, 
		_countof(m_ResultBuffer), 
		L"Results\nTotal Kill : %d\nTotal Loss : %d\n", 
		CPlayer::GetInstance()->GetNumberOfKillInStage(), 
		CPlayer::GetInstance()->GetNumberOfLossInStage()
		);
	m_pResults = NNLabel::Create(m_ResultBuffer, L"¸¼Àº °íµñ", 15.0f);
	m_pResults->SetPosition(15, FIRST_Y_COORD_OF_RESULTS);

	AddChild(m_pResults);
	
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
	if( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_DOWN ) {
		NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
	}
}

