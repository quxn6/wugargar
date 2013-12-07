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

protected :
	NNSprite *m_pPressedImage;
	NNSprite *m_pNormalImage;
	NNLabel	 *m_pButtonLabel; 

};

