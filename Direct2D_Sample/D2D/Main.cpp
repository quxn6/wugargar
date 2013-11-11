
#include "NNApplication.h"
#include "NNAudioSystem.h"

#include "SpriteExample.h"
#include "LabelExample.h"
#include "SoundExample.h"
#include "InputExample.h"
#include "CustomObjectExample.h"
#include "PlayScene.h"
#include "Player.h"
#include "NextStageScene.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );
#endif 
	srand((unsigned int)time(NULL));
	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", GAME_SCREEN_MAX_SIZE_X, GAME_SCREEN_MAX_SIZE_Y, D2D );
	 
	CPlayer::GetInstance();
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
	 NNSceneDirector::GetInstance()->ChangeScene( CPlayScene::GetInstance() );

	 // UPGRADE SCENE
	// NNSceneDirector::GetInstance()->ChangeScene( CNextStageScene::Create() );

	Application->Run();
	Application->Release();

	return 0;
}