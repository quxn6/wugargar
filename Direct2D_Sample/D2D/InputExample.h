
#pragma once

#include "NNScene.h"
#include "NNLabel.h"

class InputExample : public NNScene
{
private:
	NNLabel* m_Label;
	NNLabel* m_Count;
	int DownCount;
	int PressedCount;
	int UpCount;

	wchar_t temp[256];
public:
	InputExample();
	virtual ~InputExample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(InputExample);
};