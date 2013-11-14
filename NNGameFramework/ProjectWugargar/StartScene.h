#pragma once
#include "NNScene.h"
#include "NNSprite.h"
#include "GameConfig.h"
#include "Player.h"
#include "UIButton.h"
class CStartScene :
	public NNScene
{
public:
	CStartScene(void);
	~CStartScene(void);

	void Render();
	virtual void Update( float dTime );

	NNCREATE_FUNC(CStartScene);

	CUIButton*	m_pNewGameButton;
	CUIButton*	m_pLoadGameButton;
	CUIButton*	m_pExitButton;
	NNSprite*	m_pBackground;
	NNSprite*	m_pMainTitle;


private :
	void InitButtons( void );

private :
	wchar_t		m_LabelBuffer[NUMBER_OF_ZOMBIE_TYPES][256];
	wchar_t		m_ResultBuffer[256];

};

