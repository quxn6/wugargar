#include "Wugargar.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNLabel.h"
#include "NNApplication.h"
#include <tchar.h>
#include <time.h>

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
	m_Background = CBackground::Create(); 
	m_ZombieBase = CZombieBase::Create();
	m_UIButton1 = CUIButton::Create();
	m_UIButton1->SetPosition(20.0f, 500.0f);

	m_ShowMouseStatus = NNLabel::Create( L"cursor position", L"맑은 고딕", 35.f );
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
			CZombie *tmp_zombie = CPoorZombie::Create();
			AddChild( tmp_zombie );
			m_llistZombie.push_back(tmp_zombie);
		}		
	}

	for ( auto& iter = m_llistZombie.begin() ; iter != m_llistZombie.end() ; iter++ ) {
		(*iter)->SetPosition((*iter)->GetPosition() + NNPoint( (-5.0f), 0.0f) * dTime );
	}
	
}

