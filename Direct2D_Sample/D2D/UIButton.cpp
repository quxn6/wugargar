#include "UIButton.h"
#include "NNInputSystem.h"


CUIButton::CUIButton(void)
{
	m_pPressedImage = NNSprite::Create(L"wugargar/UIbuttons/button_pressed_poorZombie.png");
	m_pNormalImage = NNSprite::Create(L"wugargar/UIbuttons/button_normal_poorZombie.png");
	m_pPressedImage->SetPosition(m_Position.GetX(), m_Position.GetY());
	m_pNormalImage->SetPosition(m_Position.GetX(), m_Position.GetY());

//	m_pNormalImage->SetVisible(false);

	AddChild( m_pPressedImage);
	AddChild( m_pNormalImage);

}


CUIButton::~CUIButton(void)
{
}

void CUIButton::Render()
{
	NNObject::Render();
}

void CUIButton::Update( float dTime )
{

}

bool CUIButton::CheckButtonArea( void )
{
	NNPoint cursorPosition = NNInputSystem::GetInstance()->GetMousePosition();
	bool isInXCoordRange = (m_Position.GetX() < cursorPosition.GetX()) && ( ( m_Position.GetX() + m_pNormalImage->GetImageWidth() ) > cursorPosition.GetX() );
	bool isInYCoordRange = (m_Position.GetY() < cursorPosition.GetY()) && ( ( m_Position.GetY() + m_pNormalImage->GetImageHeight() ) > cursorPosition.GetY() );

	m_pNormalImage->SetVisible(false);

	// visible이 false가 되도 이미지가 계속 나오는 문제가 있음
	if ( isInXCoordRange && isInYCoordRange ) {
		m_pNormalImage->SetVisible(false);
	//	m_pPressedImage->SetVisible(false);
// 		
// 		if (NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_NOTPRESSED ) {
// 			m_pNormalImage->SetVisible(true);
// 			m_pPressedImage->SetVisible(false);
// 		}
		return true;
	}
	
	return false;
}
