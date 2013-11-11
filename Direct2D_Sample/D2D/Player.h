#pragma once

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

	bool Init();

	int GetGlobalMoney(){return m_GlobalMoney;}
	int GetLocalMoney(){return m_LocalMoney;}
	int GetClearedStage() {return m_ClearedStage;}

	void SetGlobalMoney(int globalMoney) {m_GlobalMoney = globalMoney;}
	void SetLocalMoney(int localMoney) {m_GlobalMoney = localMoney;}
	void SetClearedStage(int ClearedStage) {m_ClearedStage = ClearedStage;}
	
private:
	int m_GlobalMoney;
	int m_LocalMoney;
	int m_ClearedStage;		//201, 301 등으로 진행된 스테이지 표시
	//업데이트 현황 가지고 있기

};

