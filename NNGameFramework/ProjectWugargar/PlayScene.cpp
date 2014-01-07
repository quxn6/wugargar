#include "PlayScene.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNApplication.h"

#include "HumanFarm.h"
#include "Player.h"
#include "Background.h"
#include "XMLWriter.h"
#include "PoliceCreator.h"
#include "NNSceneDirector.h"
#include "NextStageScene.h"
#include "CharacterConfig.h"
#include "NNResourceManager.h"
#include "StageSelectScene.h"
#include "Police.h"
#include "Zombie.h"
#include "DeadPolice.h"
#include "Lightning.h"
#include "MapObstaclManager.h"
#include "UIButton.h"
#include "MapCreator.h"
#include "Base.h"
#include "NNAnimation.h"

CPlayScene* CPlayScene::m_pInstance = nullptr;

CPlayScene* CPlayScene::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new CPlayScene();
	}

	return m_pInstance;
}

void CPlayScene::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

CPlayScene::CPlayScene(void)
{	
//	initLoading();

	//Sleep(1000);
	m_LocalMoneyTimeChecker = 0;
	m_StageElapsedTime = 0;

	_initBackground();
	_initMap();
	_initUI();
	loadCharacterInfo();	
	
	

	// player초기화
	m_pPlayer = CPlayer::GetInstance();
	m_pPlayer->ReadyToPlay();

	// police creator 초기화
	m_pPoliceCreator = CPoliceCreator::Create();

	// 장애물 생성기 초기화
	m_pMapObstacleManager = MapObstaclManager::Create();
	AddChild(m_pMapObstacleManager, 2);
	

	// temporary
	// FPS를 표시하고, 콘솔창을 띄움
	m_pShowMouseStatus = NNLabel::Create( L"cursor position", L"맑은 고딕", 35.f );
	m_pShowMouseStatus->SetPosition(0.0f, 0.0f);
	AddChild( m_pShowMouseStatus , 20);
	// END TEMP
	m_pShowMeatPoint = NNLabel::Create( L"Local Money", L"맑은 고딕", 30.f );
	m_pShowMeatPoint->SetPosition(0.0f, 35.0f);
	AddChild( m_pShowMeatPoint , 20);

	//RemoveChild(tmp);
}

CPlayScene::~CPlayScene(void)
{
	SafeDelete(m_pPoliceCreator);
	CCharacterConfig::ReleaseInstance();
}

// init background
void CPlayScene::_initBackground( void )
{
	m_pBackground = CBackground::Create(); 
	AddChild( m_pBackground , 0);
	m_pHumanFarm = CHumanFarm::Create();
	AddChild( m_pHumanFarm , 1);
	m_pLightning = CLightning::Create();
	AddChild(m_pLightning, 2);

}

// init map
// 양쪽 base를 가져와 좀비 리스트 포돌이 리스트에 각각 추가함 - 성환
void CPlayScene::_initMap( void )
{	
	m_pMapCreator = CMapCreator::Create();
	AddChild( m_pMapCreator , 1);
	m_llistZombie.push_back( m_pMapCreator->GetZombieBase() );
	m_llistPolice.push_back( m_pMapCreator->GetPoliceBase() );
}


