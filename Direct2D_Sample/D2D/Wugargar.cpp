#include "Wugargar.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include <tchar.h>
#include <time.h>

CWugargar::CWugargar(void)
{
	m_Background = CBackground::Create();
	m_ZombieBase = CZombieBase::Create();
	m_UIButton1 = CUIButton::Create();
	m_UIButton1->SetPosition(20.0f, 500.0f);
//	m_character = CCharacter::Create();
	//m_UIButton1->SetScale(220.0f, 220.0f);

	m_ShowMouseStatus = NNLabel::Create( L"cursor position", L"맑은 고딕", 35.f );
	m_ShowMouseStatus->SetPosition(0.0f, 0.0f);
	
	AddChild( m_Background, 1);
	AddChild( m_ZombieBase, 2);
	AddChild( m_ShowMouseStatus ,10);
	AddChild( m_UIButton1 , 10);
}

CWugargar::~CWugargar(void)
{
}

void CWugargar::Render()
{
	NNObject::Render();
}

void CWugargar::Update( float dTime )
{		
	// 마우스 포지션을 가져오기 위한 임시 구문	
	// wsprintf가 float형을 사용할 수 없어 임시방편으로 사용중
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient( NNApplication::GetInstance()->GetHWND(), &pt);

	POINT pt2;
	pt2.x = (int)m_UIButton1->GetPositionX();
  	pt2.y = (int)m_UIButton1->GetPositionY();
	
	ZeroMemory(temp, 256);	
	wsprintf(temp, L"image coord x : %4d y : %4d\nwindowcoord x : %4d y : %4d", pt2.x, pt2.y, pt.x, pt.y  );
	m_ShowMouseStatus->SetString(temp);
	// 마우스 포지션용 끝 

	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN ) {	
		if ( m_UIButton1->CheckButtonArea() ) {

			// 좀비 객체를 가리키는 포인터가 하나밖에 없다.
		
			AddChild( CPoorZombie::Create(), 3);
		}		
	//	SetPosition( m_PoorZombie->GetPosition() + NNPoint(-5.0f, 0.0f) * dTime );// 좀비 객체에 이동로직 다시만들기
	}

}

