#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNMacroSet.h"

#include "GameConfig.h"
#include "Character.h"


class CBase;

enum MapType{
	TILE = 0x1,
	ZOMBIE_BASE = 0x2,
	POLICE_STATION = 0x4,	
};

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
	CBase		*m_pZombieBase;
	CBase		*m_pPoliceBase;
	MapType		m_Map[MAP_SIZE_X][MAP_SIZE_Y];
	NNSprite	*m_pSprites[MAP_SIZE_X][MAP_SIZE_Y];
};

