#pragma once
#include "nnobject.h"

class NNLabel;
class NNSprite;

class CHumanFarm : public NNObject
{
public:
	CHumanFarm(void);
	virtual ~CHumanFarm(void);

public :
	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CHumanFarm);
	void MakeHuman();
	void ShowMeatPoint();

protected:
	NNSprite *m_pFarmBackground;
	NNLabel *m_pShowMeatPoint;
	
	void InitFarmBackground();
private:
	wchar_t		meatPointTemp[256];

};

