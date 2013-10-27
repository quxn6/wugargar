
#include "CustomObject.h"
#include "NNInputSystem.h"

CustomObject::CustomObject()
{
	m_Sprite = NNSprite::Create( L"Sprite/CustomObjectExmaple/sprite.png" );
	m_Sprite->SetPosition( 0.f, 40.f );
	AddChild( m_Sprite );

	m_Label = NNLabel::Create( L"¿ì¸®´Â ÇÑ ¸ö!", L"±Ã¼­Ã¼", 40.f );
	AddChild( m_Label );
}
CustomObject::~CustomObject()
{

}

void CustomObject::Render()
{
	NNObject::Render();
}

void CustomObject::Update( float dTime )
{

}