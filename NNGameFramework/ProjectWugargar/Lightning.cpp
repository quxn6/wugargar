#include "Lightning.h"

#include "NNInputSystem.h"
#include "NNSound.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNSprite.h"

#include "GameConfig.h"

#include "PlayScene.h"
#include "MapCreator.h"
#include "Character.h"
#include "Base.h"
#include "MapObstacle.h"
#include "Player.h"


#define CLOUD_SPEED 130
#define FALLING_FIGHTNING_SPEED 230
#define LIGHTNINIG_DAMAGE 100
#define PAY_LIGHTNING 100
#define LIGHTNING_COOL_TIME 5000

CLightning::CLightning(void)
{
	InitSprite(L"wugargar/pika.png");
	m_is_fall_lightning = false;
	m_lightning_damage = LIGHTNINIG_DAMAGE;
	m_pay_lightning = PAY_LIGHTNING;
	m_startTime = clock();
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

	if(m_cloudSprite->GetPositionX() 
		< GAME_SCREEN_MAX_SIZE_X - 20 && !m_is_fall_lightning)
		m_cloudSprite->SetPosition
		(m_cloudSprite->GetPosition() 
		+ NNPoint(CLOUD_SPEED, 0.0f) * dTime);

	else if(!m_is_fall_lightning)
		m_cloudSprite->SetPosition(0.0f, POSITION_OF_CLOUD);


	m_currentTime = clock();
	if((NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_DOWN) && !m_is_fall_lightning
		&& (m_currentTime-m_startTime > LIGHTNING_COOL_TIME))
	{
		m_lightning_sprite->SetPosition(m_cloudSprite->GetPosition() - NNPoint(200,0));
		m_lightning_sprite->SetVisible(true);
		m_is_fall_lightning = true;
		m_startTime = m_currentTime;

		for (const auto& child : *CPlayScene::GetInstance()->GetPoliceList())
		{
			if(child != CPlayScene::GetInstance()->
				GetMapCreator()->GetPoliceBase())

				if(IsCrash(child))
				{
					child->SetHP(child->GetHP() - m_lightning_damage);
					m_stopTime = m_currentTime;
					break;
				}
			m_stopTime = m_currentTime;
		}
	}

	if(m_is_fall_lightning && m_currentTime - m_stopTime > 2000)
	{
		m_is_fall_lightning = false;
		m_lightning_sprite->SetVisible(false);

	}
}

	////가만히 있으면 번개는 왼쪽으로 이동. 왼쪽 끝까지 이동하면 오른쪽 끝으로 다시 셋팅.
	//if(m_lightning_sprite->GetVisible());

	//else if(m_cloudSprite->GetPositionX() 
	//	< GAME_SCREEN_MAX_SIZE_X - 20 && !m_is_fall_lightning)
	//	m_cloudSprite->SetPosition
	//	(m_cloudSprite->GetPosition() 
	//	+ NNPoint(LIGHTNING_SPEED, 0.0f) * dTime);
	//
	//else if(!m_is_fall_lightning)
	//	m_cloudSprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
	//
	//
	//

	//m_currentTime = clock();
	//
	////Space바가 눌렸는지를 체크. 눌렸으면 Flag를 True로 바꿔준다.
	//if(NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_DOWN && !m_fall_lightning_sprite && (m_currentTime-m_startTime > LIGHTNING_COOL_TIME))
	//{
	//	printf_s("put");
	//	m_is_fall_lightning = true;
	//	m_startTime = m_currentTime;
	//	
	//}

	////현재 '떨어지고 있는 상태'라면 번개의 위치를 지속적으로 아래로 떨어지도록 변경
	//if(m_is_fall_lightning)
	//{
	//	//m_lightning_sprite->SetPosition
	//	//	(m_lightning_sprite->GetPosition() + NNPoint(0.0f, LIGHTNING_SPEED) *dTime);
	//	//Zombie와 Police를 돌면서 충돌 체크. 충돌하면 flag를 false로 바꾸고, 데미지 주고 번개 위치는 다시 0,0으로 셋팅
	//	m_lightning_sprite->SetPosition(m_cloudSprite->GetPosition() - NNPoint(50,0));
	//	m_lightning_sprite->SetVisible(true);
	//	

	//	//Police만 맞도록 수정
	//	//for (const auto& child : *CPlayScene::GetInstance()->GetZombieList())
	//	//{
	//	//	//List에 Base가 존재. Base는 번개에 의해 데미지를 받으면 안되므로 제외하도록 설정
	//	//	if(child != CPlayScene::GetInstance()->
	//	//		GetMapCreator()->GetZombieBase())
	//	//		if(IsCrash(child))
	//	//		{
	//	//			child->SetHP(child->GetHP() - m_lightning_damage);
	//	//			m_is_fall_lightning = false;
	//	//				
	//	//			m_lightning_sprite->
	//	//				SetPosition(0.0f, POSITION_OF_LIGHTNING);
	//	//			break;
	//	//		}	
	//	//}
	//	
	//	for (const auto& child : *CPlayScene::GetInstance()->GetPoliceList())
	//	{
	//		if(child != CPlayScene::GetInstance()->
	//			GetMapCreator()->GetPoliceBase())
	//			if(IsCrash(child))
	//			{
	//				child->SetHP(child->GetHP() - m_lightning_damage);
	//				m_is_fall_lightning = false;

	//				m_lightning_sprite->
	//					SetPosition(0.0f, POSITION_OF_LIGHTNING);
	//				break;
	//			}
	//	}
	//	m_is_fall_lightning = false;

	//	
	//	////번개가 아무에게도 맞지 않고 아래로 끝까지 떨어지면 소멸 처리.
	//	//if(m_lightning_sprite->GetPositionY() >= FIRST_Y_COORDINATE_OF_UIBUTTON)
	//	//{
	//	//	m_is_fall_lightning = false;

	//	//	m_lightning_sprite->SetPosition(0.0f, POSITION_OF_LIGHTNING);
	//	//}

	//}

	////연출을 위해 2초간 정지
	//if(m_lightning_sprite->GetVisible() && m_currentTime - m_startTime > 2000){
	//	m_lightning_sprite->SetVisible(false);
	//}


void CLightning::InitSprite( std::wstring imagePath )
{
	m_lightning_sprite = NNSprite::Create(L"wugargar/Lightning.png");
	m_lightning_sprite->SetVisible(false);
	m_lightning_sprite->SetPosition(0.0f, POSITION_OF_CLOUD);	
	AddChild(m_lightning_sprite, 1);

	m_cloudSprite = NNSprite::Create(L"wugargar/Cloud.png");
	m_cloudSprite->SetPosition(0.0f, POSITION_OF_CLOUD);
	AddChild(m_cloudSprite, 1);


}

/*
충돌 체크 함수. 현재는 임의로 둘 사이의 거리가 10정도로 가까워질때 반응하도록 되어있음.
좀 더 정밀해지도록 로직 수정이 필요할 듯.
*/
bool CLightning::IsCrash( CCharacter *crash_check_character)
{
	printf_s("police : %f",crash_check_character->GetPositionX());
	printf_s("cloud : %f", m_cloudSprite->GetPositionX());
	float distane = m_cloudSprite->GetPositionX() - crash_check_character->GetPositionX();
	printf_s("Distance : %f", distane);

	if(distane <=150 && distane >= -150)
		return true;

	return false;
/*
	float distance_attacktarget;
	distance_attacktarget = m_lightning_sprite->
		GetPosition().GetDistance(crash_check_character->GetPosition());

	if(distance_attacktarget <= 50){
		printf_s("LightningAttack!\n");
		return true;
		}

	return false;
*/
}
