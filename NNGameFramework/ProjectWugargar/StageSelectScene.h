#pragma once
#include "nnscene.h"


class CUIButton;
class NNSound;
class NNSprite;
class NNLabel;


#define  STAGE_NUM 4

//Stage를 선택할 수 있게 해주는 Scene
class CStageSelectScene :
	public NNScene
{
public:
	CStageSelectScene(void);
	~CStageSelectScene(void);

	virtual void Render();
	virtual void Update( float dTime );
	NNCREATE_FUNC(CStageSelectScene);


private:
	void InitMenuButtons( void );
	void InitMapSprite();



	
private:
	NNSprite		*m_mapSprite;
	CUIButton		*m_stageFlag[STAGE_NUM];
	bool			IsStageClear[STAGE_NUM];
	NNSprite		*m_stageIllust[STAGE_NUM];
	NNSprite		*m_lockStageIllust;


	NNSound *m_pBackgroundSound;


	bool m_onImage;

};

