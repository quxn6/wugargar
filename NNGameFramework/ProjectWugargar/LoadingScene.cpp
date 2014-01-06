#include "LoadingScene.h"
#include "NNSceneDirector.h"
#include "PlayScene.h"
#include "NNSprite.h"


CLoadingScene::CLoadingScene(void)
{
	elapsed_time = 0.0f;

 	NNSprite *tmp = NNSprite::Create(L"wugargar/Loading/Loading4.jpg");
 	tmp->SetPosition(0,0);
 	AddChild(tmp);

}


CLoadingScene::~CLoadingScene(void)
{
}

void CLoadingScene::Render()
{
	NNObject::Render();
}

void CLoadingScene::Update( float dTime )
{
	NNObject::Update(dTime);
	elapsed_time += dTime;


	if(elapsed_time>0.1)
		NNSceneDirector::GetInstance()->ChangeScene(CPlayScene::GetInstance());
	
}


