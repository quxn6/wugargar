#include "PoorZombie.h"
#include <time.h>
#include <stdlib.h>

CPoorZombie::CPoorZombie(void)
{
	m_PoorZombie = NNSprite::Create( L"wugargar/poor_zombie.png");
	this->GetRandomPosition();
	AddChild( m_PoorZombie );
}


CPoorZombie::~CPoorZombie(void)
{

}

void CPoorZombie::Render()
{
	NNObject::Render();
}

void CPoorZombie::Update( float dTime )
{

}

void CPoorZombie::GetRandomPosition()
{
	srand((unsigned int)time(NULL));
	int random_location_x = rand() % 100;
	int random_location_y = rand() % 200;

	m_PoorZombie->SetPosition((700.0f+random_location_x),(300.0f+random_location_y));

}

/*CPolice * CPoorZombie::GetCloserEnemy()
{

}*/
