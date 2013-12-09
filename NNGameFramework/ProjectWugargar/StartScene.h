#pragma once
#include "NNScene.h"
#include "NNSprite.h"
#include "Player.h"
#include "UIButton.h"
#include "NNXML.h"
#include "NNSound.h"

#define MENU_BAR_NUM 3
enum MenuList{
	MENU_PLAY,
	MENU_LOAD,
	MENU_QUIT
};


class CStartScene :
	public NNScene
{
public:
	CStartScene(void);
	~CStartScene(void);

	void Render();
	virtual void Update( float dTime );
	void load();
	
	NNCREATE_FUNC(CStartScene);


private :
	void InitButtons( void );
	void InitBackGround(void);

private :
	wchar_t		m_LabelBuffer[NUMBER_OF_ZOMBIE_TYPES][256];
	wchar_t		m_ResultBuffer[256];
	NNXML*		m_TestXML;
	


	NNLabel*	m_MenuBar[MENU_BAR_NUM];
	unsigned int m_KeyOn;

	

	NNSound*	m_startscene_background_sound;
	NNSprite*	m_pStartSceneBackground;
};

