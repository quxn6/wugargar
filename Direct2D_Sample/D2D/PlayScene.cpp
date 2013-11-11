#include "PlayScene.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include <tchar.h>
#include <time.h>
#include "IceZombie.h"
#include "VomitZombie.h"
#include "SmogZombie.h"
#include "MuscleZombie.h"
#include "KamikazeZombie.h"
#include "PrintConsole.h"
#include "NormalPolice.h"
#include "Player.h"

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
	_initBackground();
	_initMap();
	_initUI();
	CPrintConsole* print_console = new CPrintConsole;

	// temporary
	m_pShowMouseStatus = NNLabel::Create( L"cursor position", L"맑은 고딕", 35.f );
	m_pShowMouseStatus->SetPosition(0.0f, 0.0f);
	AddChild( m_pShowMouseStatus , 20);

	m_pCreatePolice = new CCreatePolice;


}

CPlayScene::~CPlayScene(void)
{

}

// init background
void CPlayScene::_initBackground( void )
{
	m_pBackground = CBackground::Create(); 
	AddChild( m_pBackground , 0);
}

// init map
void CPlayScene::_initMap( void )
{	
	m_pMapCreator = CMapCreator::Create();
	AddChild( m_pMapCreator , 1);
}


// init UI
void CPlayScene::_initUI( void )
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

	m_pUIBackground = NNSprite::Create(L"wugargar/UIbuttons/UIBackground.jpg");
	m_pUIBackground->SetPosition(0.0f, FIRST_Y_COORDINATE_OF_UIBUTTON);
	AddChild( m_pUIBackground , 19);

	// zombie type을 사용하여 refactoring - 성환
	for (int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i) {
		m_pUIMakeZombieButton[i] = CUIButton::Create(buttonpath_normal[i], buttonpath_pressed[i]);
		m_pUIMakeZombieButton[i]->SetPosition(static_cast<float>(GAP_BETWEEN_UIBUTTONS + i*(GAP_BETWEEN_UIBUTTONS+SIZE_OF_UIBUTTONS) ), static_cast<float>(FIRST_Y_COORDINATE_OF_UIBUTTON + 30) );
		AddChild( m_pUIMakeZombieButton[i] , 20);
	}
}


void CPlayScene::Render()
{
	NNObject::Render();
}

void CPlayScene::Update( float dTime )
{
	//Test_ShowMousePosition(); // 마우스 커서 위치 임시 테스트
	Test_ShowFPS(); //FPS출력 임시 테스트

	// 좀비 생성 버튼 입력 처리를 한 함수로 빼버림 - 채원
	MakeZombieButtonOperate(dTime);

	// 생성된 좀비 이동 
	// 버튼 입력처리 안에 있을 필요가 없는것 같아 update 함수로 뺌 - 성환
	MakeCharacterWalk(dTime);

	KillCharacter();

	//기존 지정해놓은 파일 범위를 넘어갈때를 위한 처리. 임시.
	if(m_pCreatePolice->table_top_index < 4) {
		MakePoliceByFile();
	}
}

void CPlayScene::MakeZombieButtonOperate(float dTime)
{
	// button1을 좌클릭했을 때 좀비 생성
	// 모든 종류의 좀비 생성을 처리함 -채원

	// 코드 refactoring함. zombie type을 int처럼 사용하는데 이게 좀 걸림. - 성환
	for ( int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i ) {
		if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
			if ( m_pUIMakeZombieButton[i]->CheckButtonArea() ) {			
				MakeZombie(static_cast<ZombieType>(i));// 좀비 생성
			}		
		}
	}
}


void CPlayScene::MakeZombie(ZombieType type)
{
	CZombie *tmpZombieObject = nullptr;
	std::wstring imagePath[NUMBER_OF_ZOMBIE_TYPES];

	imagePath[POOR_ZOMBIE] = L"wugargar/poor_zombie.png";
	imagePath[ICE_ZOMBIE] = L"wugargar/ice_zombie.png";
	imagePath[VOMIT_ZOMBIE] = L"wugargar/vomit_zombie.png";
	imagePath[SMOG_ZOMBIE] = L"wugargar/smog_zombie.png";
	imagePath[MUSCLE_ZOMBIE] = L"wugargar/muscle_zombie.png";
	imagePath[KAMIKAJE_ZOMBIE] = L"wugargar/kamikaze_zombie.png";

	switch(type)
	{
	case POOR_ZOMBIE :
		tmpZombieObject = CPoorZombie::Create();
		break;
	case ICE_ZOMBIE :
		tmpZombieObject = CIceZombie::Create();
		break;
	case VOMIT_ZOMBIE :
		tmpZombieObject = CVomitZombie::Create();
		break;
	case SMOG_ZOMBIE :
		tmpZombieObject = CSmogZombie::Create();
		break;
	case MUSCLE_ZOMBIE :
		tmpZombieObject = CMuscleZombie::Create();
		break;
	case KAMIKAJE_ZOMBIE :
		tmpZombieObject = CKamikazeZombie::Create();
		break;
	default:
		break; // 클래스를 매개변수로 입력받아 깔끔하게 만들어 보려고 했으나 계속 실패해서 일단 하드코딩함
	}	

	tmpZombieObject->SetRandomPositionAroundBase();
	tmpZombieObject->InitSprite(imagePath[type]);
	// z_index설정시 y축 값이 클수록 앞에 배치하여 앞에 있는 캐릭터에 발밑에 표시되지 않게 함.
	// 나중에 추가로 수정할 필요가 있어보임, z_index도 한번 날 잡아서 #define으로 주는 것이 좋을 거같음.
	AddChild( tmpZombieObject , static_cast<int> (10 + tmpZombieObject->GetPositionY() / 10) );

	// insert into zombie list
	m_llistZombie.push_back(tmpZombieObject);
}


