#pragma once
#include "NNScene.h"
#include "NNSprite.h"
#include "GameConfig.h"
#include "Player.h"
#include "UIButton.h"

#define FIRST_Y_COORD_OF_UPGRADE_BUTTONS	100
#define GAP_BETWEEN_UPGRADE_BUTTONS			15
#define SIZE_OF_UPGRADE_BUTTONS				100
#define FIRST_Y_COORD_OF_RESULTS			400

class CNextStageScene :	public NNScene
{
public:
	CNextStageScene(void);
	virtual ~CNextStageScene(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CNextStageScene);

	CUIButton*	m_pUpgradeButtons[NUMBER_OF_ZOMBIE_TYPES];
	NNLabel*	m_pUpgradeButtonLabel[NUMBER_OF_ZOMBIE_TYPES];
	CUIButton*	m_pGambleButton;
	CUIButton*	m_pNextStageButton;
	CUIButton*	m_pGameSaveButton;
	NNSprite*	m_pBackground;
	NNLabel*	m_pResults;
	
private :
	void InitButtons( void );

private :
	wchar_t		m_LabelBuffer[NUMBER_OF_ZOMBIE_TYPES][256];
	wchar_t		m_ResultBuffer[256];
	
};

