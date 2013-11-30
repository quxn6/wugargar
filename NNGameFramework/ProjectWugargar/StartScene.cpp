#include "StartScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"


CStartScene::CStartScene(void)
{
	InitButtons();
}

void CStartScene::InitButtons( void )
{
	std::wstring new_button_path = L"wugargar/UIbuttons/startbutton_normal.png";
	std::wstring new_button_path_pressed = L"wugargar/UIbuttons/startbutton_pressed.png";
	std::wstring load_button_path = L"wugargar/UIbuttons/loadbutton_normal.png";
	std::wstring load_button_path_pressed = L"wugargar/UIbuttons/loadbutton_pressed.png";
	std::wstring exit_button_path = L"wugargar/UIbuttons/exitbutton_normal.png";
	std::wstring exit_button_path_pressed = L"wugargar/UIbuttons/exitbutton_pressed.png";
	std::wstring main_title = L"wugargar/UIbuttons/MainTitle.png";


	m_pNewGameButton = CUIButton::Create(new_button_path, new_button_path_pressed);
	m_pNewGameButton->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 2);
	AddChild(m_pNewGameButton, 20);
	m_pLoadGameButton = CUIButton::Create(load_button_path, load_button_path_pressed);
	m_pLoadGameButton->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 3);
	AddChild(m_pLoadGameButton, 20);
	m_pExitButton = CUIButton::Create(exit_button_path, exit_button_path_pressed);
	m_pExitButton->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 4);
	AddChild(m_pExitButton, 20);
	m_pMainTitle = NNSprite::Create(main_title);
	m_pMainTitle->SetPosition(GAME_SCREEN_MAX_SIZE_X / 3.0f, GAME_SCREEN_MAX_SIZE_Y / 5.0f * 1);
	AddChild(m_pMainTitle, 19);
}

CStartScene::~CStartScene(void)
{

}

void CStartScene::Render()
{
	NNObject::Render();
}

void CStartScene::Update( float dTime )
{
	NNScene::Update(dTime);

	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON)) 
	{
		// new game
		if(m_pNewGameButton->CheckButtonArea()) {
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
		}
		
		// load game
		if(m_pLoadGameButton->CheckButtonArea()) {
			NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
		}
		
		// exit
		if(m_pExitButton->CheckButtonArea()) {
			
		}		
	}
}

