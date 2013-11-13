#include "Player.h"

CPlayer* CPlayer::m_pInstance = nullptr;

CPlayer::CPlayer(void)
{
	InitPlayer();
}


void CPlayer::InitPlayer()
{
	//초기화 내용 추가
	m_GlobalMoney = 0;
	m_ClearedStage = 0;
	m_TotalKill = 0;
	m_TotalLoss = 0;
	for (int i=0 ; i<NUMBER_OF_ZOMBIE_TYPES ; ++i) {
		m_CharacterLevel[i] = 0;
	}
}


CPlayer::~CPlayer(void)
{
}

CPlayer* CPlayer::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new CPlayer();
	}

	return m_pInstance;
}

void CPlayer::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

void CPlayer::SetPlayerForNewStage()
{
	m_LocalMoney = 0;
	m_NumberOfKillInStage = 0;
	m_NumberOfLossInStage = 0;
}
