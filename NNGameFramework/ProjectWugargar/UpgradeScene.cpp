#include "UpgradeScene.h"


CUpgradeScene::CUpgradeScene(void)
{
}


CUpgradeScene::~CUpgradeScene(void)
{
}

void CUpgradeScene::Render()
{
	NNObject::Render();
}

void CUpgradeScene::Update( float dTime )
{
	NNScene::Update(dTime);
}

void CUpgradeScene::InitUpgradeUI()
{
	m_pBackground = NNSprite::Create(L"wugargar/upgrade.png");
	m_pBackground->SetPosition(0,0);
	AddChild(m_pBackground);

	NNAnimation* tmpforAnimation;
}
