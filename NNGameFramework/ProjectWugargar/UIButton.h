#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNPoint.h"
#include "NNLabel.h"

class CUIButton : public NNObject
{
public :
	CUIButton(void);
	CUIButton( std::wstring normalImagePath, std::wstring pressedImagePath );
	CUIButton( std::wstring normalImagePath, std::wstring pressedImagePath, std::wstring onImagePath );
	virtual ~CUIButton(void);

	static CUIButton* Create( std::wstring normalImagePath, std::wstring pressedImagePath );
	static CUIButton* Create(std::wstring normalImagePath, std::wstring pressedImagePath, std::wstring onImagePath);
	void Render();
	void Update( float dTime );
	bool CheckButtonArea( void );
	bool CheckButtonOn(void);
	bool ButtonPressed();


protected :
	NNSprite *m_pPressedImage;
	NNSprite *m_pNormalImage;
	NNSprite *m_pOnImage;
	NNLabel	 *m_pButtonLabel; 



};

