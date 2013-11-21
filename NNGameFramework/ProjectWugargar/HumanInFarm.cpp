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
	m_pSmallBaby = NNAnimation::Create(11,L"wugargar/smallbaby/0.png",
		L"wugargar/smallbaby/1.png",
		L"wugargar/smallbaby/2.png",
		L"wugargar/smallbaby/3.png",
		L"wugargar/smallbaby/4.png",
		L"wugargar/smallbaby/5.png",
		L"wugargar/smallbaby/6.png",
		L"wugargar/smallbaby/7.png",
		L"wugargar/smallbaby/8.png",
		L"wugargar/smallbaby/9.png",
		L"wugargar/smallbaby/10.png");
	SetRandomPositionInFarm();
	AddChild(m_pSmallBaby,100);
}

void CHumanInFarm::SetRandomPositionInFarm()
{
	int random_location_x = rand() % (SIZE_OF_HUMAN_FARM_X - 100);
	int random_location_y = rand() % (SIZE_OF_HUMAN_FARM_Y - 50);

	m_pSmallBaby->SetPosition( NNPoint(random_location_x + 20.0f, FIRST_Y_COORDINATE_OF_UIBUTTON + random_location_y) );
}
