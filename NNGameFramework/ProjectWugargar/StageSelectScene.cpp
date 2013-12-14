#include "StageSelectScene.h"
#include "Player.h"
#include "PlayScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"


CStageSelectScene::CStageSelectScene(void)
{
	InitMapSprite();
}


CStageSelectScene::~CStageSelectScene(void)
{
}

void CStageSelectScene::InitMenuButtons( void )
{

}

void CStageSelectScene::Render()
{
	NNObject::Render();
}

void CStageSelectScene::Update( float dTime )
{
	NNScene::Update(dTime);


	int current_stage =  CPlayer::GetInstance()->GetCurrentStage() / 100;
	if(NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON))
	{
		for (int idx=0; idx<STAGE_NUM; ++idx)
		{
			//선택된 스테이지 버튼이 클리어 할 수 있는 스테이지 인 경우 선택됨
			if(m_stageFlag[idx]->CheckButtonArea() && (idx+1) <= current_stage)
			{
				//Player의 현재 스테이지 진행 현황 외에 PlayScene에서 진행되는
				//스테이지를 표시하기 위한 변수 추가.
				//이미 진행한 스테이지도 진행하게 하기 위함.
				CPlayer::GetInstance()->SetPlayingStage(idx+1);
				NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
				break;
			}
		}
	}


}

void CStageSelectScene::InitMapSprite()
{
	//Map Sprite 배치
	m_mapSprite = NNSprite::Create(L"wugargar/stageSelect.jpg");
	m_mapSprite->SetPosition(0.0f, 0.0f);
	AddChild( m_mapSprite );

	int current_stage = CPlayer::GetInstance()->GetCurrentStage() / 100;

	//MapStageFlag Sprite배치. 클리어 한 스테이지는 빨강, 아닌 스테이지는 파란색 원으로 표시 (임시)
	for(int idx=0; idx<current_stage; ++idx)
	{
		m_stageFlag[idx] = CUIButton::Create(L"wugargar/stageselect_on.png", L"wugargar/stageselect_on.png");
		AddChild( m_stageFlag[idx] );
	}
	for(int idx=current_stage; idx<STAGE_NUM; ++idx)
	{
		m_stageFlag[idx] = CUIButton::Create(L"wugargar/stageselect_off.png",L"wugargar/stageselect_off.png");
		AddChild( m_stageFlag[idx] );
	}

	m_stageFlag[0]->SetPosition(301,219);
	m_stageFlag[1]->SetPosition(448,183);
	m_stageFlag[2]->SetPosition(465,321);
	m_stageFlag[3]->SetPosition(601,403);

}
