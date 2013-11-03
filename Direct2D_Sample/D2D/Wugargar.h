#pragma once

#include "nnscene.h"
#include "Background.h"
#include "PoorZombie.h"
#include "ZombieBase.h"
#include "NNLabel.h"
#include "NNPoint.h"
#include "UIButton.h"

class CWugargar : public NNScene
{
private :
	static CWugargar* m_pInstance;

private:
	CWugargar(void);
	~CWugargar(void);


private :
	CBackground *m_Background;
	CPoorZombie *m_PoorZombie;
	CZombieBase *m_ZombieBase;
	CUIButton	*m_UIButton1;
	NNLabel		*m_ShowMouseStatus;
	NNPoint		m_CursorPos;
	wchar_t		temp[256];
	

private:	
	std::list<CZombie*>		m_llistZombie;
	std::list<CPolice*>		m_llistPolice;

public:
	void Render();
	void Update( float dTime );
	std::list<CZombie*> GetZombieList() { return m_llistZombie; }


public :
	static CWugargar* GetInstance();
	static void ReleaseInstance();

};
