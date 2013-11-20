#pragma once

#define GAME_SCREEN_MIN_SIZE_X	0
#define GAME_SCREEN_MAX_SIZE_X	1024
#define GAME_SCREEN_MIN_SIZE_Y	0
#define GAME_SCREEN_MAX_SIZE_Y	768

// 아래 정의 된 #define값들은 playScene의 화면출력 관련 값들이다.
// x, y타일 한칸의 크기를 50으로 설정했다.
// background(하늘)이 끝나고 타일이 시작되는 지점을 First y coordinate으로 지정한다.
// max size x는 타일의 갯수를 의미한다. 가로 사이즈가 1024이므로 24를 위해 1칸정도 더 여유를 준다.
// 세로 방향으로는 6 * 50 = 300의 크기를 가진다. 520 pixel~ 730까지는 UI가 사용한다.
#define FIRST_Y_COORDINATE_OF_BACKGROUND	0
#define FIRST_Y_COORDINATE_OF_MAPTILE		270
#define MAP_SIZE_X	21
#define MAP_SIZE_Y	6
#define TILE_SIZE_X	50
#define TILE_SIZE_Y	50
#define SIZE_OF_UI_BACKGROUND_X				450
#define SIZE_OF_HUMAN_FARM					GAME_SCREEN_MAX_SIZE_X - SIZE_OF_UI_BACKGROUND_X //574
#define FIRST_X_COORDINATE_OF_UIBUTTON		SIZE_OF_HUMAN_FARM
#define FIRST_Y_COORDINATE_OF_UIBUTTON		FIRST_Y_COORDINATE_OF_MAPTILE + TILE_SIZE_Y * MAP_SIZE_Y // 520
#define SECOND_Y_COORDINATE_OF_UIBUTTON		FIRST_Y_COORDINATE_OF_UIBUTTON + GAP_BETWEEN_UIBUTTONS_Y
#define GAP_BETWEEN_UIBUTTONS	10
#define GAP_BETWEEN_UIBUTTONS_Y 10
#define SIZE_OF_UIBUTTON		100
#define NUM_OF_UIBUTTON_IN_ROW 4
#define NUM_OF_UIBUTTON 8

// 좀비 생성시 타입을 알아보기 위한 enum값 - 채원
// array에서 사용하므로 각각의 enum에 상수를 할당하지 말 것. - 성환
enum ZombieType // 버튼 생성할때도 이 enum값을 사용하기 때문에 버튼 init을 위해 마지막에 어쩔수없이 좀비가 아닌 BABY를 추가함. 
				//대신 image_path 배열 생성을 위해 NUM_OF_UIBUTTON 을 define 해줌 - 채원
{
	POOR_ZOMBIE,
	VOMIT_ZOMBIE,
	MUSCLE_ZOMBIE,
	KAMIKAJE_ZOMBIE,
	SMOG_ZOMBIE,
	ICE_ZOMBIE,
	HERO_ZOMBIE_SM9,
	NUMBER_OF_ZOMBIE_TYPES,
	BABY_HUMAN
}; 
