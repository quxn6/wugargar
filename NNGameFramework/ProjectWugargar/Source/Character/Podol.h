#pragma once
#include "unit.h"
class CPodol :
	public CUnit
{
public:
	CPodol(void);
	~CPodol(void);


	CZombie *GetCloserEnemy();
};

