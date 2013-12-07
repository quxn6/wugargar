#pragma once
#include "nnobject.h"
#include "NNSprite.h"

class CBackground : public NNObject
{
public:
	CBackground(void);
	virtual ~CBackground(void);

public : 
	NNSprite*		m_pBackgroundImage;
	
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CBackground);
};

