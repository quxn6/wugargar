#pragma once

#include "NNScene.h"
#include "NNLabel.h"
#include "NNPoint.h"
#include "Background.h"
#include "UIButton.h"
#include "MapCreator.h"
#include "CreatePolice.h"
#include "Police.h"
#include "Zombie.h"
#include "GameConfig.h"
// 
// enum GameResult{
// 	NOT_END,
// 	LOSE,
// 	WIN
// };

class CPlayScene : public NNScene
{
private :
	static CPlayScene* m_pInstance;
	CPlayScene(void);
	virtual ~CPlayScene(void);

public:
	void Render();
	void Update( float dTime );
	std::list<CCharacter*> GetZombieList() { return m_llistZombie; }
	std::list<CCharacter*> GetPoliceList() { return m_llistPolice; }
	CMapCreator* GetMapCreator(void) { return m_pMapCreator;}
	

	static CPlayScene* GetInstance();
	static void ReleaseInstance();
	void MakeZombie(ZombieType type);
	void MakeCharacterWalk(float dTime);
	void MakeZombieButtonOperate(float dTime);
	void DeadCharacterCollector();
	void MakePoliceFromScript();
	void IncreaseLocalMoney(int time);
	bool CheckGameOver();

	void SetStartTime(clock_t time) {m_startTime = time;};
	void SetNowTime(clock_t time) {m_nowTime = time;};
	int GetStartTimeSEC() {return m_startTime/CLOCKS_PER_SEC;}; 
	int GetNowTimeSEC() {return m_nowTime/CLOCKS_PER_SEC;};

private :
	void _initBackground( void );
	void _initUI( void );
	void _initMap( void );

private :
	CBackground *m_pBackground;
	CMapCreator *m_pMapCreator;
	NNSprite	*m_pUIBackground;
	CUIButton	*m_pUIMakeZombieButton[NUMBER_OF_ZOMBIE_TYPES];
	NNLabel		*m_pShowMouseStatus;
	NNPoint		m_CursorPos;
	CCreatePolice *m_pCreatePolice;

	std::list<CCharacter*>		m_llistZombie;
	std::list<CCharacter*>		m_llistPolice;

	wchar_t		temp[256]; // 화면 마우스 커서 표시를 위한 임시변수
	clock_t m_startTime;
	clock_t m_nowTime;

public: // update함수가 지저분해서 테스트 함수 밖으로 다 뺐습니다 // Good job~
	void Test_ShowMousePosition();
	void Test_ShowFPS();
};
