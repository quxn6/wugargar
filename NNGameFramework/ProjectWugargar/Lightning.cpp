#include "Lightning.h"
#include "GameConfig.h"
#include "NNInputSystem.h"
#include "PlayScene.h"

#define LIGHTNING_SPEED 130

CLightning::CLightning(void)
{
	InitSprite(L"wugargar/pika.png");
	m_is_fall_lightning = false;
	m_lightning_damage = 100;
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
	
	if(m_lightning_sprite->GetPositionX() < GAME_SCREEN_MAX_SIZE_X - 20 && !m_is_fall_lightning)
		m_lightning_sprite->SetPosition(m_lightning_sprite->GetPosition() + NNPoint(LIGHTNING_SPEED, 0.0f) * dTime);
	else if(!m_is_fall_lightning)
		m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
	if(NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_DOWN && !m_fall_lightning_sprite)
	{
		printf_s("put");
		/*m_fall_lightning_sprite = NNSprite::Create(L"wugargar/pika.png");
		m_fall_lightning_sprite->SetPosition(m_lightning_sprite->GetPosition());
		AddChild(m_fall_lightning_sprite, 1);
		*/
		m_is_fall_lightning = true;
		
	}

	if(m_is_fall_lightning)
	{
		m_lightning_sprite->SetPosition(m_lightning_sprite->GetPosition() + NNPoint(0.0f, LIGHTNING_SPEED) *dTime);
		
		for (const auto& child : CPlayScene::GetInstance()->GetZombieList())
		{
			if(child != CPlayScene::GetInstance()->GetMapCreator()->GetZombieBase())
			if(IsCrash(child->GetSprite()))
			{
				child->SetHP(child->GetHP() - m_lightning_damage);
				m_is_fall_lightning = false;

				m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
				break;
			}
		}
		
		for (const auto& child : CPlayScene::GetInstance()->GetPoliceList())
		{
			if(child != CPlayScene::GetInstance()->GetMapCreator()->GetPoliceBase())
			if(IsCrash(child->GetSprite()))
			{
				child->SetHP(child->GetHP() - m_lightning_damage);
				m_is_fall_lightning = false;

				m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
				break;
			}
		}


		if(m_lightning_sprite->GetPositionY() >= FIRST_Y_COORDINATE_OF_UIBUTTON)
		{
			m_is_fall_lightning = false;

			m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
		/*	RemoveChild(m_lightning_sprite, true);
			m_lightning_sprite = false;
			printf_s("번개 소멸\n");*/
		}

	}
}

void CLightning::InitSprite( std::wstring imagePath )
{
	m_lightning_sprite = NNSprite::Create(imagePath);
	m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);	
	AddChild(m_lightning_sprite, 1);

}

/*
11.27 정인호
충돌 판정 함수. 현재 구동은 이 스프라이트가 대상 스프라이트 사이에
들어가면 충돌로 판정하도록 설정. 충돌하면 true, 아니면 false반환
*/
bool CLightning::IsCrash( NNSprite *crash_check_sprite)
{

	float distance_attacktarget;
	distance_attacktarget = this->GetPosition().GetDistance(crash_check_sprite->GetPosition());

	if(distance_attacktarget <= 5/*m_lightning_sprite->GetImageWidth()*/){
		printf_s("LightningAttack!\n");
		return true;
		}

	return false;

	/*if(((thi->GetCenterX() + thi->GetImageWidth()/2) > (crash_check_sprite->GetCenterX() - crash_check_sprite->GetImageWidth()/2)) &&
		(((thi->GetCenterX() + thi->GetImageWidth()/2) <= (crash_check_sprite->GetCenterX() + crash_check_sprite->GetImageWidth()/2)) &&
		((thi->GetCenterY() <= (crash_check_sprite->GetCenterY() + crash_check_sprite->GetImageHeight()/2)) &&
		((thi->GetCenterX() > (crash_check_sprite->GetCenterY() - crash_check_sprite->GetImageHeight()/2)) ))))
		return true;

	return false;

	*/
}
