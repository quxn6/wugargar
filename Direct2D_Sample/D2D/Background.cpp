#include "Background.h"


CBackground::CBackground(void)
{
	m_BackgroundImage = NNSprite::Create( L"wugargar/background.jpg");
	m_BackgroundImage->SetPosition(0.0f, 0.0f);
	AddChild( m_BackgroundImage );
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
