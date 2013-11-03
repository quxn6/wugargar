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
	CBackground *m_Background;
	CZombieBase *m_ZombieBase;
	CUIButton	*m_UIButton1;
	NNLabel		*m_ShowMouseStatus;
	NNPoint		m_CursorPos;
	CPoorZombie	*m_PoorZombieList[3];
	CPolice		*m_PoliceList[3];
	wchar_t		temp[256];

public:
	CWugargar(void);
	virtual ~CWugargar(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC (CWugargar);


};

