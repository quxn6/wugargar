#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"


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
	NNCREATE_FUNC(CCharacter);	

	void InitSprite(std::wstring imagePath);
	void SetRandomPositionAroundBase();
	void DetermineAttackTarget();
	void GoToAttackTarget(float dTime);
	bool IsAttack();

	// gets & sets
	int GetHP() {return m_HealthPoint;};
	float GetMovingSpeed() {return m_MovingSpeed;};
	int GetAttackPower() {return m_AttackPower;};
	int GetDefensivePower() {return m_DefensivePower;};
	float GetAttackRange() {return m_AttackRange;};
	int GetNumberOfTarget() {return m_NumberOfTarget;};
	int GetAttackSpeed() {return m_AttackSpeed;};
	CharacterIdentity GetIdentity() {return m_Identity;}
	
	void SetHP(int hp) {m_HealthPoint = hp;};
	void SetSpeed(float speed) {m_MovingSpeed = speed;};
	void SetAttackPower(int AP) {m_AttackPower = AP;};
	void SetDefensivePower(int DP) {m_DefensivePower = DP;};
	void SetAttackRange(float AR) {m_AttackRange = AR;};
	void SetNumberOfTarget(int NT) {m_NumberOfTarget = NT;};
	void SetAttackSpeed(int AS) {m_AttackSpeed = AS;};
	void SetIdentity(CharacterIdentity set_id) {m_Identity = set_id;}

	void Attack();
	
protected: 
	virtual void initStatus( void );	

protected:
	int m_HealthPoint;
	float m_MovingSpeed;
	int m_AttackPower;
	int m_DefensivePower;
	float m_AttackRange;
	int m_NumberOfTarget;
	int m_AttackSpeed;
	CharacterIdentity m_Identity;
	CCharacter *m_AttackTarget;
	NNSprite*	m_Sprite;	//캐릭터는 기본적으로 sprite하나를 갖게함. 추후에 애니메이션으로 업그레이드되겠지?
	NNLabel*	m_pShowHP;
	wchar_t		temp_HP[256]; 
};

