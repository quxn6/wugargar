#include "Wugargar.h"
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

CWugargar* CWugargar::m_pInstance = nullptr;

CWugargar* CWugargar::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new CWugargar();
	}

	return m_pInstance;
}

void CWugargar::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

CWugargar::CWugargar(void)
{	
	_initBackground();
	_initMap();
	_initUI();

	// temporary
	m_pShowMouseStatus = NNLabel::Create( L"cursor position", L"맑은 고딕", 35.f );
	m_pShowMouseStatus->SetPosition(0.0f, 0.0f);
	AddChild( m_pShowMouseStatus , 20);

	m_pCreatePolice = CCreatePolice::Create();
	AddChild(m_pCreatePolice, 21);


}

CWugargar::~CWugargar(void)
{

}

// init background
void CWugargar::_initBackground( void )
{
	m_pBackground = CBackground::Create(); 
	AddChild( m_pBackground , 0);
}

// init map
void CWugargar::_initMap( void )
{	
	m_pMapCreator = CMapCreator::Create();
	AddChild( m_pMapCreator , 1);
}


// init UI
void CWugargar::_initUI( void )
{
	std::wstring buttonpath_normal_poorZombie = L"wugargar/UIbuttons/button_normal_poorZombie.png";
	std::wstring buttonpath_pressed_poorZombie = L"wugargar/UIbuttons/button_pressed_poorZombie.png";
	std::wstring buttonpath_normal_vomitZombie = L"wugargar/UIbuttons/button_normal_vomitZombie.png";
	std::wstring buttonpath_pressed_vomitZombie = L"wugargar/UIbuttons/button_pressed_vomitZombie.png";
	std::wstring buttonpath_normal_muscleZombie = L"wugargar/UIbuttons/button_normal_muscleZombie.png";
	std::wstring buttonpath_pressed_muscleZombie = L"wugargar/UIbuttons/button_pressed_muscleZombie.png";
	std::wstring buttonpath_normal_kamikazeZombie = L"wugargar/UIbuttons/button_normal_kamikazeZombie.png";
	std::wstring buttonpath_pressed_kamikazeZombie = L"wugargar/UIbuttons/button_pressed_kamikazeZombie.png";
	std::wstring buttonpath_normal_smogZombie = L"wugargar/UIbuttons/button_normal_smogZombie.png";
	std::wstring buttonpath_pressed_smogZombie = L"wugargar/UIbuttons/button_pressed_smogZombie.png";
	std::wstring buttonpath_normal_iceZombie = L"wugargar/UIbuttons/button_normal_iceZombie.png";
	std::wstring buttonpath_pressed_iceZombie = L"wugargar/UIbuttons/button_pressed_iceZombie.png";

	m_pUIBackground = NNSprite::Create(L"wugargar/UIbuttons/UIBackground.jpg");
	m_pUIBackground->SetPosition(0.0f, 520.0f);

	m_pUIButton1 = CUIButton::Create(buttonpath_normal_poorZombie, buttonpath_pressed_poorZombie);
	m_pUIButton1->SetPosition(15.0f, 550.0f);
	m_pUIButton2 = CUIButton::Create(buttonpath_normal_vomitZombie, buttonpath_pressed_vomitZombie);
	m_pUIButton2->SetPosition(180.0f, 550.0f);
	m_pUIButton3 = CUIButton::Create(buttonpath_normal_muscleZombie, buttonpath_pressed_muscleZombie);
	m_pUIButton3->SetPosition(345.0f, 550.0f);
	m_pUIButton4 = CUIButton::Create(buttonpath_normal_kamikazeZombie, buttonpath_pressed_kamikazeZombie);
	m_pUIButton4->SetPosition(510.0f, 550.0f);
	m_pUIButton5 = CUIButton::Create(buttonpath_normal_smogZombie, buttonpath_pressed_smogZombie);
	m_pUIButton5->SetPosition(675.0f, 550.0f);
	m_pUIButton6 = CUIButton::Create(buttonpath_normal_iceZombie, buttonpath_pressed_iceZombie);
	m_pUIButton6->SetPosition(840.0f, 550.0f);

	AddChild( m_pUIBackground , 19);
	AddChild( m_pUIButton1 , 20);
	AddChild( m_pUIButton2 , 20);
	AddChild( m_pUIButton3 , 20);
	AddChild( m_pUIButton4 , 20);
	AddChild( m_pUIButton5 , 20);
	AddChild( m_pUIButton6 , 20);
}


void CWugargar::Render()
{
	NNObject::Render();
}

void CWugargar::Update( float dTime )
{
	//Test_ShowMousePosition(); // 마우스 커서 위치 임시 테스트
	Test_ShowFPS(); //FPS출력 임시 테스트


	// 좀비 생성 버튼 입력 처리를 한 함수로 빼버림 - 채원
	MakeZombieButtonOperate(dTime);


	m_pCreatePolice->CreateEnemy();
}

void CWugargar::MakeZombie(ZombieType type)
{
	CZombie *tmpZombieObject = nullptr;
	std::wstring imagePath[6];

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
	AddChild( tmpZombieObject , 10 );

	// insert into zombie list
	m_llistZombie.push_back(tmpZombieObject);
}

void CWugargar::MakeCharacterWalk(float dTime)
{
	for ( auto& iter = m_llistPolice.begin() ; iter != m_llistPolice.end() ; iter++ ) {
		(*iter)->SetPosition((*iter)->GetPosition() + NNPoint( ((*iter)->GetMovingSpeed()), 0.0f) * dTime);
	}


	for ( auto& iter = m_llistZombie.begin() ; iter != m_llistZombie.end() ; iter++ ) {
		(*iter)->SetPosition((*iter)->GetPosition() + NNPoint( ((*iter)->GetMovingSpeed()), 0.0f) * dTime);
	}
}

void CWugargar::MakeZombieButtonOperate(float dTime)
{
	// button1을 좌클릭했을 때 좀비 생성
	// 모든 종류의 좀비 생성을 처리함 -채원
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		if ( m_pUIButton1->CheckButtonArea() ) {			
			MakeZombie(POOR_ZOMBIE);// 좀비 생성
		}	
	}
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		if ( m_pUIButton2->CheckButtonArea() ) {			
			MakeZombie(VOMIT_ZOMBIE);// 좀비 생성
		}	
	}
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		if ( m_pUIButton3->CheckButtonArea() ) {			
			MakeZombie(MUSCLE_ZOMBIE);// 좀비 생성
		}	
	}
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		if ( m_pUIButton4->CheckButtonArea() ) {			
			MakeZombie(KAMIKAJE_ZOMBIE);// 좀비 생성
		}	
	}
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		if ( m_pUIButton5->CheckButtonArea() ) {			
			MakeZombie(SMOG_ZOMBIE);// 좀비 생성
		}
	}
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) ) {	
		if ( m_pUIButton6->CheckButtonArea() ) {			
			MakeZombie(ICE_ZOMBIE);// 좀비 생성
		}	
	}

	MakeCharacterWalk(dTime);// 생성된 좀비 이동
}

/////////////////////////////////////////////////////////
///////////////////test 함수 /////////////////////////////
void CWugargar::Test_ShowMousePosition()
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

void CWugargar::Test_ShowFPS()
{
	// fps 출력용 임시
	ZeroMemory(temp, 256);	
	swprintf_s(temp, _countof(temp), L"FPS = %0.3f", NNApplication::GetInstance()->GetFPS() );
	m_pShowMouseStatus->SetString(temp);
	// fps 출력용 끝
}
