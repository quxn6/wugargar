
#pragma once

#include "NNScene.h"
#include "NNLabel.h"

class LabelExample : public NNScene
{
private:
	NNLabel* m_NormalLabel;
	NNLabel* m_BoldLabel;
	NNLabel* m_ItalicLabel;
	NNLabel* m_ColorLabel;
	NNLabel* m_OpacityLabel;
	NNLabel* m_DifferentFontLabel;

public:
	LabelExample();
	virtual ~LabelExample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(LabelExample);
};