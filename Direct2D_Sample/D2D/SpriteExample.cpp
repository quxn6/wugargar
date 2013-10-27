
#include "SpriteExample.h"

SpriteExample::SpriteExample()
{
	m_Sprite = NNSprite::Create( L"Sprite/SpriteExample/sprite.png" );

	AddChild( m_Sprite );
}
SpriteExample::~SpriteExample()
{

}

void SpriteExample::Render()
{
	NNObject::Render();
}
void SpriteExample::Update( float dTime )
{
}