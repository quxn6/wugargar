#include "Lightning.h"
#include "GameConfig.h"

#define LIGHTNING_SPEED 30

CLightning::CLightning(void)
{
	InitSprite(L"wugargar/pika.png");
}


CLightning::~CLightning(void)
{
}

void CLightning::Render()
{
	NNObject::Render();
}

void CLightning::Update( float dTime )
{
	
	if(this->GetPositionX() < GAME_SCREEN_MAX_SIZE_X - 20)
		SetPosition(this->GetPosition() + NNPoint(LIGHTNING_SPEED, 0.0f) * dTime);
	else
		SetPosition(0.0f, POSITION_OF_LIGHTNING);


}

void CLightning::InitSprite( std::wstring imagePath )
{
	m_lightning_sprite = NNSprite::Create(imagePath);


	
	m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);	
	AddChild(m_lightning_sprite, 1);

}
