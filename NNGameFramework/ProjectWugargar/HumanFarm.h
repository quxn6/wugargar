#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNMacroSet.h"

class CHumanFarm : public NNObject
{
private :
	static CHumanFarm* m_pInstance;
	CHumanFarm(void);
	virtual ~CHumanFarm(void);

public :
	static CHumanFarm* GetInstance();
	static void ReleaseInstance();
	void InitFarmBackground();
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CHumanFarm);
	void MakeHuman();
	void ShowMeatPoint();
	void SetMeatPoint(int meatPoint) { m_pMeatPoint = meatPoint;}
	int GetMeatPoint() { return m_pMeatPoint;}

protected:
	NNSprite *m_pFarmBackground;
	NNLabel *m_pShowMeatPoint;

private:
	wchar_t		meatPointTemp[256];
	int m_pMeatPoint;

};

