#pragma once
#include "NNObject.h"
#include "NNSprite.h"

class CBackground : public NNObject
{
public:
	CBackground(void);
	virtual ~CBackground(void);
	
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CBackground);

private :
	NNSprite*		m_pBackgroundImage;
};

