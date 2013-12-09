#include "StartScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"
#include "NNResourceManager.h"
#include "GameConfig.h"
#include "CharacterConfig.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"




CStartScene::CStartScene(void)
{
	InitBackGround();
	InitButtons();
	m_startscene_background_sound = NNResourceManager::GetInstance()->LoadSoundFromFile("sound/StartscenBackgroundSound.mp3", true, true);

	NNAudioSystem::GetInstance()->Play(m_startscene_background_sound);
}

void CStartScene::InitBackGround( void )
{
	m_pStartSceneBackground = NNSprite::Create( L"wugargar/StartSceneImage.png");
	m_pStartSceneBackground->SetPosition(0.0f, 0.0f);
	AddChild( m_pStartSceneBackground );
}


void CStartScene::InitButtons( void )
{

	m_MenuBar[MENU_PLAY] = NNLabel::Create( L"NEW GAME", L"궁서체", 20.f );
	m_MenuBar[MENU_PLAY]->SetPosition( GAME_SCREEN_MAX_SIZE_X - 200, 640 );
	AddChild( m_MenuBar[MENU_PLAY] );

	m_MenuBar[MENU_LOAD] = NNLabel::Create( L"LOAD GAME", L"궁서체", 20.f );
	m_MenuBar[MENU_LOAD]->SetPosition( GAME_SCREEN_MAX_SIZE_X - 200, 670 );
	AddChild( m_MenuBar[MENU_LOAD] );

	m_MenuBar[MENU_QUIT] = NNLabel::Create( L"QUIT", L"궁서체", 20.f );
	m_MenuBar[MENU_QUIT]->SetPosition( GAME_SCREEN_MAX_SIZE_X - 200, 700 );
	AddChild( m_MenuBar[MENU_QUIT] );

	for(int idx=0; idx<MENU_BAR_NUM; ++idx)
		m_MenuBar[idx]->SetColor( 255.f, 255.f, 255.f );

	m_KeyOn = 0;			// 현재 가리키고 있는 메뉴 위치

}

CStartScene::~CStartScene(void)
{
	NNAudioSystem::GetInstance()->Stop( m_startscene_background_sound );

}

void CStartScene::Render()
{
	NNObject::Render();
}

void CStartScene::Update( float dTime )
{
	NNScene::Update(dTime);

	

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_UP) == KEY_DOWN
		&& m_KeyOn!=MENU_PLAY)
	{
		--m_KeyOn;
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState(VK_DOWN) == KEY_DOWN 
		&& m_KeyOn!=MENU_QUIT)
	{
		++m_KeyOn;
	}
	m_KeyOn = (m_KeyOn + MENU_BAR_NUM) % MENU_BAR_NUM;
	m_MenuBar[m_KeyOn]->SetColor( 255.f, 0.f, 0.f );

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_DOWN )
	{
		switch (m_KeyOn)
		{
		case MENU_PLAY:
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
			return ;
			break;
		case MENU_LOAD:
			load();
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
			return ;
			break;
		case MENU_QUIT:
			PostMessage( NNApplication::GetInstance()->GetHWND(), WM_DESTROY, 0, 0 );
			break;
		default:
			break;
		}


	}

	for(int idx=0; idx<MENU_BAR_NUM; ++idx)
		if(idx!= m_KeyOn)
			m_MenuBar[idx]->SetColor( 255.f, 255.f, 255.f );


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


