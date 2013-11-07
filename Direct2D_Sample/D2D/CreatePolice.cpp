#include "CreatePolice.h"
#include "Police.h"
#include "NormalPolice.h"
#include "Wugargar.h"


CCreatePolice::CCreatePolice(void)
{
	begin_time = clock();
	table_top_index = 0;
	create_enemy_table = new CreateEnemyTable[5];
	ReturnTableByFile();
}


CCreatePolice::~CCreatePolice(void)
{

}


void CCreatePolice::Render()
{

}

void CCreatePolice::Update( float dTime )
{
}


/*
함수명 : ReturnTableByFile
반환값 : 지정된 파일에서 CreateEnemyTable의 형식에 맞춰 데이터를 삽입하고 반환
**현재 임시로 직접 값을 넣어줌. 차후 파일 I/O로 수정될 예정
*/
// 리턴하는 포인터가 local variable를 가리킴, local variable은 함수가 끝나면 사라지므로 결국 없는 값을 반환하게 됨.
// 수정 완료
void CCreatePolice::ReturnTableByFile()
{
	create_enemy_table[0].time = 2;
	create_enemy_table[0].enemy_type = NORMAL_POLICE;
	create_enemy_table[0].num_enemy = 1;
	create_enemy_table[1].time = 3;
	create_enemy_table[1].enemy_type = NORMAL_POLICE;
	create_enemy_table[1].num_enemy = 2;
	create_enemy_table[2].time = 5;
	create_enemy_table[2].enemy_type = NORMAL_POLICE;
	create_enemy_table[2].num_enemy = 3;
	create_enemy_table[3].time = 7;
	create_enemy_table[3].enemy_type = NORMAL_POLICE;
	create_enemy_table[3].num_enemy = 2;
	create_enemy_table[4].time = 10;
	create_enemy_table[4].enemy_type = NORMAL_POLICE;
	create_enemy_table[4].num_enemy = 1;


}


/*
함수명 : CreateEnemy
반환값 : void
지정된 CreateEnemyTable의 정보대로 Police를 생성
주요 로직 : gap_time(현재 시간과 프로그램 시작 시간을 뺸 것으로 초(sec)로 환산한 것)에 따라
			gap_time이 지정된 테이블의 생성 시간보다 큰 경우 지정된 갯수만큼 지정된 타입의 경찰 생성
			생성후엔 index를 늘려주어 다음에 지정된 부분으로 이동하게 함.
*/
void CCreatePolice::CreateEnemy()
{
	current_time = clock();

	gap_time = (int)(current_time - begin_time)/(CLOCKS_PER_SEC);


	CPolice *tmp_police;
	if((gap_time) >= create_enemy_table[table_top_index].time)
	{
		for(int idx=0; idx<create_enemy_table[table_top_index].num_enemy; ++idx)
		{
			switch (create_enemy_table[table_top_index].enemy_type)
			{
			case NORMAL_POLICE:
				tmp_police = CNormalPolice::Create();
				tmp_police->SetRandomPositionAroundBase();
				tmp_police->InitSprite(L"wugargar/normal_police.png");
				AddChild(tmp_police, 10);
				CWugargar::GetInstance()->GetPoliceList().push_back(tmp_police);
				break;
			case GUN_POLICE:
				break;
			case SHILD_POLICE:
				break;
			case HELLICOPTER:
				break;
			default:
				break;
			}
			
		}

		++table_top_index;
	}
}

