
#include "InputExample.h"
#include "NNInputSystem.h"

InputExample::InputExample()
	: DownCount(0),
	  PressedCount(0),
	  UpCount(0)
{
	m_Label = NNLabel::Create( L"엔터를 눌러보세요.", L"맑은 고딕", 35.f );
	AddChild( m_Label );

	m_Count = NNLabel::Create( L"Key down: 0\nKey pressed: 0\nKey up: 0", L"맑은 고딕", 35.f );
	m_Count->SetPosition( 0.f, 40.f );
	AddChild( m_Count );
}
InputExample::~InputExample()
{

}

void InputExample::Render()
{
	NNObject::Render();
}
void InputExample::Update( float dTime )
{
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_DOWN )
	{
		m_Label->SetString( L"KEY DOWN" );
		++DownCount;
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_PRESSED )
	{
		m_Label->SetString( L"KEY PRESSED" );
		++PressedCount;
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_UP )
	{
		m_Label->SetString( L"KEY UP" );
		++UpCount;
	}
	else
	{
		m_Label->SetString( L"엔터를 눌러보세요." );
	}

	wsprintf( temp, L"Key down: %d\nKey pressed: %d\nKey up: %d", DownCount, PressedCount, UpCount );
	m_Count->SetString( temp );
}