#include "StageSelectScene.h"
#include "Player.h"
#include "PlayScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "UpgradeScene.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"
#include "UIButton.h"
#include "NNSound.h"
#include "NNSprite.h"
#include "NNLabel.h"


CStageSelectScene::CStageSelectScene(void)
{
	InitMapSprite();

	m_pBackgroundSound = NNResourceManager::GetInstance()->
		LoadSoundFromFile("sound/StageSelectSceneBackground.mp3", true, true);
	NNAudioSystem::GetInstance()->Play(m_pBackgroundSound);
	m_onImage = false;
}


CStageSelectScene::~CStageSelectScene(void)
{
	NNAudioSystem::GetInstance()->Stop( m_pBackgroundSound );
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

	

	if(NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON))
	{
	
		for (int idx=0; idx<STAGE_NUM; ++idx)
		{
			//StageFlag(동그란 거)가 입력되었을 때의 처리
			//Stage의 정보를 띄워주는 것들을 생성.
			if(m_stageFlag[idx]->CheckButtonOn())
			{
				m_onImage = true;

				if(IsStageClear[idx])
				{
					m_stageIllust[idx]->SetPosition(GAME_SCREEN_MAX_SIZE_X/2, GAME_SCREEN_MIN_SIZE_Y);
					m_stageIllust[idx]->SetVisible(true);

					if(m_stageFlag[idx]->CheckButtonArea())
					{
						//Player의 현재 스테이지 진행 현황 외에 PlayScene에서 진행되는
						//스테이지를 표시하기 위한 변수 추가.
						//이미 진행한 스테이지도 진행하게 하기 위함.
						CPlayer::GetInstance()->SetPlayingStage(idx+1);

						NNSceneDirector::GetInstance()->
							ChangeScene(CUpgradeScene::Create());
						return;
					}

				}
				else
				{
					m_lockStageIllust->SetPosition(GAME_SCREEN_MAX_SIZE_X/2, GAME_SCREEN_MIN_SIZE_Y);
					m_lockStageIllust->SetVisible(true);
				}
				break;
			}


			if(m_onImage && !m_stageFlag[idx]->CheckButtonOn())
			{
				for(int idx=0; idx<STAGE_NUM; ++idx)
					m_stageIllust[idx]->SetVisible(false);

				m_lockStageIllust->SetVisible(false);
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

	int current_stage = CPlayer::GetInstance()->GetClearedStage() % 100;

	//MapStageFlag Sprite배치. 클리어 한 스테이지는 빨강, 아닌 스테이지는 파란색 원으로 표시 (임시)
	for(int idx=0; idx<current_stage; ++idx)
	{
		m_stageFlag[idx] = CUIButton::Create
			(L"wugargar/stageselect_on.png", L"wugargar/stageselect_on.png", L"wugargar/stageselect_off.png");
		AddChild( m_stageFlag[idx] );
		IsStageClear[idx] = true;
	}
	for(int idx=current_stage; idx<STAGE_NUM; ++idx)
	{
		m_stageFlag[idx] = CUIButton::Create
			(L"wugargar/stageselect_off.png",L"wugargar/stageselect_off.png",  L"wugargar/stageselect_on.png");
		AddChild( m_stageFlag[idx] );
		IsStageClear[idx] = false;
	}

	m_stageFlag[0]->SetPosition(301,219);
	m_stageFlag[1]->SetPosition(448,183);
	m_stageFlag[2]->SetPosition(465,321);
	m_stageFlag[3]->SetPosition(601,403);


	m_stageIllust[0] = NNSprite::Create(L"wugargar/StageSelect/Stage1ExplainImage.png");
	m_stageIllust[1] = NNSprite::Create(L"wugargar/StageSelect/Stage2ExplainImage.png");
	m_stageIllust[2] = NNSprite::Create(L"wugargar/StageSelect/Stage3ExplainImage.png");
	m_stageIllust[3] = NNSprite::Create(L"wugargar/StageSelect/Stage4ExplainImage.png");
	m_lockStageIllust = NNSprite::Create(L"wugargar/StageSelect/LockStageImage.png");
	AddChild(m_lockStageIllust);
	m_lockStageIllust->SetVisible(false);
	
	for(int idx=0; idx<STAGE_NUM; ++idx)
	{
		AddChild(m_stageIllust[idx]);
		m_stageIllust[idx]->SetVisible(false);
	}
	

	
	
	

}