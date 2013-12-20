
#include "NNResourceManager.h"

#include "PoliceCreator.h"
#include "PlayScene.h"
#include "PrintConsole.h"
#include "Police.h"
#include "Player.h"

CPoliceCreator::CPoliceCreator(void)
{
	begin_time = clock();
	tableTopIndex = 0;
	LoadScriptFromFile();
	
	//printf_s("CreatePolice 생성자\n");
	//printf_s("beginetime : %d\n", begin_time);
}


CPoliceCreator::~CPoliceCreator(void)
{
	SafeArrayDelete<PoliceTable>(m_aCreateEnemyTable);
	SafeArrayDelete<float>(m_aPoliceScriptCallTime);
}

/*
함수명 : ReturnTableByFile
반환값 : 지정된 파일에서 CreateEnemyTable의 형식에 맞춰 데이터를 삽입하고 반환
**현재 임시로 직접 값을 넣어줌. 차후 파일 I/O로 수정될 예정
*/
void CPoliceCreator::LoadScriptFromFile()
{
	NNXML *create_police_xml;

	//create_police_xml = NNResourceManager::GetInstance()->LoadXMLFromFIle("XML/Stage/PoliceCreatorScript.txt");
	create_police_xml = NNResourceManager::GetInstance()->LoadXMLFromFIle("XML/Stage/StageInfo.txt");
	int current_stage = CPlayer::GetInstance()->GetPlayingStage();
	std::string Xpath = "/StageInfo/Stage" + std::to_string(current_stage);
	m_NumStageInfo = std::stoi(create_police_xml->XPathToString(Xpath + "/StageInfoNum/text()").c_str());
	
	m_aCreateEnemyTable = new PoliceTable[m_NumStageInfo];
	m_aPoliceScriptCallTime = new float[m_NumStageInfo];
	ZeroMemory(m_aPoliceScriptCallTime,m_NumStageInfo);
	Xpath.append("/StageInfo");
	
	for (int idx=0; idx<m_NumStageInfo; ++idx) {
		m_aCreateEnemyTable[idx].time = std::stoi(create_police_xml->XPathToString(Xpath + std::to_string(idx+1) + "/Time/text()").c_str());
		m_aCreateEnemyTable[idx].enemy_type = (PoliceType)std::stoi(create_police_xml->XPathToString(Xpath + std::to_string(idx+1) + "/PoliceType/text()").c_str());
	}
}


/*
함수명 : CreateEnemy
반환값 : void
지정된 CreateEnemyTable의 정보대로 Police를 생성
주요 로직 : gap_time(현재 시간과 프로그램 시작 시간을 뺸 것으로 초(sec)로 환산한 것)에 따라
			gap_time이 지정된 테이블의 생성 시간보다 큰 경우 지정된 갯수만큼 지정된 타입의 경찰 생성
			생성후엔 index를 늘려주어 다음에 지정된 부분으로 이동하게 함.
*/
PoliceType CPoliceCreator::ReturnCreateEnemyInfo()
{	
	
	if((tableTopIndex) >= m_NumStageInfo)
		return NONE_POLICE;

	current_time = clock();
	
	gap_time = (int)(current_time - begin_time);

	if((gap_time) >= m_aCreateEnemyTable[tableTopIndex].time){
		//++tableTopIndex;
		return m_aCreateEnemyTable[tableTopIndex++].enemy_type;
	}

	return NONE_POLICE;
}

// 지금 뱉어야할 폴리스가 있다면 폴리스를 리턴, 아니라면 null 리턴
CPolice* CPoliceCreator::CreatePoliceOnTime( float stageElapsedTime )
{
	CPolice* returnPolice = nullptr;
	for ( int i=0 ; i<m_NumStageInfo ; ++i ) {
		if (stageElapsedTime - m_aPoliceScriptCallTime[i] > m_aCreateEnemyTable[i].time ) {
			// 해당 script phase의 police생성 시간을 기록
			m_aPoliceScriptCallTime[i] = stageElapsedTime;

			// 새로운 police 객체를 생성하고 그 포인터를 반환
			returnPolice = CPolice::Create();
			returnPolice->initStatus(
				CCharacterConfig::GetInstance()->GetCharacterInfo(POLICE),
				m_aCreateEnemyTable[i].enemy_type);
			return returnPolice;
		}
	}
	// 없다면 null을 반환하게 될거임
	return returnPolice;
}



//void CCreatePolice::SetCreateInfoByXML( NNXML *StageXML )
//{
//	int num_info = std::stoi(StageXML->XPathToString("/stage/StageInfoNum/text()").c_str());
//	create_enemy_table = new CreateEnemyTable[num_info];
//	std::string tmp_path = "/stage/StageInfo";
//
//
//	for(int idx=0; idx<num_info; ++idx)
//	{
//		tmp_path.append(std::to_string(idx));
//		std::string tmp_time_path = tmp_path;
//		std::string tmp_type_path = tmp_path;
//		tmp_time_path.append("/Time/text()");
//		tmp_type_path.append("/PoliceType/text()");
//
//		create_enemy_table[idx].time = std::stoi(StageXML->XPathToString(tmp_time_path.c_str()));
//		create_enemy_table[idx].enemy_type = (PoliceType)std::stoi(StageXML->XPathToString(tmp_type_path.c_str()));
//	}
//
//
//
//}	

