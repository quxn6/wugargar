#pragma once
#include "nnAnimation.h"
#include "NNMacroSet.h"
#include "NNObject.h"

class CHumanInFarm : public NNObject
{
public:
	CHumanInFarm(void);
	virtual ~CHumanInFarm(void);

public :
	NNAnimation *m_pSmallBaby;
	NNAnimation *m_pMiddleBaby;
	NNAnimation *m_pGrownUp;

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CHumanInFarm);

public :
	void CreateBaby();

};

