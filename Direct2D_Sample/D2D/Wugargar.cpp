#include "Wugargar.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include <tchar.h>

CWugargar::CWugargar(void)
{
	m_PoorZombie = NULL;
	m_Background = CBackground::Create();
	m_ZombieBase = CZombieBase::Create();
	m_UIButton1 = CUIButton::Create();
	m_UIButton1->SetPosition(20.0f, 500.0f);
	//m_UIButton1->SetScale(220.0f, 220.0f);

	m_ShowMouseStatus = NNLabel::Create( L"cursor position", L"¸¼Àº °íµñ", 35.f );
	m_ShowMouseStatus->SetPosition(0.0f, 0.0f);
	
	AddChild( m_Background );
	AddChild( m_ZombieBase );
	AddChild( m_ShowMouseStatus );
	AddChild( m_UIButton1 );
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
	ZeroMemory(temp, 256);
	m_CursorPos = NNInputSystem::GetInstance()->GetMousePosition();
		
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient( NNApplication::GetInstance()->GetHWND(), &pt);

	POINT pt2;
	pt2.x = m_UIButton1->GetPositionX();
  	pt2.y = m_UIButton1->GetPositionY();
	
	wsprintf(temp, L"image coord x : %4d y : %4d\nwindowcoord x : %4d y : %4d", pt2.x, pt2.y, pt.x, pt.y  );
	m_ShowMouseStatus->SetString(temp);

	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN ) {	
		if ( m_UIButton1->CheckButtonArea() ) {
			if ( m_PoorZombie != NULL) {			
				RemoveChild( m_PoorZombie, true);
			}		
			m_PoorZombie = CPoorZombie::Create();
			AddChild( m_PoorZombie );
		}		
	}

	

	if( m_PoorZombie != NULL ) {
		m_PoorZombie->SetPosition( m_PoorZombie->GetPosition() + NNPoint(-10.0f, 0.0f) * dTime );
	}

}

