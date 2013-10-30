#pragma once
#include "Zombie.h"
#include "Podol.h"
#include "NNSprite.h"

class CUnit
{
public:
	CUnit(void);
	~CUnit(void);



public:
	double GetPosition_x() {return m_position_x;}
	double GetPosition_y() {return m_position_y;}
	CUnit	GetCloserEnemy();


public:
	CZombie zombie_list[25];
	CPodol  podol_list[25];
	int num_zombie_unit;
	int num_podol_unit;

private:


protected:
	double	m_position_x;
	double	m_position_y;
	double	m_attack_range;
	int		m_attack_point;
	CUnit	*m_attack_target;
	NNSprite *m_unit_image;



};




