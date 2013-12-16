#pragma once
#include "NNObject.h"
#include "GameConfig.h"
#include "NNXML.h"
/*
클래스 이름 : CCreatePolice
클래스 목적 : 적(경찰)이 생성되는 기준을 세우고 해당 기준에 맞게
			경찰들이 생성되도록 함

최초 수정일 : 2013/11/03
최종 수정일 : 2013/11/04
*/


//적(경찰)의 타입. 이 타입에 맞춰서 해당하는 유닛을 생성함
//enum enemyType{
//	NOT_TIME,
//	NORMAL_POLICE,
//	GUN_POLICE,
//	SHILD_POLICE,
//	HELLICOPTER
//};

/*
구조체 : 스테이지의 경찰 출력 패턴을 나타냄.
지정된 시간(time)에 지정된 적의 타입(enemy_type)으로 지정된 적의 수(num_enemy)를 생성
*/


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
	void				LoadScript();


	int GetTableTopIndex() const { return tableTopIndex; }
	void SetTableTopIndex(int val) { tableTopIndex = val; }
	
	
private:
	PoliceTable *create_enemy_table;
	clock_t begin_time;
	clock_t current_time;
	int gap_time;
	int num_stage_info;
	int tableTopIndex;
};

