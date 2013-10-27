
#pragma once

#include "NNScene.h"
#include "NNLabel.h"

class SoundExample : public NNScene
{
private:
	NNLabel* m_Label;

public:
	SoundExample();
	virtual ~SoundExample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(SoundExample);
};