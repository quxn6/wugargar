#pragma once
#include "NNScene.h"


class NNSound;
class NNLabel;
class NNSprite;

#define MENU_BAR_NUM 3
enum MenuList{
	MENU_PLAY,
	MENU_LOAD,
	MENU_QUIT
};

//시작 화면을 나타내는 Scene
class CStartScene :
	public NNScene
{
public:
	CStartScene(void);
	~CStartScene(void);

	virtual void Render();
	virtual void Update( float dTime );
	void load();
	
	NNCREATE_FUNC(CStartScene);


private :
	void InitButtons( void );
	void InitBackGround(void);

private :
	NNLabel*		m_MenuBar[MENU_BAR_NUM];
	unsigned int	m_KeyOn;
	NNSound*		m_startscene_background_sound;
	NNSprite*		m_pStartSceneBackground;
};

