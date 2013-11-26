#pragma once
#include "GameConfig.h"

enum PlayerStatus {
	WIN,
	LOSE,
	ON_PLAYING,
	ON_MAINMENU,
	ON_UPGRADEMENU
};

class CPlayer
{

private:
	static CPlayer* m_pInstance;

	CPlayer(void);
	virtual ~CPlayer(void);

public:
	static CPlayer* GetInstance();
	static void ReleaseInstance();

public:

	void InitPlayer();
	void ReadyToPlay();
	void ReadyToUpgrade();

	int GetGlobalMoney(){return m_GlobalMoney;}
	int GetLocalMoney(){return m_LocalMoney;}
	int GetClearedStage() {return m_CurrentStage;}
	int GetZombieLevel(ZombieType character) { return m_CharacterLevel[character]; }
	int GetNumberOfKillInStage() const { return m_NumberOfKillInStage; }
	int GetNumberOfLossInStage() const { return m_NumberOfLossInStage; }
	PlayerStatus GetPlayerStatus() const { return m_playerStatus; }

	void SetGlobalMoney(int globalMoney) {m_GlobalMoney = globalMoney; }
	void SetLocalMoney(int localMoney) {m_LocalMoney = localMoney; }
	void SetClearedStage(int ClearedStage) {m_CurrentStage = ClearedStage; }
	void SetZombieLevel(ZombieType character, int level) { m_CharacterLevel[character] = level; }
	void SetPlayerStatus(PlayerStatus ps) { m_playerStatus = ps; }

	void IncreaseZombieLevel(ZombieType character) { ++m_CharacterLevel[character] ; }
	void IncreaseNumberOfKillInStage() { ++m_NumberOfKillInStage; }
	void IncreaseNumberOfLossInStage() { ++m_NumberOfLossInStage; }	
	void IncreaseStage() {++m_CurrentStage;}
	void NextCity() {m_CurrentStage += 100;}

	
private:
	int m_LocalMoney;
	int m_NumberOfKillInStage;
	int m_NumberOfLossInStage;	
	// 이하는 save할 때 저장할 데이터들
	int m_CharacterLevel[NUMBER_OF_ZOMBIE_TYPES];
	int m_GlobalMoney;	
	int m_CurrentStage;		//201, 301 등으로 진행된 스테이지 표시
	int m_TotalKill;
	int m_TotalLoss;
	PlayerStatus m_playerStatus;
};

