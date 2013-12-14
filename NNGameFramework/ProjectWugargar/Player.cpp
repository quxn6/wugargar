#include "Player.h"

CPlayer* CPlayer::m_pInstance = nullptr;

CPlayer::CPlayer(void)
{
	InitPlayer();
}


void CPlayer::InitPlayer()
{
	//초기화 내용 추가
	m_PlayerName = "player1";
	m_playerStatus = ON_MAINMENU;
	m_GlobalMoney = 1000;
	m_CurrentStage = 101;
	m_TotalKill = 0;
	m_TotalLoss = 0;
	m_InfectionRate = 20.0f;
	m_pMeatPoint = 50;
	m_CurrentStage = 1;
	m_playingStage = 1;

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

void CPlayer::ReadyToPlay()
{
	m_playerStatus = ON_PLAYING;
	m_LocalMoney = 2000;
	m_NumberOfKillInStage = 0;
	m_NumberOfLossInStage = 0;
}

void CPlayer::ReadyToUpgrade()
{
	m_playerStatus = ON_UPGRADEMENU;
	m_TotalKill += m_NumberOfKillInStage;
	m_TotalLoss += m_NumberOfLossInStage;
	m_GlobalMoney += 10 * m_NumberOfKillInStage;
}

