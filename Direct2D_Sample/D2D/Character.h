#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"
class CCharacter : public NNObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);



public:
	void Render();
	void Update( float dTime );


	NNCREATE_FUNC(CCharacter);

private:
	int m_hp;
	float m_speed;
	int m_attackPower;
	int m_defensivePower;
	float m_attackRange;
	int m_numberOfTarget;
	int m_attackSpeed;

public:
	int GetHP() {return m_hp;};
	float GetSpeed() {return m_speed;};
	int GetAttackPower() {return m_attackPower;};
	int GetDefensivePower() {return m_defensivePower;};
	float GetAttackRange() {return m_attackRange;};
	int GetNumberOfTarget() {return m_numberOfTarget;};
	int GetAttackSpeed() {return m_attackSpeed;};

};

