#include "Player.h"

CPlayer* CPlayer::m_pInstance = nullptr;

CPlayer::CPlayer(void)
{

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

bool CPlayer::Init()
{
	//초기화 내용 추가
	return true;
}

