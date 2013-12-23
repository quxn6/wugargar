#include "StartScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"
#include "NNResourceManager.h"
#include "GameConfig.h"
#include "CharacterConfig.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"
#include "StageSelectScene.h"
#include "UpgradeScene.h"
#include "NNSound.h"
#include "NNSprite.h"
#include "NNLabel.h"


CStartScene::CStartScene(void)
{
	InitBackGround();
	InitButtons();

	//Sound추가. 배경음이며 무한 loop되며 재생되도록
	m_startscene_background_sound = NNResourceManager::GetInstance()->
		LoadSoundFromFile("sound/StartscenBackgroundSound.mp3", true, true);

	NNAudioSystem::GetInstance()->Play(m_startscene_background_sound);
}

void CStartScene::InitBackGround( void )
{
	m_pStartSceneBackground = 
		NNSprite::Create( L"wugargar/StartSceneImage.jpg");
	m_pStartSceneBackground->SetPosition(0.0f, 0.0f);
	AddChild( m_pStartSceneBackground );
}


void CStartScene::InitButtons( void )
{
	//기존 버튼에서 Label을 이용한 방식으로 변경. 라벨 설정
	m_MenuBar[MENU_PLAY] = 
		NNLabel::Create( L"NEW GAME", L"궁서체", 25.f );
	m_MenuBar[MENU_PLAY]->SetPosition( 48, 480 );
	AddChild( m_MenuBar[MENU_PLAY] );

	m_MenuBar[MENU_LOAD] =
		NNLabel::Create( L"LOAD GAME", L"궁서체", 25.f );
	m_MenuBar[MENU_LOAD]->SetPosition(48, 520 );
	AddChild( m_MenuBar[MENU_LOAD] );

	m_MenuBar[MENU_QUIT] = 
		NNLabel::Create( L"QUIT", L"궁서체", 25.f );
	m_MenuBar[MENU_QUIT]->SetPosition(48, 560 );
	AddChild( m_MenuBar[MENU_QUIT] );

	//라벨의 색을 하얀색으로 설정(안보이니까)
	for(int idx=0; idx<MENU_BAR_NUM; ++idx)
		m_MenuBar[idx]->SetColor( 230.f, 230.f, 230.f );

	m_KeyOn = 0;			
	// 현재 가리키고 있는 메뉴 위치

}

CStartScene::~CStartScene(void)
{
	//소멸자에서 배경음 재생 중지
	NNAudioSystem::GetInstance()->Stop( m_startscene_background_sound );

}

void CStartScene::Render()
{
	NNObject::Render();
}

void CStartScene::Update( float dTime )
{
	NNScene::Update(dTime);

	
	//m_KeyOn을 이용하여 라벨의 상태, 입력 설정
	if ( NNInputSystem::GetInstance()->GetKeyState(VK_UP) == KEY_DOWN
		&& m_KeyOn!=MENU_PLAY)
		--m_KeyOn;

	else if ( NNInputSystem::GetInstance()->GetKeyState(VK_DOWN) == KEY_DOWN 
		&& m_KeyOn!=MENU_QUIT)
		++m_KeyOn;

	m_KeyOn = (m_KeyOn + MENU_BAR_NUM) % MENU_BAR_NUM;
	//현재 가리키고 있는 부분의 색상을 빨간색으로
	m_MenuBar[m_KeyOn]->SetColor( 255.f, 50.f, 50.f );


	//엔터 버튼 누르면 선택된 부분 선택하게됨
	if ( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_DOWN )
	{
		switch (m_KeyOn)
		{
		case MENU_PLAY:
			NNSceneDirector::GetInstance()->
				ChangeScene(CStageSelectScene::Create());
			return ;
			break;
		case MENU_LOAD:
			load();
			NNSceneDirector::GetInstance()->
				ChangeScene(CStageSelectScene::Create());
			return ;
			break;
		case MENU_QUIT:
			//종료 처리 로직
			PostMessage( NNApplication::GetInstance()->GetHWND(), 
				WM_DESTROY, 0, 0 );
			break;
		default:
			break;
		}


	}

	//현재 선택되어 있는 부분 외 라벨을 흰색으로 재설정
	for(int idx=0; idx<MENU_BAR_NUM; ++idx)
		if(idx!= m_KeyOn)
			m_MenuBar[idx]->SetColor( 230.f, 230.f, 230.f );


}

// load game
// NNXML로 xml형식의 savefile을 불러온다.-sh
void CStartScene::load()
{
	// initialize
	
 	CPlayer* pPlayer = CPlayer::GetInstance();
	NNXML *m_TestXML = NNResourceManager::GetInstance()->
		LoadXMLFromFIle("savegame.sav");

	// 예외처리
	if (!(m_TestXML->GetLoadSuccess())) {
		return ;
	}

	// get files from save file
	int globalMoney = std::stoi(m_TestXML->
		XPathToString("/player1/GlobalMoney/text()").c_str());
	pPlayer->SetGlobalMoney( globalMoney ); 

	int totalkill = std::stoi(m_TestXML->
		XPathToString("/player1/TotalKill/text()").c_str());
	pPlayer->SetTotalKill( totalkill ); 

	int totalloss = std::stoi(m_TestXML->
		XPathToString("/player1/TotalLoss/text()").c_str());
	pPlayer->SetTotalLoss( totalloss);

	int currentstage =  std::stoi(m_TestXML->
		XPathToString("/player1/CurrentStage/text()").c_str());
	pPlayer->SetCurrentStage(currentstage); 

	float infectionrate = std::stof(m_TestXML->
		XPathToString("/player1/InfectionRate/text()").c_str());
	pPlayer->SetInfectionRate(infectionrate ); 


	for ( int i=0; i<NUMBER_OF_ZOMBIE_TYPES ; ++i ) {
		std::string xPath = "/player1/UnitLevel/";
		xPath.append("UnitNo");
		xPath.append(std::to_string(i) );
		xPath.append("/text()");
		pPlayer->SetZombieLevel(static_cast<ZombieType>(i), 
			std::stoi(m_TestXML->XPathToString(xPath).c_str() ) );
	}
	
#ifdef _DEBUG
	printf("%d\n", pPlayer->GetGlobalMoney() );
	printf("%d\n", pPlayer->GetTotalKill() );
	printf("%d\n", pPlayer->GetTotalLoss() );
	printf("%d\n", pPlayer->GetClearedStage() );
	printf("%f\n", pPlayer->GetInfectionRate() );
	for ( int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i ) {
		printf("%d ", pPlayer->GetZombieLevel
			(static_cast<ZombieType>(i)) );
	}	
#endif

}
