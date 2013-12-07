#include "MapCreator.h"


CMapCreator::CMapCreator(void)
{
	initMap(false);
	SetMap();
}

CMapCreator::~CMapCreator(void)
{
}


// map의 rawdata를 초기화 함, 추후 map editor만들면 fromfile을 이용해 불러올 예정임
// input : bool file인지 아닌지?
// output : 음슴.
void CMapCreator::initMap( bool fromFile )
{
	if (fromFile) {
		//not implement yet;
	} else {
		// set Tiles		
		for ( int i=0 ; i<MAP_SIZE_X ; ++i ) {
			for ( int j=0 ; j<MAP_SIZE_Y ; ++j ) {
				m_Map[i][j] = TILE;
				m_pSprites[i][j] = nullptr;
			}
		}

		// set zombie base
		m_Map[1][3] = ZOMBIE_BASE;

		// set police station
		m_Map[MAP_SIZE_X-2][3] = POLICE_STATION;
		//경찰기지를 밑에쪽에 두면 어떨까?
		//	m_Map[MAP_SIZE_X-2][MAP_SIZE_Y-3] = POLICE_STATION_1;
	}
}

// map좌표마다 tile이미지(sprite)를 할당.
// input, output 음슴.
// sh
void CMapCreator::SetMap( void )
{
	std::wstring imagePath;

	for ( int i=0 ; i<MAP_SIZE_X ; ++i ) {
		for ( int j=0 ; j<MAP_SIZE_Y ; ++j ) {			
			GetImagePathFromMapData(i, j, &imagePath);
			SetTileSprite(i, j, &imagePath);
		}
	}
}


// 해당 좌표의 sprite Path를 선택하여 가져오는 함수. 
// 현재는 map에 TILE한 종류밖에 없으므로 큰 의미는 없다.
void CMapCreator::GetImagePathFromMapData( int x_coord, int y_coord, std::wstring* imagePath )
{
	switch (m_Map[x_coord][y_coord])
	{
	case TILE:
		// random으로 tile이미지를 바꾸는 것도 좋을 듯
		*imagePath = L"wugargar/tile01.png";		
		break;
	case ZOMBIE_BASE:
		*imagePath = L"wugargar/tile01.png";
		//*imagePath = L"wugargar/zombie_base.png";
		break;
	case POLICE_STATION:
		*imagePath = L"wugargar/tile01.png";
		break;
	default:
		break;
	}
}


// 특정 좌표에 sprite을 할당하는 내부함수
// tile의 x, y좌표 및 이미지path를 입력받고 add하는 부분까지 처리
void CMapCreator::SetTileSprite( int x_coord, int y_coord, std::wstring* imagePath )
{
 	m_pSprites[x_coord][y_coord] = NNSprite::Create(*imagePath);
 	m_pSprites[x_coord][y_coord]->SetPosition(static_cast<float>(x_coord * TILE_SIZE_X) , static_cast<float>(y_coord * TILE_SIZE_Y + FIRST_Y_COORDINATE_OF_MAPTILE) );
 	AddChild( m_pSprites[x_coord][y_coord], static_cast<int>(TILE) );

	if ( m_Map[x_coord][y_coord] == ZOMBIE_BASE ) {
		BuildBase(x_coord, y_coord, Zombie);
	}
	if ( m_Map[x_coord][y_coord] == POLICE_STATION ) {
		BuildBase(x_coord, y_coord, Police);
	}
}


void CMapCreator::BuildBase( int x_coord, int y_coord, CharacterIdentity identity)
{
	switch (identity)
	{
	case Zombie:		
		m_pZombieBase = CBase::Create();
		m_pZombieBase->SetIdentity(identity);
		m_pZombieBase->SetPosition(
			static_cast<float>(x_coord * TILE_SIZE_X), 
			static_cast<float>(y_coord * TILE_SIZE_Y + FIRST_Y_COORDINATE_OF_MAPTILE)
			);
		m_pZombieBase->InitSprite(L"wugargar/zombie_base.png");
		AddChild(m_pZombieBase, 10);

		break;
	case Police:		
		m_pPoliceBase = CBase::Create();
		m_pPoliceBase->SetIdentity(identity);
		m_pPoliceBase->SetPosition(
			static_cast<float>(x_coord * TILE_SIZE_X), 
			static_cast<float>(y_coord * TILE_SIZE_Y + FIRST_Y_COORDINATE_OF_MAPTILE)
			);
		m_pPoliceBase->InitSprite(L"wugargar/police_station.png");
		AddChild(m_pPoliceBase, 10);

		break;
	default:		
		break;
	}

}

void CMapCreator::Render()
{
	NNObject::Render();
}

void CMapCreator::Update( float dTime )
{
	NNObject::Update( dTime );
}
