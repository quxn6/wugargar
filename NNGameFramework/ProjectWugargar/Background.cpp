#include "Background.h"


CBackground::CBackground(void)
{
	m_pBackgroundImage = NNSprite::Create( L"wugargar/background.jpg");
	m_pBackgroundImage->SetPosition(0.0f, 0.0f);
	AddChild( m_pBackgroundImage );
}


CBackground::~CBackground(void)
{
}

void CBackground::Render()
{
	NNObject::Render();
}

void CBackground::Update( float dTime )
{

}
