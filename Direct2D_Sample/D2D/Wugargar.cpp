#include "Wugargar.h"
#include "NNPoint.h"


CWugargar::CWugargar(void)
{
	m_Background = CBackground::Create();
	m_ZombieBase = CZombieBase::Create();
	m_PoorZombie = CPoorZombie::Create();

	AddChild( m_Background );
	AddChild( m_ZombieBase );
	AddChild( m_PoorZombie );
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
	m_PoorZombie->SetPosition( m_PoorZombie->GetPosition() + NNPoint(-10.0f, 0.0f) * dTime );
}

