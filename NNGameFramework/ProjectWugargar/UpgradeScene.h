#pragma once
#include "NNScene.h"
#include "NNSprite.h"
#include "NNAnimation.h"
class CUpgradeScene :
	public NNScene
{
public:
	CUpgradeScene(void);
	~CUpgradeScene(void);

public:
	void Render();
	void Update( float dTime );
	
	void InitUpgradeUI();
	
	NNCREATE_FUNC(CUpgradeScene);

protected:
	NNSprite* m_pBackground;

};

