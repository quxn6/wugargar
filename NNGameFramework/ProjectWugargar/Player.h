#pragma once
#include "GameConfig.h"


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
	void SetPlayerForNewStage();

	int GetGlobalMoney(){return m_GlobalMoney;}
	int GetLocalMoney(){return m_LocalMoney;}
	int GetClearedStage() {return m_ClearedStage;}
	int GetZombieLevel(ZombieType character) { return m_CharacterLevel[character]; }
	int GetNumberOfKillInStage() const { return m_NumberOfKillInStage; }
	int GetNumberOfLossInStage() const { return m_NumberOfLossInStage; }

	void SetGlobalMoney(int globalMoney) {m_GlobalMoney = globalMoney; }
	void SetLocalMoney(int localMoney) {m_LocalMoney = localMoney; }
	void SetClearedStage(int ClearedStage) {m_ClearedStage = ClearedStage; }
	void SetZombieLevel(ZombieType character, int level) { m_CharacterLevel[character] = level; }
	void IncreaseZombieLevel(ZombieType character) { ++m_CharacterLevel[character] ; }
	void IncreaseNumberOfKillInStage() { ++m_NumberOfKillInStage; }
	void IncreaseNumberOfLossInStage() { ++m_NumberOfLossInStage; }

	
private:
	int m_LocalMoney;
	int m_NumberOfKillInStage;
	int m_NumberOfLossInStage;	
	// 이하는 save할 때 저장할 데이터들
	int m_CharacterLevel[NUMBER_OF_ZOMBIE_TYPES];
	int m_GlobalMoney;	
	int m_ClearedStage;		//201, 301 등으로 진행된 스테이지 표시
	int m_TotalKill;
	int m_TotalLoss;

};

