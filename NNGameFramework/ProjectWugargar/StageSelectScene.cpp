#include "StageSelectScene.h"
#include "Player.h"
#include "PlayScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "UpgradeScene.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"


CStageSelectScene::CStageSelectScene(void)
{
	InitMapSprite();

	m_pBackgroundSound = NNResourceManager::GetInstance()->LoadSoundFromFile("sound/StageSelectSceneBackground.mp3", true, true);
	NNAudioSystem::GetInstance()->Play(m_pBackgroundSound);
	m_pPlayButton = nullptr;
	m_pExitButton = nullptr;
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
			if(m_stageFlag[idx]->CheckButtonArea())
			{
				if(IsStageClear[idx])
				{
					m_stageIllust[idx]->SetPosition(GAME_SCREEN_MAX_SIZE_X/2, GAME_SCREEN_MIN_SIZE_Y);
					m_stageIllust[idx]->SetVisible(true);

					//Player의 현재 스테이지 진행 현황 외에 PlayScene에서 진행되는
					//스테이지를 표시하기 위한 변수 추가.
					//이미 진행한 스테이지도 진행하게 하기 위함.
					CPlayer::GetInstance()->SetPlayingStage(idx+1);
				}
				else
				{
					m_lockStageIllust->SetPosition(GAME_SCREEN_MAX_SIZE_X/2, GAME_SCREEN_MIN_SIZE_Y);
					m_lockStageIllust->SetVisible(true);
				}
				SettingButton(idx);
				break;
			}
		}

		//선택된 스테이지 버튼이 클리어 할 수 있는 스테이지 인 경우 선택됨
		if(m_pPlayButton && m_pPlayButton->CheckButtonArea())
		{
			NNSceneDirector::GetInstance()->ChangeScene(CUpgradeScene::Create());
			return ;
		}

		//Exit버튼이 눌리면 다시 스테이지 선택 화면으로 돌아감
		if(m_pExitButton && m_pExitButton->CheckButtonArea())
		{
			for(int idx=0; idx<STAGE_NUM; ++idx)
				m_stageIllust[idx]->SetVisible(false);

			m_lockStageIllust->SetVisible(false);
			// remove시 리스트에서만 없애고 객체를 안날려서(true를 안붙여서) label이 살아있었음.
			RemoveChild(m_pExitButton, true);
			RemoveChild(m_pPlayButton, true);
			m_pPlayButton = nullptr;
			m_pExitButton = nullptr;
			
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
		m_stageFlag[idx] = CUIButton::Create(L"wugargar/stageselect_on.png", L"wugargar/stageselect_on.png");
		AddChild( m_stageFlag[idx] );
		IsStageClear[idx] = true;
	}
	for(int idx=current_stage; idx<STAGE_NUM; ++idx)
	{
		m_stageFlag[idx] = CUIButton::Create(L"wugargar/stageselect_off.png",L"wugargar/stageselect_off.png");
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
	

	//StageIllustrate Sprite(말풍선) 미리 배치. 보여주는 경우 포지션 세팅하고 visible을 true로
	//m_stageIllustrate = NNSprite::Create(L"wugargar/StageIllustrate.png");
	//AddChild(m_stageIllustrate);
	//m_stageIllustrate->SetVisible(false);

	
	
	

}

//Button을 다른 Sprite 생성과 분리한 이유~
//Sprite는 Set Visible 조정만 해줘도 문제가 없지만
//Button의 경우는 그렇게 처리할 경우, 보이지 않을 뿐, 그 위치를
//클릭할 경우 플레이가 가능해짐.
//따라서 따로 Set Button을 빼놓고 그때그때 Remove해주기 위함.
void CStageSelectScene::SettingButton(int stage_idx)
{
	if(IsStageClear[stage_idx]){
		m_pPlayButton = CUIButton::Create(L"wugargar/playbutton.png", L"wugargar/playbutton.png");
		AddChild(m_pPlayButton);
		m_pPlayButton->SetPosition(GAME_SCREEN_MAX_SIZE_X/2, GAME_SCREEN_MIN_SIZE_Y);
	}
	
	m_pExitButton = CUIButton::Create(L"wugargar/exitbutton.png", L"wugargar/exitbutton.png");
	AddChild(m_pExitButton);
	m_pExitButton->SetPosition(GAME_SCREEN_MAX_SIZE_X/2, GAME_SCREEN_MIN_SIZE_Y+20);


}
