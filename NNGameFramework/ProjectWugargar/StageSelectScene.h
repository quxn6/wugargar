#pragma once
#include "nnscene.h"
#include "UIButton.h"
#include "NNSound.h"

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

	void ShowMapDetail(int stageNum);
	void SettingButton(int stage_idx);


	NNCREATE_FUNC(CStageSelectScene);

private:
	NNSprite *m_mapSprite;
	CUIButton *m_stageFlag[STAGE_NUM];
	bool IsStageClear[STAGE_NUM];
	NNSprite *m_stageIllust[STAGE_NUM];
	NNSprite *m_lockStageIllust;

	NNSprite *m_difficultyStar;
	NNSprite *m_stageIllustrate;
	

	NNLabel *m_pShowDifficulty;
	NNLabel *m_pShowCleared;
	NNLabel *m_pShowUnacceptable;

	NNSound *m_pBackgroundSound;

	CUIButton *m_pPlayButton;
	CUIButton *m_pExitButton;


};

