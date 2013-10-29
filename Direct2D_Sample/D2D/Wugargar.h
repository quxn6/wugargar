#pragma once

#include "nnscene.h"
#include "Background.h"
#include "PoorZombie.h"
#include "ZombieBase.h"
#include "NNLabel.h"

class CWugargar : public NNScene
{
private :
	CBackground *m_Background;
	CPoorZombie *m_PoorZombie;
	CZombieBase *m_ZombieBase;
	NNLabel		*m_ShowMouseStatus;
	POINT		m_CursorPos;
	wchar_t		temp[256];

public:
	CWugargar(void);
	virtual ~CWugargar(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC (CWugargar);


};

