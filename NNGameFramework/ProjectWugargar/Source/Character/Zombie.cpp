#include "Zombie.h"
#include "PlayScene.h"


CZombie::CZombie(void)
{
//	enemyList = &(CPlayScene::GetInstance()->GetPoliceList());
}


CZombie::~CZombie(void)
{
}

void CZombie::Render()
{

}

void CZombie::Update( float dTime )
{

}

void CZombie::ApplyZombieLevel()
{
	CPlayer* player = CPlayer::GetInstance();
	int currentZombieLevel = player->GetZombieLevel(m_zombieType);

	m_HealthPoint += m_HealthPoint/10*currentZombieLevel;
	m_AttackPower += m_AttackPower/5 *currentZombieLevel;
	m_DefensivePower += m_DefensivePower/5 + currentZombieLevel;
}

