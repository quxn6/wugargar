#pragma once
#include "unit.h"
class CZombie :
	public CUnit
{
public:
	CZombie(void);
	~CZombie(void);

	CPodol *GetCloserEnemy();


};

