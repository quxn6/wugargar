#pragma once
#include "nnscene.h"
#include "UIButton.h"
class CStageSelectScene :
	public NNScene
{
public:
	CStageSelectScene(void);
	~CStageSelectScene(void);

public:
	void InitMenuButtons( void );
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CStageSelectScene);

private:
	CUIButton *stage1_button;
	CUIButton *stage2_button;
	CUIButton *stage3_button;
	CUIButton *stage4_button;
	CUIButton *stage5_button;
	CUIButton *stage6_button;
	CUIButton *stage7_button;

};

