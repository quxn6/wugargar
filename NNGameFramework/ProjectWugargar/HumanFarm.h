#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNMacroSet.h"

class CHumanFarm : public NNObject
{
public:
	CHumanFarm(void);
	virtual ~CHumanFarm(void);

public :
	void InitFarmBackground();
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CHumanFarm);
	void MakeHuman();
	void ShowMeatPoint();

protected:
	NNSprite *m_pFarmBackground;
	NNLabel *m_pShowMeatPoint;

private:
	wchar_t		meatPointTemp[256];

};

