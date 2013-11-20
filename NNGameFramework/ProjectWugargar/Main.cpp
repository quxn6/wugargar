
#include "NNApplication.h"
#include "NNAudioSystem.h"

#include "PlayScene.h"
#include "Player.h"
#include "NextStageScene.h"
#include "StartScene.h"

#ifdef _DEBUG
#pragma comment(lib, "NNGameFramework_DEBUG.lib")
#else
#pragma comment(lib, "NNGameFramework.lib")
#endif

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );
#endif 
	srand((unsigned int)time(NULL));
	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", GAME_SCREEN_MAX_SIZE_X, GAME_SCREEN_MAX_SIZE_Y, D2D );
		
	// Sprite Example
	// NNSceneDirector::GetInstance()->ChangeScene( SpriteExample::Create() );

	// Label Example
	// NNSceneDirector::GetInstance()->ChangeScene( LabelExample::Create() );

	// Input Example
	// NNSceneDirector::GetInstance()->ChangeScene( InputExample::Create() );

	// Sound Example
	// NNSceneDirector::GetInstance()->ChangeScene( SoundExample::Create() );

	// CustomObject Example
	// NNSceneDirector::GetInstance()->ChangeScene( CustomObjectExample::Create() );

	// Wugargar game
	// NNSceneDirector::GetInstance()->ChangeScene( CPlayScene::GetInstance() );

	// StartMenu SCENE
	 NNSceneDirector::GetInstance()->ChangeScene(CStartScene::Create());

	 // UPGRADE SCENE
	// NNSceneDirector::GetInstance()->ChangeScene( CNextStageScene::Create() );

	Application->Run();
	Application->Release();

	return 0;
}