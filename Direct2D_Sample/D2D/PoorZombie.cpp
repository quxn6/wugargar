#include "PoorZombie.h"


CPoorZombie::CPoorZombie(void)
{
	m_PoorZombie = NNSprite::Create( L"wugargar/poor_zombie.png");
	m_PoorZombie->SetPosition(1000.0f, 400.0f);
	AddChild( m_PoorZombie );
}


CPoorZombie::~CPoorZombie(void)
{

}

void CPoorZombie::Render()
{
	NNObject::Render();
}

void CPoorZombie::Update( float dTime )
{

}
