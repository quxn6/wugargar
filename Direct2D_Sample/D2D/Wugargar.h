#pragma once

#include "nnscene.h"
#include "Background.h"
#include "PoorZombie.h"
#include "ZombieBase.h"

class CWugargar : public NNScene
{
private :
	CBackground *m_Background;
	CPoorZombie *m_PoorZombie;
	CZombieBase *m_ZombieBase;

public:
	CWugargar(void);
	virtual ~CWugargar(void);

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC (CWugargar);


};

