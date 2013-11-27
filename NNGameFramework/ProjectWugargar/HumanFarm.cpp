#include "HumanFarm.h"
#include "GameConfig.h"
#include "HumanInFarm.h"

CHumanFarm::CHumanFarm(void)
{
	InitFarmBackground();
	m_pMeatPoint = 100; //°í±â Æ÷ÀÎÆ® ÃÊ±âÈ­ (¾Æ±âµé ¸ÔÀÌ Áà¾ßÇÏ¹Ç·Î Ã·¿¡ 100¿øÁÜ)
	m_pShowMeatPoint = NNLabel::Create( L"Meat Point", L"¸¼Àº °íµñ", 20.f );
	m_pShowMeatPoint->SetPosition(10.f, FIRST_Y_COORDINATE_OF_UIBUTTON +5.f);
	AddChild( m_pShowMeatPoint , 200);
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
	ShowMeatPoint();
}

void CHumanFarm::MakeHuman()
{
	CHumanInFarm* tmpBaby = CHumanInFarm::Create();
	AddChild( tmpBaby , 30);
}

void CHumanFarm::InitFarmBackground()
{
	std::wstring FarmBackground = L"wugargar/FarmBackground.png";
	m_pFarmBackground = NNSprite::Create(FarmBackground);
	m_pFarmBackground->SetPosition(0, FIRST_Y_COORDINATE_OF_UIBUTTON);
	m_pFarmBackground->SetVisible(true);

	AddChild( m_pFarmBackground, 20);
}

void CHumanFarm::ShowMeatPoint()
{
	ZeroMemory(meatPointTemp, 256);	
	swprintf_s(meatPointTemp, _countof(meatPointTemp), L"meat point = %d", m_pMeatPoint );
	m_pShowMeatPoint->SetString(meatPointTemp);
}
