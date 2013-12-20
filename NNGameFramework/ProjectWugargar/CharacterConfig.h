#pragma once

#include "headers.h"
#include "GameConfig.h"
#include "NNXML.h"



struct CharacterInfo{
	float FullHP;	
	float MovingSpeed;
	float AttackRange;
	float SplashRange;
	int AttackPower;
	int DefensivePower;
	int AttackSpeed;
	bool IsSplash;
	bool IsIceAttack;
	std::string SpritePath;
	std::string TypeName;
	CharacterIdentity identity;
	int characterType;

	//애니메이션 변수
	int				numberOfAnimationImage[NUMBER_OF_CHARACTER_STATUS];
	std::string		*animationPath[NUMBER_OF_CHARACTER_STATUS];


// 	int WalkAniImageNum;
// 	std::string *WalkAniImagePath;
// 	int DeadAniImageNum;
// 	std::string *DeadAniImagePath;
// 	int CreateAniImageNum;
// 	std::string *CreateAniImagePath;
// 	int AttackAniImageNum;
// 	std::string *AttackAniImagePath;


	int CreationCost;
	clock_t FreezingAttackDuration;
	bool IsSelfDestruction;
};

class CCharacterConfig
{
public:
	CCharacterConfig(void);
	virtual ~CCharacterConfig(void);

	static CCharacterConfig* m_pInstance;	
	static CCharacterConfig* GetInstance();
	static void ReleaseInstance();
	
	void InitCharacterInfo(NNXML *CharacterInfoXml, CharacterIdentity identity);
	CharacterInfo* GetCharacterInfo(CharacterIdentity identity){ return m_CharacterInfo[identity]; }

private:
	void initialize_Xpath(std::string *xPath, int idx, CharacterIdentity identity);	

	int m_NumberOfCharacterType[NUMBER_OF_IDENTITIES];

	CharacterInfo *m_CharacterInfo[NUMBER_OF_IDENTITIES];


};

