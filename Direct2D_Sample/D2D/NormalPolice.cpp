#include "NormalPolice.h"



CNormalPolice::CNormalPolice(void)
{
	m_normalPolice = NNSprite::Create( L"wugargar/cap.jpg");
	this->GetRandomPosition();
	AddChild( m_normalPolice );
}


CNormalPolice::~CNormalPolice(void)
{
}

void CNormalPolice::GetRandomPosition()
{
	srand((unsigned int)time(NULL));
	int random_location_x = rand()%100;
	int random_location_y = rand()%200;

	m_normalPolice->SetPosition((700.0f+random_location_x),(300.0f+random_location_y));

}

void CNormalPolice::Render()
{
	NNObject::Render();
}

void CNormalPolice::Update( float dTime )
{

}
