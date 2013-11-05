#include "UIButton.h"
#include "NNInputSystem.h"


CUIButton::CUIButton(void)
{
	std::wstring defaultNormalImagePath = L"UIButton/button_default_normal.png";
	std::wstring defaultPressedImagePath = L"UIButton/button_default_pressed.png";
	CUIButton(defaultNormalImagePath, defaultPressedImagePath);
}

CUIButton::CUIButton( std::wstring normalImagePath, std::wstring pressedImagePath )
{
	m_pNormalImage = NNSprite::Create(normalImagePath);
	m_pPressedImage = NNSprite::Create(pressedImagePath);
	m_pNormalImage->SetPosition(0, 0);
	m_pPressedImage->SetPosition(0, 0);
		
	m_pNormalImage->SetVisible(true);
	m_pPressedImage->SetVisible(true);

	AddChild( m_pPressedImage, 10);
	AddChild( m_pNormalImage, 10);
}

// 이미지 두 장을 이용하여 button을 생성하는 함수
// input : 기본 이미지 경로, 버튼이 눌렸을 때 바뀌는 이미지 경로
// output : 버튼 pointer
CUIButton* CUIButton::Create( std::wstring normalImagePath, std::wstring pressedImagePath )
{
	CUIButton* pInstance = nullptr;
	pInstance = new CUIButton(normalImagePath, pressedImagePath);

	return pInstance;
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

// 현재 마우스 커서의 위치가 UIbutton 위에 있는지를 체크함
// parameter : void
// return  : button 위에 있을 시 1, button밖dp 있을 시 0을 반환
bool CUIButton::CheckButtonArea( void )
{
	NNPoint cursorPosition = NNInputSystem::GetInstance()->GetMousePosition();
	bool isInXCoordRange = (m_Position.GetX() < cursorPosition.GetX()) && ( ( m_Position.GetX() + m_pNormalImage->GetImageWidth() ) > cursorPosition.GetX() );
	bool isInYCoordRange = (m_Position.GetY() < cursorPosition.GetY()) && ( ( m_Position.GetY() + m_pNormalImage->GetImageHeight() ) > cursorPosition.GetY() );
	

	m_pPressedImage->SetVisible(false);
	m_pNormalImage->SetVisible(false);

	// //visible이 false가 되도 이미지가 계속 나오는 문제가 있음
	// 1. 선협이 framework상 문제인데 상위 object가 자식들에게 지정해준 zIndex값이 
	// 자식의 자식이 갖는 zIndex보다 우선하기 때문에 자식의 자식이 갖는 zIndex가 무시됨
	// 2. SetVisible했을 때 false구문이 이상하게 안 먹는 것 같음, 
	if ( isInXCoordRange && isInYCoordRange ) {
//		m_pNormalImage->SetVisible(false);

// 		if (NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_NOTPRESSED ) {
// 			m_pNormalImage->SetVisible(true);
// 			m_pPressedImage->SetVisible(false);
// 		}

		return true;
	}
	
	return false;
}
