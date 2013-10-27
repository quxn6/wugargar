
#pragma once

#include "NNScene.h"
#include "CustomObject.h"

class CustomObjectExample : public NNScene
{
private:
	CustomObject* m_CustomObject;

public:
	CustomObjectExample();
	virtual ~CustomObjectExample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CustomObjectExample);
};