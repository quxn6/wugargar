#include "StartScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"
#include "NNResourceManager.h"
#include "GameConfig.h"

#define POLICE_TYPE_NUM 6
#define ZOMBIE_TYPE_NUM 8

CStartScene::CStartScene(void)
{
	InitButtons();
}

void CStartScene::InitButtons( void )
{
	std::wstring new_button_path = L"wugargar/UIbuttons/startbutton_normal.png";
	std::wstring new_button_path_pressed = L"wugargar/UIbuttons/startbutton_pressed.png";
	std::wstring load_button_path = L"wugargar/UIbuttons/loadbutton_normal.png";
	std::wstring load_button_path_pressed = L"wugargar/UIbuttons/loadbutton_pressed.png";
	std::wstring exit_button_path = L"wugargar/UIbuttons/exitbutton_normal.png";
	std::wstring exit_button_path_pressed = L"wugargar/UIbuttons/exitbutton_pressed.png";
	std::wstring main_title = L"wugargar/UIbuttons/MainTitle.png";


	m_pNewGameButton = CUIButton::Create(new_button_path, new_button_path_pressed);
	m_pNewGameButton->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 2);
	AddChild(m_pNewGameButton, 20);

	m_pLoadGameButton = CUIButton::Create(load_button_path, load_button_path_pressed);
	m_pLoadGameButton->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 3);
	AddChild(m_pLoadGameButton, 20);

	m_pExitButton = CUIButton::Create(exit_button_path, exit_button_path_pressed);
	m_pExitButton->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 4);
	AddChild(m_pExitButton, 20);

	m_pMainTitle = NNSprite::Create(main_title);
	m_pMainTitle->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 1);
	AddChild(m_pMainTitle, 19);
}

CStartScene::~CStartScene(void)
{

}

void CStartScene::Render()
{
	NNObject::Render();
}

void CStartScene::Update( float dTime )
{
	NNScene::Update(dTime);

	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON)) {
		// new game
		if(m_pNewGameButton->CheckButtonArea()) {
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
			return ;
		}
		
		// load game
		if(m_pLoadGameButton->CheckButtonArea()) {
			load();
		}
		
		// exit
		if(m_pExitButton->CheckButtonArea()) {
		}		
	}
}

// load game
// NNXML로 xml형식의 savefile을 불러온다.-sh
void CStartScene::load()
{
	// initialize
	
 	CPlayer* pPlayer = CPlayer::GetInstance();
	m_TestXML = NNResourceManager::GetInstance()->LoadXMLFromFIle("savegame.sav");

	// 예외처리
	if (!(m_TestXML->GetLoadSuccess())) {
		return ;
	}

	// get files from save file
	pPlayer->SetGlobalMoney( std::stoi(m_TestXML->XPathToString("/player1/GlobalMoney/text()").c_str()) ); 
	pPlayer->SetTotalKill( std::stoi(m_TestXML->XPathToString("/player1/TotalKill/text()").c_str()) ); 
	pPlayer->SetTotalLoss( std::stoi(m_TestXML->XPathToString("/player1/TotalLoss/text()").c_str()) ); 
	pPlayer->SetCurrentStage( std::stoi(m_TestXML->XPathToString("/player1/CurrentStage/text()").c_str()) ); 
	pPlayer->SetInfectionRate( std::stof(m_TestXML->XPathToString("/player1/InfectionRate/text()").c_str()) ); 
	for ( int i=0; i<NUMBER_OF_ZOMBIE_TYPES ; ++i ) {
		std::string xPath = "/player1/UnitLevel/";
		xPath.append("UnitNo");
		xPath.append(std::to_string(i) );
		xPath.append("/text()");
		pPlayer->SetZombieLevel(static_cast<ZombieType>(i), std::stoi(m_TestXML->XPathToString(xPath).c_str() ) );
	}
	
#ifdef _DEBUG
	printf("%d\n", pPlayer->GetGlobalMoney() );
	printf("%d\n", pPlayer->GetTotalKill() );
	printf("%d\n", pPlayer->GetTotalLoss() );
	printf("%d\n", pPlayer->GetCurrentStage() );
	printf("%f\n", pPlayer->GetInfectionRate() );
	for ( int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i ) {
		printf("%d ", pPlayer->GetZombieLevel(static_cast<ZombieType>(i)) );
	}	
#endif

}

void CStartScene::loadPoliceInfo()
{

}
