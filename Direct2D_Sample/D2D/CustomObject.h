
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNScene.h"

class CustomObject : public NNObject
{
public:
	NNSprite* m_Sprite;
	NNLabel* m_Label;

public:
	CustomObject();
	virtual ~CustomObject();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CustomObject);
};