// init UI
void CPlayScene::_initUI( void )
{
	std::wstring buttonpath_normal[NUM_OF_UIBUTTON];
	std::wstring buttonpath_pressed[NUM_OF_UIBUTTON];

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
	std::wstring localmoneyImgPath = L"wugargar/UIbuttons/money_upgrade.jpg";
	


	m_pUIBackground = NNSprite::Create(L"wugargar/UIbuttons/UIBackground.jpg");
	m_pUIBackground->SetPosition(FIRST_X_COORDINATE_OF_UIBUTTON, FIRST_Y_COORDINATE_OF_UIBUTTON);
	AddChild( m_pUIBackground , 19);

	// zombie type을 사용하여 refactoring - 성환
	for (int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i) {
		m_pUIButtons[i] = CUIButton::Create(buttonpath_normal[i], buttonpath_pressed[i]);
		m_pUIButtons[i]->SetPosition( static_cast<float>(FIRST_X_COORDINATE_OF_UIBUTTON + GAP_BETWEEN_UIBUTTONS + ((i % (NUMBER_OF_ZOMBIE_TYPES/2))) * (GAP_BETWEEN_UIBUTTONS + SIZE_OF_UIBUTTON  )), 
			static_cast<float>(FIRST_Y_COORDINATE_OF_UIBUTTON + GAP_BETWEEN_UIBUTTONS_Y + (SIZE_OF_UIBUTTON + GAP_BETWEEN_UIBUTTONS_Y) * int(i*2/NUMBER_OF_ZOMBIE_TYPES)) );
		AddChild( m_pUIButtons[i] , 20);
	}
	m_pUIButtons[LOCALMONEY_UPGRADE] = CUIButton::Create(localmoneyImgPath, localmoneyImgPath);
	m_pUIButtons[LOCALMONEY_UPGRADE]->SetPosition( static_cast<float>(( FIRST_X_COORDINATE_OF_UIBUTTON + GAP_BETWEEN_UIBUTTONS ) + 4*(GAP_BETWEEN_UIBUTTONS + SIZE_OF_UIBUTTON  )), 
		static_cast<float>(FIRST_Y_COORDINATE_OF_UIBUTTON + GAP_BETWEEN_UIBUTTONS_Y) );
	AddChild( m_pUIButtons[LOCALMONEY_UPGRADE] , 20);
}


void CPlayScene::Render()
{
	NNObject::Render();
}
void CPlayScene::Update( float dTime )
{
	//종료조건처리.
	if (CheckGameOver()) {
		return ;
	}

	NNScene::Update(dTime);

	m_StageElapsedTime+=dTime;
	if (m_StageElapsedTime - m_LocalMoneyTimeChecker >= m_pPlayer->GetEarningInterval()) {
		m_pPlayer->IncreaseLocalMoney(EARNING_AMOUNTS);
		m_LocalMoneyTimeChecker = m_StageElapsedTime;
	}
	
	//Test_ShowMousePosition(); // 마우스 커서 위치 임시 테스트
	Test_ShowFPS(); //FPS출력 임시 테스트
	Test_ShowLocalMoney(); // local money 출력

	// 좀비 생성 버튼 입력 처리를 한 함수로 빼버림 - 채원
	MakeZombieButtonOperate(dTime);

	DeadCharacterCollector();
	CollectDeadPoliceByClick();
	//기존 지정해놓은 파일 범위를 넘어갈때를 위한 처리. 임시.
	//MakePoliceFromScript();
	MakePoliceFromScriptWithTimeInterval(m_StageElapsedTime);
	// next stage 화면으로 이동하기 위한 임시 구문
	// 엔터 치면 이동함
// 	if( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_DOWN ) {
// 		NNSceneDirector::GetInstance()->ChangeScene(CNextStageScene::Create());
// 		m_pInstance = nullptr;
// 	}
}

