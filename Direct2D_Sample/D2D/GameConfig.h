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
#define FIRST_Y_COORDINATE_OF_MAPTILE		220
#define MAP_SIZE_X	21
#define MAP_SIZE_Y	6
#define TILE_SIZE_X	50
#define TILE_SIZE_Y	50
#define FIRST_Y_COORDINATE_OF_UIBUTTON		FIRST_Y_COORDINATE_OF_MAPTILE + TILE_SIZE_Y * MAP_SIZE_Y // 520
#define GAP_BETWEEN_UIBUTTONS	15
#define SIZE_OF_UIBUTTON		150


enum ZombieType
{
	POOR_ZOMBIE,
	VOMIT_ZOMBIE,
	MUSCLE_ZOMBIE,
	KAMIKAJE_ZOMBIE,
	SMOG_ZOMBIE,
	ICE_ZOMBIE,
	NUMBER_OF_ZOMBIE_TYPES
}; 
