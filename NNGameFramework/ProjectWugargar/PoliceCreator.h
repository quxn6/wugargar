#pragma once
#include "NNObject.h"
#include "NNXML.h"

#include "GameConfig.h"
/*
클래스 이름 : CCreatePolice
클래스 목적 : 적(경찰)이 생성되는 기준을 세우고 해당 기준에 맞게
			경찰들이 생성되도록 함

최초 수정일 : 2013/11/03
최종 수정일 : 2013/11/04
*/


/*
구조체 : 스테이지의 경찰 출력 패턴을 나타냄.
지정된 시간(time)에 지정된 적의 타입(enemy_type)으로 지정된 적의 수(num_enemy)를 생성
*/

class CPolice;

struct PoliceTable
{
	int time;
	PoliceType enemy_type;
};


class CPoliceCreator
{
public:
	CPoliceCreator(void);
	virtual ~CPoliceCreator(void);
	
	NNCREATE_FUNC(CPoliceCreator);
	void				LoadScriptFromFile();
	PoliceType			ReturnCreateEnemyInfo();
	CPolice*			CreatePoliceOnTime(float stageElapsedTime);

// 	int GetNumStageInfo() const { return m_NumStageInfo; }
// 	int GetTableTopIndex() const { return tableTopIndex; }
// 	float* GetPoliceScriptCallTime() const { return m_aPoliceScriptCallTime; }
// 	
// 	void SetTableTopIndex(int val) { tableTopIndex = val; }
// 	void SetPoliceScriptCallTime(float time, int index) { m_aPoliceScriptCallTime[index] = time; }
// 	
private:
	PoliceTable *m_aCreateEnemyTable;
	float* m_aPoliceScriptCallTime;
	clock_t begin_time;
	clock_t current_time;
	int gap_time;
	int m_NumStageInfo;
	int tableTopIndex;
};