void CPlayScene::MakeZombieButtonOperate(float dTime) // 아기 생성도 덧붙임
{
	// button1을 좌클릭했을 때 좀비 생성
	// 모든 종류의 좀비 생성을 처리함 - 채원

	// 코드 refactoring함. zombie type을 int처럼 사용하는데 이게 좀 걸림. - 성환
	// baby버튼 별도로 빠져잇던거 한 for문 안으로 삽입함.	
	int localMoney = m_pPlayer->GetLocalMoney();	
	int meatPoint = m_pPlayer->GetMeatPoint();
	float earningIntervalUpgradeCost = 50/(m_pPlayer->GetEarningInterval());

	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		for ( int i=0 ; i<NUM_OF_UIBUTTON ; ++i ) {
			if ( m_pUIButtons[i]->CheckButtonArea()) {
				if ( i == BABY_HUMAN && localMoney >= BABY_PRICE) 
				{
					m_pPlayer->SetLocalMoney(localMoney - BABY_PRICE);
					m_pHumanFarm->MakeHuman();				
					return ;
				}
				else if ( i == HERO_ZOMBIE_SM9 && meatPoint >= HERO_ZOMBIE_PRICE ) 
				{
					m_pPlayer->SetMeatPoint(meatPoint - HERO_ZOMBIE_PRICE );
					MakeZombie(static_cast<ZombieType>(i));
					return ;
				} 
				else if ( i == LOCALMONEY_UPGRADE && localMoney >= earningIntervalUpgradeCost ) {
					m_pPlayer->IncreaseEarningInterval();
					m_pPlayer->SetLocalMoney(localMoney - static_cast<int>(earningIntervalUpgradeCost));
					earningIntervalUpgradeCost = 2 * earningIntervalUpgradeCost;
					return ;
				}

				else if( i != BABY_HUMAN && i != HERO_ZOMBIE_SM9 && i != LOCALMONEY_UPGRADE )
				{
					int cost = (CCharacterConfig::GetInstance())->GetCharacterInfo(ZOMBIE)[i].CreationCost;
					if( localMoney >= cost ) {
						m_pPlayer->SetLocalMoney( localMoney - cost);		
						MakeZombie(static_cast<ZombieType>(i));										
					}
				}
			}
		}
	}
}

void CPlayScene::MakeZombie( ZombieType type, NNPoint* position )
{
	CZombie *tmpZombieObject = nullptr;

	tmpZombieObject = CZombie::Create();
	tmpZombieObject->initStatus(CCharacterConfig::GetInstance()->GetCharacterInfo(ZOMBIE), static_cast<int>(type));
	
	if (position == nullptr ) {
		tmpZombieObject->SetRandomPositionAroundBase();
	} else {
		tmpZombieObject->SetPosition(*position);
	}
	
	AddChild( tmpZombieObject );	
	m_llistZombie.push_back(tmpZombieObject);

	// when player has not enough money
// 	if (localMoney < cost || (CheckHero && m_pPlayer->GetMeatPoint() < 100) ) {
// 		SafeDelete(tmpZombieObject);
// 		return;
// 	}
// 	else if(CheckHero && m_pPlayer->GetMeatPoint() >= 100)
// 		m_pPlayer->SetMeatPoint(m_pPlayer->GetMeatPoint()-100);// 영웅좀비 meat point 감소

	// when position is nullptr, set position around zombie base
	

	
	

}



void CPlayScene::MakeZombie(ZombieType type)
{
	MakeZombie(type, nullptr);	
}



void CPlayScene::MakePoliceFromScript()
{
	PoliceType create_enemy_type;
	create_enemy_type =	m_pPoliceCreator->ReturnCreateEnemyInfo();
	if(create_enemy_type != NONE_POLICE){
		CPolice *tmpPoliceObject = CPolice::Create();
		tmpPoliceObject->initStatus(CCharacterConfig::GetInstance()->GetCharacterInfo(POLICE), create_enemy_type);
		bool is_not_time = false;
		tmpPoliceObject->SetRandomPositionAroundBase();
		tmpPoliceObject->InitSprite( tmpPoliceObject->GetSpritepath() );
		AddChild(tmpPoliceObject, 10);
		m_llistPolice.push_back(tmpPoliceObject);
	}	
}


void CPlayScene::MakePoliceFromScriptWithTimeInterval( float stageElapsedTime )
{
	CPolice *tmpPoliceObject = m_pPoliceCreator->CreatePoliceOnTime(stageElapsedTime);
	if ( tmpPoliceObject == nullptr) {
		return ;
	}

	tmpPoliceObject->SetRandomPositionAroundBase();
	AddChild(tmpPoliceObject, 10);
	m_llistPolice.push_back(tmpPoliceObject);

}



