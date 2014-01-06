#pragma once

#include "GameConfig.h"
#include "headers.h"

enum PlayerStatus {
	PLAYER_WIN,
	PLAYER_LOSE,
	PLAYER_ON_PLAYING,
	PLAYER_ON_MAINMENU,	
	PLAYER_ON_RESULT,
	PLAYER_ON_UPGRADEMENU
};


//Player의 정보들을 나타내주는 클래스
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
	void ReadyToSave();
	
	int GetGlobalMoney(){return m_GlobalMoney;}
	int GetLocalMoney(){return m_LocalMoney;}
	int GetClearedStage() const { return m_ClearedStage; }
	int GetZombieLevel(ZombieType character) { return m_CharacterLevel[character]; }
	int GetNumberOfKillInStage() const { return m_NumberOfKillInStage; }
	int GetNumberOfLossInStage() const { return m_NumberOfLossInStage; }
	PlayerStatus GetPlayerStatus() const { return m_playerStatus; }
	float GetInfectionRate() const { return m_InfectionRate; }
	std::string GetPlayerName() const { return m_PlayerName; }
	int GetTotalLoss() const { return m_TotalLoss; }
	int GetTotalKill() const { return m_TotalKill; }
	float GetEarningInterval() const { return m_EarningInterval; }
	

	void SetGlobalMoney(int globalMoney) {m_GlobalMoney = globalMoney; }
	void SetLocalMoney(int localMoney) {m_LocalMoney = localMoney; }
	void SetCurrentStage(int ClearedStage) {m_ClearedStage = ClearedStage; }
	void SetZombieLevel(ZombieType character, int level) { m_CharacterLevel[character] = level; }
	void SetPlayerStatus(PlayerStatus ps) { m_playerStatus = ps; }
	void SetInfectionRate(float ir) { m_InfectionRate = ir; }
	void SetPlayerName(std::string val) { m_PlayerName = val; }
	void SetTotalLoss(int val) { m_TotalLoss = val; }
	void SetTotalKill(int val) { m_TotalKill = val; }
	void SetClearedStage(int val) { m_ClearedStage = val; }
	void SetEarningInterval(float val) { m_EarningInterval = val; }

	void IncreaseZombieLevel(ZombieType character) { ++m_CharacterLevel[character] ; }
	void IncreaseNumberOfKillInStage() { ++m_NumberOfKillInStage; }
	void IncreaseNumberOfLossInStage() { ++m_NumberOfLossInStage; }	
	void IncreaseInfectionRate() {m_InfectionRate += 10.0f; }
	void IncreaseLocalMoney(int amount) {m_LocalMoney += amount;}
	void IncreaseClearedStage() {++m_ClearedStage;}
	void IncreaseEarningInterval() {m_EarningInterval*=0.75f;}

	void SetMeatPoint(int meatPoint) { m_MeatPoint = meatPoint;}
	int GetMeatPoint() { return m_MeatPoint;}

	void SetPlayingStage(int set){m_playingStage = set;}
	int GetPlayingStage(){return m_playingStage;}
	

private:
	PlayerStatus m_playerStatus;
	std::string m_PlayerName;
	int m_LocalMoney;
	int m_MeatPoint;
	int m_NumberOfKillInStage;
	int m_NumberOfLossInStage;	

	int m_playingStage;

	// 이하는 save할 때 저장할 데이터들
	int m_CharacterLevel[NUMBER_OF_ZOMBIE_TYPES];
	int m_GlobalMoney;	
	int m_ClearedStage;		//1,2,3,4 등으로 진행된 스테이지 표시
	int m_TotalKill;
	int m_TotalLoss;
	float m_EarningInterval;
	float m_InfectionRate;
	
	

};

