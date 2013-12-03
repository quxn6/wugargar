#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "NNPoint.h"
#include "NNLabel.h"

class CUIButton : public NNObject
{
public :
	CUIButton(void);
	CUIButton( std::wstring normalImagePath, std::wstring pressedImagePath );
	virtual ~CUIButton(void);

public :
	static CUIButton* Create( std::wstring normalImagePath, std::wstring pressedImagePath );
	void Render();
	void Update( float dTime );
	bool CheckButtonArea( void );
	bool ButtonPressed();

	bool m_InCoolTime;
	clock_t m_tCoolTime;
	clock_t m_tClickedTime;
	clock_t m_tNowTime; // 1초 단위로 시간을 재기위한 tmp

protected :
	NNSprite *m_pPressedImage;
	NNSprite *m_pNormalImage;
	NNLabel	 *m_pButtonLabel; 

};