// 죽은 캐릭터 수집기,
// update시마다 실행되면서 hp가 0이거나 화면밖으로 나간 캐릭터를 삭제함
void CPlayScene::DeadCharacterCollector()
{	
	for ( auto& iter = m_llistPolice.begin() ; iter != m_llistPolice.end() ; iter++ ) {
		if(( (*iter)->GetHP()<= 0 ) || ((*iter)->GetPositionX() < GAME_SCREEN_MIN_SIZE_X)){
			CCharacter *tmpCharacter;
			tmpCharacter = *iter;
			m_llistPolice.erase(iter);
			NNPoint DeadPosition = tmpCharacter->GetPosition();
			RemoveChild(tmpCharacter,true);

			// 죽은 경찰이 있을때마다 player의 죽인 경찰 수를 증가.
			m_pPlayer->IncreaseNumberOfKillInStage();	


			// dead police 추가하는 부분?
			CDeadPolice *tmpDeadPolice = CDeadPolice::Create(); 
			tmpDeadPolice->SetDeadPosition(DeadPosition);
			AddChild(tmpDeadPolice,10);
			m_llistDeadPolice.push_back(tmpDeadPolice);


			break;
		}
	}

	for ( auto& iter = m_llistZombie.begin() ; iter != m_llistZombie.end() ; iter++ ) {
		if(( (*iter)->GetHP()<= 0 ) || ((*iter)->GetPositionX() > GAME_SCREEN_MAX_SIZE_X)){
			CCharacter *tmpCharacter;
			tmpCharacter = *iter;
		//	tmpCharacter->GetDeadAnimation()->SetVisible(true);
			m_llistZombie.erase(iter);
			RemoveChild(tmpCharacter,true);
			
			// 죽은 좀비가 있을때마다 player의 잃은 좀비 수를 증가.
			m_pPlayer->IncreaseNumberOfLossInStage();	
			break;
		}
	}
}


void CPlayScene::CollectDeadPoliceByClick()
{
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_UP ) {
		NNPoint cursorPosition = NNInputSystem::GetInstance()->GetMousePosition();
		for ( auto& iter = m_llistDeadPolice.begin() ; iter != m_llistDeadPolice.end() ; iter++ )
		{
			bool isInXCoordRange = (static_cast<CDeadPolice*>(*iter)->GetDeadPosition().GetX() < cursorPosition.GetX()) && ( ( static_cast<CDeadPolice*>(*iter)->GetDeadPosition().GetX() + DEAD_POLICE_IMAGE_WIDTH ) > cursorPosition.GetX() );
			bool isInYCoordRange = (static_cast<CDeadPolice*>(*iter)->GetDeadPosition().GetY() < cursorPosition.GetY()) && ( ( static_cast<CDeadPolice*>(*iter)->GetDeadPosition().GetY() + DEAD_POLICE_IMAGE_HEIGHT ) > cursorPosition.GetY() );
			if(isInXCoordRange && isInYCoordRange)
			{
				// 감염확률에 따라 감염된 포돌이 생성, 기본은 POOR_ZOMBIE로, 
				if ( rand()% 100 <= m_pPlayer->GetInfectionRate()) {
					NNPoint deadPosition = static_cast<CDeadPolice*>(*iter)->GetDeadPosition();
					MakeZombie(POOR_ZOMBIE, &deadPosition );
				}

				CCharacter *tmp = *iter;
				m_llistDeadPolice.erase(iter);
				RemoveChild(tmp,true);
				
				m_pPlayer->SetMeatPoint(m_pPlayer->GetMeatPoint() + 10);
				m_pPlayer->IncreaseLocalMoney(100);
				break;
			}
		}
	}
}

