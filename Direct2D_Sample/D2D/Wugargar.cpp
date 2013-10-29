#include "Wugargar.h"
#include "NNPoint.h"
#include "NNInputSystem.h"
#include "NNLabel.h"

CWugargar::CWugargar(void)
{
	m_PoorZombie = NULL;
	m_Background = CBackground::Create();
	m_ZombieBase = CZombieBase::Create();

	m_ShowMouseStatus = NNLabel::Create( L"cursor position", L"¸¼Àº °íµñ", 35.f );
	m_ShowMouseStatus->SetPosition(0.0f, 0.0f);

	AddChild( m_Background );
	AddChild( m_ZombieBase );
	AddChild( m_ShowMouseStatus );
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
	m_CursorPos = NNInputSystem::GetInstance()->GetCurrentCursorPosition();
	
	wsprintf(temp, L"x : %d y : %d", m_CursorPos.x, m_CursorPos.y);
	m_ShowMouseStatus->SetString(temp);
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN ) {	
		SafeDelete(m_PoorZombie);
		m_PoorZombie = CPoorZombie::Create();
		AddChild( m_PoorZombie );
	}

	if( m_PoorZombie != NULL ) {
		m_PoorZombie->SetPosition( m_PoorZombie->GetPosition() + NNPoint(-10.0f, 0.0f) * dTime );
	}

}