//11/11 정상 작동 확인
void CPlayScene::MakeCharacterWalk(float dTime)
{
	for ( auto& iter = m_llistPolice.begin() ; iter != m_llistPolice.end() ; iter++ ) {
		(*iter)->SetPosition((*iter)->GetPosition() - NNPoint( ((*iter)->GetMovingSpeed()), 0.0f) * dTime);
	}


	for ( auto& iter = m_llistZombie.begin() ; iter != m_llistZombie.end() ; iter++ ) {
		(*iter)->SetPosition((*iter)->GetPosition() + NNPoint( ((*iter)->GetMovingSpeed()), 0.0f) * dTime);
	}
}


void CPlayScene::MakePoliceByFile()
{
	enemyType create_enemy_type;
	CPolice *tmpPoliceObject = nullptr;
	create_enemy_type =	m_pCreatePolice->GetCreateEnemyInfo();
	std::wstring imagePath[5];
	imagePath[NORMAL_POLICE] = L"wugargar/normal_police.png";

	switch (create_enemy_type)
	{
	case NORMAL_POLICE:
		tmpPoliceObject = CNormalPolice::Create();
		break;
	case GUN_POLICE:
		break;
	case SHILD_POLICE:
		break;
	case HELLICOPTER:
		break;
	default:
		break;
	}

	if(create_enemy_type != NOT_TIME){
		tmpPoliceObject->SetRandomPositionAroundBase();
		tmpPoliceObject->InitSprite( imagePath[create_enemy_type]);
		AddChild(tmpPoliceObject, 10);
		m_llistPolice.push_back(tmpPoliceObject);

	}
	
}

void CPlayScene::KillCharacter()
{	
	for ( auto& iter = m_llistPolice.begin() ; iter != m_llistPolice.end() ; iter++ ) {
		if(( (*iter)->GetHP()<= 0 ) || ((*iter)->GetPositionX() < GAME_SCREEN_MIN_SIZE_X)){
			CCharacter *tmpCharacter;
			tmpCharacter = *iter;
			m_llistPolice.erase(iter);
			RemoveChild(tmpCharacter,true);
			break;
		}
	}

	for ( auto& iter = m_llistZombie.begin() ; iter != m_llistZombie.end() ; iter++ ) {
		if(( (*iter)->GetHP()<= 0 ) || ((*iter)->GetPositionX() > GAME_SCREEN_MAX_SIZE_X)){
			CCharacter *tmpCharacter;
			tmpCharacter = *iter;
			m_llistZombie.erase(iter);
			RemoveChild(tmpCharacter,true);
			break;
		}
	}
}

/////////////////////////////////////////////////////////
///////////////////test 함수 /////////////////////////////
void CPlayScene::Test_ShowMousePosition()
{
	// 마우스 포지션을 가져오기 위한 임시 구문	
	// wsprintf가 float형을 사용할 수 없어 임시방편으로 사용중
	 	POINT pt;
	 	GetCursorPos(&pt);
	 	ScreenToClient( NNApplication::GetInstance()->GetHWND(), &pt);
	 
	 	POINT pt2;
	 	pt2.x = (int)m_pUIButton1->GetPositionX();
	 	pt2.y = (int)m_pUIButton1->GetPositionY();
	 
	 	ZeroMemory(temp, 256);	
	 	wsprintf(temp, L"image coord x : %4d y : %4d\nwindowcoord x : %4d y : %4d", pt2.x, pt2.y, pt.x, pt.y  );
	 	m_pShowMouseStatus->SetString(temp);
	// 마우스 포지션용 끝 
}

void CPlayScene::Test_ShowFPS()
{
	// fps 출력용 임시
	ZeroMemory(temp, 256);	
	swprintf_s(temp, _countof(temp), L"FPS = %0.3f", NNApplication::GetInstance()->GetFPS() );
	m_pShowMouseStatus->SetString(temp);
	// fps 출력용 끝
}


