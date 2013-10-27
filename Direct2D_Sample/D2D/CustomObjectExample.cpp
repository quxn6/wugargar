
#include "CustomObjectExample.h"
#include "NNInputSystem.h"

CustomObjectExample::CustomObjectExample()
{
	m_CustomObject = CustomObject::Create();
	AddChild( m_CustomObject );
}
CustomObjectExample::~CustomObjectExample()
{

}

void CustomObjectExample::Render()
{
	NNObject::Render();
}
void CustomObjectExample::Update( float dTime )
{
	
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_LEFT ) == KEY_PRESSED )
	{
		m_CustomObject->SetPosition( m_CustomObject->GetPosition() + NNPoint(-100.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_RIGHT ) == KEY_PRESSED )
	{
		m_CustomObject->SetPosition( m_CustomObject->GetPosition() + NNPoint(100.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_UP ) == KEY_PRESSED )
	{
		m_CustomObject->SetPosition( m_CustomObject->GetPosition() + NNPoint(0.f,-100.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_DOWN ) == KEY_PRESSED )
	{
		m_CustomObject->SetPosition( m_CustomObject->GetPosition() + NNPoint(0.f,100.f) * dTime );
	}
	
}