/*
정인호. 11/14
현재 Base의 상황을 체크하여 게임 종료 여부를 체크.
불타입으로 변경, 스테이지 관련 부분 구현 후 내용추가할 필요가 있어보임
*/
bool CPlayScene::CheckGameOver()
{
	if (m_pPlayer->GetPlayerStatus() == PLAYER_ON_PLAYING ) {
		if(m_pMapCreator->GetPoliceBase()->GetHP() <= 0) {
			m_pPlayer->SetPlayerStatus(PLAYER_WIN);
			if (m_pPlayer->GetClearedStage() == m_pPlayer->GetPlayingStage() )
			{
				m_pPlayer->IncreaseClearedStage();
			}
			m_pPlayer->ReadyToSave();
			SaveGame();
			ShowResult(L"WIN");			
			printf_s("WIN!\n");
		} else if(m_pMapCreator->GetZombieBase()->GetHP() <= 0) {
			m_pPlayer->SetPlayerStatus(PLAYER_LOSE);
			m_pPlayer->ReadyToSave();
			SaveGame();
			ShowResult(L"LOSE");
			printf_s("LOSE!\n");
		} else {
			return false;	
		}
	} 
	else  // when the game is over
	{
		if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) && m_pResultOKButton->CheckButtonArea() ) 
		{
			NNSceneDirector::GetInstance()->ChangeScene(CStageSelectScene::Create());
			m_pInstance = nullptr;		
		}
	}
	
	return true;
}


void CPlayScene::ShowResult( std::wstring result )
{
	// result background image
	m_pResultImage = NNSprite::Create(L"wugargar/result.png");
	float resultPositionX = GAME_SCREEN_MAX_SIZE_X/2.0f - m_pResultImage->GetImageWidth()/2.0f;
	float resultPositionY = GAME_SCREEN_MAX_SIZE_Y/5.0f;
	m_pResultImage->SetPosition(resultPositionX, resultPositionY);
	AddChild(m_pResultImage,10000);

	// set label
	swprintf_s(
		m_aResultBuffer, 
		_countof(m_aResultBuffer), 
		L"Results : %s\n\nGlobalMoney : %d \nTotal Kill : %d \nTotal Loss : %d \nStage Kill : %d \nStage Loss : %d \n", 
		result.c_str(),
		m_pPlayer->GetGlobalMoney(),
		m_pPlayer->GetTotalKill(),
		m_pPlayer->GetTotalLoss(),
		m_pPlayer->GetNumberOfKillInStage(), 
		m_pPlayer->GetNumberOfLossInStage() );
	m_pResultLabel = NNLabel::Create(m_aResultBuffer, L"맑은 고딕", 15.0f);
	m_pResultLabel->SetPosition(resultPositionX+50, resultPositionY+30);
	AddChild(m_pResultLabel, 10001);

	// set ok button
	m_pResultOKButton = CUIButton::Create(L"wugargar/ok.png", L"wugargar/ok.png");
	m_pResultOKButton->SetPosition(GAME_SCREEN_MAX_SIZE_X/2.0f - 20, GAME_SCREEN_MAX_SIZE_Y/2.0f);
	AddChild(m_pResultOKButton, 10001);
}

