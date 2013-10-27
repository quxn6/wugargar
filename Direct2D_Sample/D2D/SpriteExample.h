
#pragma once

#include "NNScene.h"
#include "NNSprite.h"

class SpriteExample : public NNScene
{
private:
	NNSprite* m_Sprite;

public:
	SpriteExample();
	virtual ~SpriteExample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(SpriteExample);
};