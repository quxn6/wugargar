#include "HumanInFarm.h"
#include "GameConfig.h"


CHumanInFarm::CHumanInFarm(void)
{
	CreateBaby();
}


CHumanInFarm::~CHumanInFarm(void)
{
}

void CHumanInFarm::Render()
{
	NNObject::Render();
}

void CHumanInFarm::Update( float dTime )
{
	NNObject::Update(dTime);
}

void CHumanInFarm::CreateBaby()
{
	m_pSmallBaby = NNAnimation::Create(1,L"wugargar/smallbaby.png");
	m_pSmallBaby->SetPosition( NNPoint( 100.0f, FIRST_Y_COORDINATE_OF_UIBUTTON+50.0f) );
	AddChild(m_pSmallBaby,100);
}