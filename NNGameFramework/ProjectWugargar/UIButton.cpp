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
	m_pPressedImage->SetVisible(false);

	AddChild( m_pPressedImage, 10);
	AddChild( m_pNormalImage, 10);

	m_InCoolTime = false;
	m_tNowTime = clock();
	m_tCoolTime = 5 * CLOCKS_PER_SEC; // 일단 쿨타임 전부다 5초로 세팅
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
	m_tNowTime = clock();
	if(m_InCoolTime == true)
	{
		//printf_s("쿨타임 %d",(m_tNowTime - m_tClickedTime)/CLOCKS_PER_SEC);
		if(m_tNowTime - m_tClickedTime >= m_tCoolTime){
			m_InCoolTime = false;
		}
	}
	
}
// 현재 마우스 커서의 위치가 UIbutton 위에 있는지를 체크함
// parameter : void
// return  : button 위에 있을 시 1, button밖에 있을 시 0을 반환
bool CUIButton::CheckButtonArea( void )
{
	NNPoint cursorPosition = NNInputSystem::GetInstance()->GetMousePosition();
	bool isInXCoordRange = (m_Position.GetX() < cursorPosition.GetX()) && ( ( m_Position.GetX() + m_pNormalImage->GetImageWidth() ) > cursorPosition.GetX() );
	bool isInYCoordRange = (m_Position.GetY() < cursorPosition.GetY()) && ( ( m_Position.GetY() + m_pNormalImage->GetImageHeight() ) > cursorPosition.GetY() );
	
	if ( !(isInXCoordRange && isInYCoordRange) ) {
		m_pNormalImage->SetVisible(true);
		m_pPressedImage->SetVisible(false);
		return false;
	} else {
		if (NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_PRESSED ) {
			m_pNormalImage->SetVisible(false);
			m_pPressedImage->SetVisible(true);
		}
		if (NNInputSystem::GetInstance()->GetKeyState( VK_LBUTTON ) == KEY_UP ){
			m_pNormalImage->SetVisible(true);
			m_pPressedImage->SetVisible(false);
			return true;
		}
	}
	
	return false;
}
