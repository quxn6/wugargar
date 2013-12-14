#pragma once
#include "nnscene.h"
#include "UIButton.h"

#define  STAGE_NUM 4
class CStageSelectScene :
	public NNScene
{
public:
	CStageSelectScene(void);
	~CStageSelectScene(void);

public:
	void InitMenuButtons( void );
	void InitMapSprite();
	void Render();
	void Update( float dTime );



	NNCREATE_FUNC(CStageSelectScene);

private:
	NNSprite *m_mapSprite;
	CUIButton *m_stageFlag[STAGE_NUM];
	NNSprite *m_difficultyStar;



	CUIButton *stage1_button;
	CUIButton *stage2_button;
	CUIButton *stage3_button;
	CUIButton *stage4_button;
	CUIButton *stage5_button;
	CUIButton *stage6_button;
	CUIButton *stage7_button;

};

