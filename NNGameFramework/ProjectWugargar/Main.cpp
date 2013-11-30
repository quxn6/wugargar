
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

	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");

#endif 
	srand((unsigned int)time(NULL));
	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", GAME_SCREEN_MAX_SIZE_X, GAME_SCREEN_MAX_SIZE_Y, D2D );
	CPlayer::GetInstance();
	// StartMenu SCENE
	NNSceneDirector::GetInstance()->ChangeScene(CStartScene::Create());

	// Wugargar game
	// NNSceneDirector::GetInstance()->ChangeScene( CPlayScene::GetInstance() );

	// UPGRADE SCENE
	// NNSceneDirector::GetInstance()->ChangeScene( CNextStageScene::Create() );

	Application->Run();
	Application->Release();
	CPlayer::ReleaseInstance();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}