void CPlayScene::SaveGame( void )
{
	// set root using player name
	std::string root = m_pPlayer->GetPlayerName();

	// set root
	m_SaveManager = CXMLWriter::Create("savegame.sav");
	m_SaveManager->AddRoot(m_pPlayer->GetPlayerName());

	// write contents
	m_SaveManager->AddNode("GlobalMoney", root);
	m_SaveManager->AddText(std::to_string(m_pPlayer->GetGlobalMoney() ), "GlobalMoney" );
	m_SaveManager->AddNode("TotalKill", root);
	m_SaveManager->AddText(std::to_string(m_pPlayer->GetTotalKill() ), "TotalKill");
	m_SaveManager->AddNode("TotalLoss", root);
	m_SaveManager->AddText(std::to_string(m_pPlayer->GetTotalLoss() ), "TotalLoss");
	m_SaveManager->AddNode("CurrentStage", root);
	m_SaveManager->AddText(std::to_string(m_pPlayer->GetClearedStage() ), "CurrentStage");
	m_SaveManager->AddNode("InfectionRate", root);
	m_SaveManager->AddText(std::to_string(m_pPlayer->GetInfectionRate() ), "InfectionRate");

	m_SaveManager->AddNode("UnitLevel", root);
	for ( int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i) {
		std::string nodeName = "UnitNo";
		nodeName.append(std::to_string(i));
		m_SaveManager->AddNode(nodeName, "UnitLevel");
		m_SaveManager->AddText(std::to_string(m_pPlayer->GetZombieLevel(static_cast<ZombieType>(i))), nodeName );
	}

	m_SaveManager->ExportXMLFile();
	SafeDelete(m_SaveManager);
}

/////////////////////////////////////////////////////////
///////////////////test �Լ� /////////////////////////////
void CPlayScene::Test_ShowMousePosition()
{
	// 마우스 포지션을 가져오기 위한 임시 구문	
	// wsprintf가 float형을 사용할 수 없어 임시방편으로 사용중
	//	 	POINT pt;
	//	 	GetCursorPos(&pt);
	//	 	ScreenToClient( NNApplication::GetInstance()->GetHWND(), &pt);	 

	//	 	ZeroMemory(temp, 256);	
	//	 	wsprintf(temp, L"windowcoord x : %4d y : %4d", pt.x, pt.y  );
	//	 	m_pShowMouseStatus->SetString(temp);
	// 마우스 포지션용 끝 
}

void CPlayScene::Test_ShowFPS()
{
	// fps 출력용 임시
	ZeroMemory(temp, 256);	
	swprintf_s(temp, _countof(temp), L"FPS = %0.3f", NNApplication::GetInstance()->GetFPS() );
	m_pShowMouseStatus->SetString(temp);
}


void CPlayScene::Test_ShowLocalMoney()
{
	//로컬머니 임시 출력 코드
	ZeroMemory(localmoney, 256);	
	swprintf_s(localmoney, _countof(localmoney), L"local money = %d", m_pPlayer->GetLocalMoney() );
	m_pShowMeatPoint->SetString(localmoney);
}


void CPlayScene::loadCharacterInfo()
{
	CCharacterConfig *pCharacterConfig = CCharacterConfig::GetInstance();
	m_PoliceXML = NNResourceManager::GetInstance()->LoadXMLFromFIle("XML/Character/PoliceInfo.txt");
	m_ZombieXML = NNResourceManager::GetInstance()->LoadXMLFromFIle("XML/Character/ZombieInfo.txt");
		
	if(!(m_PoliceXML->GetLoadSuccess() && m_ZombieXML->GetLoadSuccess() ) )
	{
		printf_s("Character Information XML Load Fail!\n");
		return;
	}
	pCharacterConfig->InitCharacterInfo(m_ZombieXML, ZOMBIE);
	pCharacterConfig->InitCharacterInfo(m_PoliceXML, POLICE);
}

void CPlayScene::initLoading()
{
	tmp = NNSprite::Create(L"wugargar/Loading/Loading1.jpg");
	 
	tmp->SetPosition(0,0);
	AddChild(tmp);
	//m_pLoadingAnimation = NNAnimation::Create();
	//for(int i=0; i<6; ++i)
	//{
	//	wchar_t temp[256] = {0, };
	//	swprintf_s(temp, _countof(temp), L"wugargar/Loading/Loading %d.jpg",i+1);
	//	m_pLoadingAnimation->AddSpriteNode(temp);
	//}

	//m_pLoadingAnimation->SetFrameTimeInSection(0.05f, 0, 5);
	//AddChild(m_pLoadingAnimation);
	//m_pLoadingAnimation->SetPosition(0,0);

}
