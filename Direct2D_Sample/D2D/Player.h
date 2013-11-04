#pragma once
class CPlayer
{

private:
	static CPlayer* m_pInstance;

public:
	CPlayer(void);
	~CPlayer(void);

public:
	static CPlayer* GetInstance();
	static void ReleaseInstance();

public:
	bool Init();

private:
	int m_globalMoney;
	float m_clearedStage;//2.1, 3.4 등으로 진행된 스테이지 표시하려고
	//업데이트 현황 가지고 있기

public:
	int GetGlobalMoney(){return m_globalMoney;};
	float GetClearedStage() {return m_clearedStage;};
	
	void SetGlobalMoney(int money) {m_globalMoney = money;};
	void SetClearedStage(float ClearedStage) {m_clearedStage = ClearedStage;};

};

