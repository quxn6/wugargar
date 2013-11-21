#include "HumanFarm.h"
#include "GameConfig.h"
#include "HumanInFarm.h"


CHumanFarm::CHumanFarm(void)
{
	std::wstring FarmBackground = L"wugargar/FarmBackground.png";
	m_pFarmBackground = NNSprite::Create(FarmBackground);
	m_pFarmBackground->SetPosition(0, FIRST_Y_COORDINATE_OF_UIBUTTON);
	m_pFarmBackground->SetVisible(true);

	AddChild( m_pFarmBackground, 20);
}

CHumanFarm::~CHumanFarm(void)
{
}

void CHumanFarm::Render()
{
	NNObject::Render();
}

void CHumanFarm::Update( float dTime )
{
	NNObject::Update(dTime);
}

void CHumanFarm::MakeHuman()
{
	CHumanInFarm* tmpBaby = CHumanInFarm::Create();
	//std::wstring HumanimagePath = L"wugargar/smallbaby.png";
	AddChild( tmpBaby , 30);
}
