#include "Lightning.h"
#include "GameConfig.h"
#include "NNInputSystem.h"

#define LIGHTNING_SPEED 130

CLightning::CLightning(void)
{
	InitSprite(L"wugargar/pika.png");
	m_is_fall_lightning = false;
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
	
	if(m_lightning_sprite->GetPositionX() < GAME_SCREEN_MAX_SIZE_X - 20)
		m_lightning_sprite->SetPosition(m_lightning_sprite->GetPosition() + NNPoint(LIGHTNING_SPEED, 0.0f) * dTime);
	else
		m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
	if(NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_DOWN && !m_fall_lightning_sprite)
	{
		printf_s("put");
		m_fall_lightning_sprite = NNSprite::Create(L"wugargar/pika.png");
		m_fall_lightning_sprite->SetPosition(m_lightning_sprite->GetPosition());
		AddChild(m_fall_lightning_sprite);
		m_is_fall_lightning = true;
	}

	if(m_is_fall_lightning)
	{
		m_fall_lightning_sprite->SetPosition(m_fall_lightning_sprite->GetPositionX(), m_fall_lightning_sprite->GetPositionY()-LIGHTNING_SPEED);
		//if(m_fall_lightning_sprite->GetPositionX())

	}
}

void CLightning::InitSprite( std::wstring imagePath )
{
	m_lightning_sprite = NNSprite::Create(imagePath);


	m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);	
	AddChild(m_lightning_sprite, 1);

}
