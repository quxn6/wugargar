#pragma once
#include "nnobject.h"
#include "NNSprite.h"


class CLightning :
	public NNObject
{
public:
	CLightning(void);
	~CLightning(void);


public:
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CLightning);	

	void InitSprite(std::wstring imagePath);


protected:
	NNSprite* m_lightning_sprite;
	NNSprite* m_fall_lightning_sprite;
	bool	m_is_fall_lightning;


};

