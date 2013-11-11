#pragma once

#include "nnscene.h"
#include "Background.h"
#include "PoorZombie.h"
#include "NNLabel.h"
#include "NNPoint.h"
#include "UIButton.h"
#include "MapCreator.h"
#include "CreatePolice.h"


enum ZombieType
{
	POOR_ZOMBIE,
	VOMIT_ZOMBIE,
	MUSCLE_ZOMBIE,
	KAMIKAJE_ZOMBIE,
	SMOG_ZOMBIE,
	ICE_ZOMBIE,
	NUMBER_OF_ZOMBIE_TYPES
}; // 좀비 생성시 타입을 알아보기 위한 enum값 - 채원
// array에서 사용하므로 각각의 enum에 상수를 할당하지 말 것. - 성환

class CPlayScene : public NNScene
{
private :
	static CPlayScene* m_pInstance;

private:
	CPlayScene(void);
	~CPlayScene(void);

public:
	void Render();
	void Update( float dTime );
	std::list<CZombie*> GetZombieList() { return m_llistZombie; }
	std::list<CPolice*> GetPoliceList() { return m_llistPolice; }
	CMapCreator* GetMapCreator(void) { return m_pMapCreator;}

	static CPlayScene* GetInstance();
	static void ReleaseInstance();
	void MakeZombie(ZombieType type);
	void MakeCharacterWalk(float dTime);
	void MakeZombieButtonOperate(float dTime);
	void KillCharacter();
	void MakePoliceByFile();


private :
	void _initBackground( void );
	void _initUI( void );
	void _initMap( void );

private :
	CBackground *m_pBackground;
	CMapCreator *m_pMapCreator;
	NNSprite	*m_pUIBackground;
	CUIButton	*m_pUIMakeZombieButton[NUMBER_OF_ZOMBIE_TYPES];
	CUIButton	*m_pUIButton1;
	CUIButton	*m_pUIButton2;
	CUIButton	*m_pUIButton3;
	CUIButton	*m_pUIButton4;
	CUIButton	*m_pUIButton5;
	CUIButton	*m_pUIButton6;
	NNLabel		*m_pShowMouseStatus;
	NNPoint		m_CursorPos;
	CCreatePolice *m_pCreatePolice;

	std::list<CZombie*>		m_llistZombie;
	std::list<CPolice*>		m_llistPolice;

	wchar_t		temp[256]; // 화면 마우스 커서 표시를 위한 임시변수

public: // update함수가 지저분해서 테스트 함수 밖으로 다 뺐습니다 // Good job~
	void Test_ShowMousePosition();
	void Test_ShowFPS();
};
