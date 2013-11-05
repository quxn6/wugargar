#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "NNMacroSet.h"
#include "Base.h"

// x, y타일 한칸의 크기를 50으로 설정했다.
// background(하늘)이 끝나고 타일이 시작되는 지점을 First y coordinate으로 지정한다.
// max size x는 타일의 갯수를 의미한다. 가로 사이즈가 1024이므로 24를 위해 1칸정도 더 여유를 준다.
// 세로 방향으로는 6 * 50 = 300의 크기를 가진다. 520 pixel~ 730까지는 UI가 사용한다.

#define MAP_SIZE_X	21
#define MAP_SIZE_Y	6
#define FIRST_Y_COORDINATE_OF_MAPTILE	220
#define TILE_SIZE_X	50
#define TILE_SIZE_Y	50

enum MapType{
	TILE = 0x1,
	ZOMBIE_BASE = 0x2,
	POLICE_STATION = 0x4,	
};

inline MapType operator | (MapType a, MapType b)
{return static_cast<MapType>(static_cast<int>(a) | static_cast<int>(b));}

class CMapCreator :	public NNObject
{
public:
	CMapCreator(void);
	virtual ~CMapCreator(void);

public:
	void Render();
	void Update( float dTime );	
	void SetMap( void );

	CBase* GetZombieBase(void) { return m_pZombieBase; }
	CBase* GetPoliceBase(void) { return m_pPoliceBase; }

	NNCREATE_FUNC(CMapCreator);

private: 
	void initMap(bool fromFile);	
	void SetTileSprite(int x_coord, int y_coord, std::wstring* imagePath);
	void GetImagePathFromMapData(int x_coord, int y_coord, std::wstring* imagePath);
	void BuildBase(int x_coord, int y_coord, CharacterIdentity identity);
	
private:
	CBase*		m_pZombieBase;
	CBase*		m_pPoliceBase;
	MapType		m_Map[MAP_SIZE_X][MAP_SIZE_Y];
	NNSprite*	m_pSprites[MAP_SIZE_X][MAP_SIZE_Y];
};

