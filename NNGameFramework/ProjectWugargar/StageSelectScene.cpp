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

	//static변수로 Update를 사정없이 돌면서도 '현재 선택중인' 스테이지의 번호를 알게 함.
	//..더 좋은 방법이 없을까?
	static int tmp_current_stage;

	int current_stage =  CPlayer::GetInstance()->GetCurrentStage() / 100;
	if(NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON))
	{
		for (int idx=0; idx<STAGE_NUM; ++idx)
		{
			//StageFlag(동그란 거)가 입력되었을 때의 처리
			//Stage의 정보를 띄워주는 것들을 생성.
			if(m_stageFlag[idx]->CheckButtonArea())
			{
				m_stageIllustrate->SetPosition(m_stageFlag[idx]->GetPositionX()+50, m_stageFlag[idx]->GetPositionY()-50);
				m_stageIllustrate->SetVisible(true);
				ShowMapDetail(idx+1);
				m_pPlayButton->SetPosition(m_stageIllustrate->GetPositionX(), m_stageIllustrate->GetPositionY()+30);
				m_pExitButton->SetPosition(m_stageIllustrate->GetPositionX(), m_stageIllustrate->GetPositionY()+50);
				m_pPlayButton->SetVisible(true);
				m_pExitButton->SetVisible(true);
				tmp_current_stage = idx+1;
				break;
			}

			
			//선택된 스테이지 버튼이 클리어 할 수 있는 스테이지 인 경우 선택됨
			if(m_pPlayButton->CheckButtonArea() && tmp_current_stage  <= current_stage)
			{
				//Player의 현재 스테이지 진행 현황 외에 PlayScene에서 진행되는
				//스테이지를 표시하기 위한 변수 추가.
				//이미 진행한 스테이지도 진행하게 하기 위함.
				CPlayer::GetInstance()->SetPlayingStage(idx+1);
				NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
				break;
			}

			//Exit버튼이 눌리면 다시 스테이지 선택 화면으로 돌아감
			if(m_pExitButton->CheckButtonArea())
			{
				m_pExitButton->SetVisible(false);
				m_pPlayButton->SetVisible(false);
				m_pShowDifficulty->SetVisible(false);
				m_stageIllustrate->SetVisible(false);
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

	//StageIllustrate Sprite(말풍선) 미리 배치. 보여주는 경우 포지션 세팅하고 visible을 true로
	m_stageIllustrate = NNSprite::Create(L"wugargar/StageIllustrate.png");
	AddChild(m_stageIllustrate);
	m_stageIllustrate->SetVisible(false);

	//마찬가지로 UI버튼 두개 Play, exit도 배치
	m_pPlayButton = CUIButton::Create(L"wugargar/playbutton.png", L"wugargar/playbutton.png");
	AddChild(m_pPlayButton);
	m_pPlayButton->SetVisible(false);
	m_pExitButton = CUIButton::Create(L"wugargar/exitbutton.png", L"wugargar/exitbutton.png");
	AddChild(m_pExitButton);
	m_pExitButton->SetVisible(false);
	
	

}

void CStageSelectScene::ShowMapDetail( int stageNum )
{
	//선택한 Map의 Detail을 보여줌..
	//XML에서 데이터를 불러옴이 바람직하지만, 현재 구조상
	//데이터를 불러오는 부분이 PlayScene에 있으므로 임시로 설정하도록 함.

	switch (stageNum)
	{
	case 1:
		m_pShowDifficulty = NNLabel::Create(L"★☆☆☆☆", L"맑은 고딕", 20);
		break;
	case 2:
		m_pShowDifficulty = NNLabel::Create(L"★★☆☆☆", L"맑은 고딕", 20);
		break;
	case 3:
		m_pShowDifficulty = NNLabel::Create(L"★★★☆☆", L"맑은 고딕", 20);
		break;
	case 4:
		m_pShowDifficulty = NNLabel::Create(L"★★★★★", L"맑은 고딕", 20);
		break;
	default:
		break;
	}

	m_pShowDifficulty->SetPosition(m_stageIllustrate->GetPositionX(), m_stageIllustrate->GetPositionY());
	AddChild(m_pShowDifficulty);
}
