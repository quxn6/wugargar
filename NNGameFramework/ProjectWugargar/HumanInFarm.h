#pragma once
#include "nnAnimation.h"
#include "NNMacroSet.h"
#include "NNObject.h"
#include "..\NNGameFramework\NNSpriteAtlas.h"

class CHumanInFarm : public NNObject
{
public:
	CHumanInFarm(void);
	virtual ~CHumanInFarm(void);

public :
	NNSpriteAtlas *m_pSmallBabyAtlas;
	NNSpriteAtlas *m_pMiddleBabyAtlas;
	NNSpriteAtlas *m_pGrownUpAtlas;

	NNAnimation *m_pSmallBaby;
	NNAnimation *m_pMiddleBaby;
	NNAnimation *m_pGrownUp;

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CHumanInFarm);

public :
	void CreateBaby();
	void SetRandomPositionInFarm();
};

