#include "Wugargar.h"
#include "NNPoint.h"
#include "NNInputSystem.h"


CWugargar::CWugargar(void)
{
	m_PoorZombie = NULL;
	m_Background = CBackground::Create();
	m_ZombieBase = CZombieBase::Create();
	

	AddChild( m_Background );
	AddChild( m_ZombieBase );
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
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN ) {	
		SafeDelete(m_PoorZombie);
		m_PoorZombie = CPoorZombie::Create();
		AddChild( m_PoorZombie );
	}

	if( m_PoorZombie != NULL ) {
		m_PoorZombie->SetPosition( m_PoorZombie->GetPosition() + NNPoint(-10.0f, 0.0f) * dTime );
	}

}

