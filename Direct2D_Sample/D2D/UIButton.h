#pragma once
#include "nnobject.h"
#include "NNMacroSet.h"
#include "NNSprite.h"
#include "NNPoint.h"

class CUIButton : public NNObject
{
public :
	CUIButton(void);
	virtual ~CUIButton(void);

public :
	void Render();
	void Update( float dTime );
	bool CheckButtonArea( void );
	bool ButtonPressed ();

	NNCREATE_FUNC (CUIButton);

private :
	NNSprite *m_pPressedImage;
	NNSprite *m_pNormalImage;

};

