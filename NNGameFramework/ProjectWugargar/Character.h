#pragma once
#include "NNMacroSet.h"
#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"

#include "GameConfig.h"
#include "Player.h"
#include "NNSpriteAtlas.h"


enum CharacterIdentity{
	Zombie,
	Police,
	Base
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
	void SplashAttack(int damage);
	void CheckIceState();
	void MakeCharacterWalk(float dTime);
	virtual void Attack();

	// gets & sets
	float GetHP() {return m_HealthPoint;}
	float GetMovingSpeed() {return m_MovingSpeed;}
	int GetAttackPower() {return m_AttackPower;}
	int GetDefensivePower() {return m_DefensivePower;}
	float GetAttackRange() {return m_AttackRange;}
	int GetNumberOfTarget() {return m_NumberOfTarget;}
	int GetAttackSpeed() {return m_AttackSpeed;}
	int GetNowTimeSEC() {return m_NowTime/CLOCKS_PER_SEC;}
	int GetCreateTimeSEC() {return m_CreateTime/CLOCKS_PER_SEC;}
	CharacterIdentity GetIdentity() {return m_Identity;}
	NNSprite *GetSprite(){return m_Sprite;}


	void SetHP(float hp) {m_HealthPoint = hp;}
	void SetSpeed(float speed) {m_MovingSpeed = speed;}
	void SetAttackPower(int AP) {m_AttackPower = AP;}
	void SetDefensivePower(int DP) {m_DefensivePower = DP;}
	void SetAttackRange(float AR) {m_AttackRange = AR;}
	void SetNumberOfTarget(int NT) {m_NumberOfTarget = NT;}
	void SetAttackSpeed(int AS) {m_AttackSpeed = AS;}
	void SetIdentity(CharacterIdentity set_id) {m_Identity = set_id;}
	void SetNowTime(clock_t time) {m_NowTime = time;}
	void SetCreateTime(clock_t time) {m_CreateTime = time;}
	void SetIceStartTime(clock_t time) {m_iceStartTime = time;}
	void SetIceNowTime(clock_t time) {m_iceNowTime = time;};
	void SetIceState(bool ice_state) {m_FrozenState = ice_state;}
	void SetFrozenTime(int ft) { m_RemainingFrozenTime = ft;}

	
protected: 
	virtual void initStatus( void ) {};	

protected:
	// variations for Character status
	CharacterIdentity	m_Identity;
	std::string			m_typeName; // xml parser를 위한 변수인가?
	float	m_HealthPoint;
	float	m_HPRatioPer100; //HP를 100에 대한 비율로 알기 위한 변수 
	float	m_MovingSpeed;
	int		m_AttackPower;
	int		m_DefensivePower;
	float	m_AttackRange;
	int		m_NumberOfTarget;
	int		m_AttackSpeed;
	bool	m_SplashAttack;
	float	m_SplashAttackRange;
	bool	m_FreezingAttack;
	int		m_FreezingAttackTime;		

	// 공격 및 이동 관련 내부 변수
	clock_t		m_NowTime;
	clock_t		m_CreateTime;
	clock_t		m_iceStartTime;
	clock_t		m_iceNowTime;
	CCharacter*	m_AttackTarget;
	bool		m_FrozenState;
	int			m_RemainingFrozenTime;
	float		m_Sight;

	// 기본 내부 변수
	NNSprite*		m_Sprite;	//캐릭터는 기본적으로 sprite하나를 갖게함. 추후에 애니메이션으로 업그레이드되겠지?
	std::string		m_spritePath;
	NNSpriteAtlas*	m_pShowHP;
	
	//wchar_t		temp_HP[256]; 
};

