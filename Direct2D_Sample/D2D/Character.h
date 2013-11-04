#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"

enum CharacterIdentity{
	Zombie,
	Police
};

class CCharacter : public NNObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);



public:
	void Render();
	void Update( float dTime );
	CCharacter *GetCloseEnemy();

	NNCREATE_FUNC(CCharacter);

private:
	int m_hp;
	float m_speed;
	int m_attackPower;
	int m_defensivePower;
	float m_attackRange;
	int m_numberOfTarget;
	int m_attackSpeed;
	CharacterIdentity m_identity;
	CCharacter *m_attack_target;

public:
	int GetHP() {return m_hp;};
	float GetSpeed() {return m_speed;};
	int GetAttackPower() {return m_attackPower;};
	int GetDefensivePower() {return m_defensivePower;};
	float GetAttackRange() {return m_attackRange;};
	int GetNumberOfTarget() {return m_numberOfTarget;};
	int GetAttackSpeed() {return m_attackSpeed;};
	CharacterIdentity GetIdentity() {return m_identity;}
	void SetIdentity(CharacterIdentity set_id) {m_identity = set_id;}

	void SetHP(int hp) {m_hp = hp;};
	void SetSpeed(float speed) {m_speed = speed;};
	void SetAttackPower(int AP) {m_attackPower = AP;};
	void SetDefensivePower(int DP) {m_defensivePower = DP;};
	void SetAttackRange(float AR) {m_attackRange = AR;};
	void SetNumberOfTarget(int NT) {m_numberOfTarget = NT;};
	void SetAttackSpeed(int AS) {m_attackSpeed = AS;};

};

