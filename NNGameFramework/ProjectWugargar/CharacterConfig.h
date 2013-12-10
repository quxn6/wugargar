#pragma once
#include "GameConfig.h"
#include <string>
#include "Character.h"
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
	PoliceType policeType;
};

class CCharacterConfig
{
public:
	CCharacterConfig(void);
	virtual ~CCharacterConfig(void);

	static CCharacterConfig* m_pInstance;

	CharacterInfo policeInfo[NUMBER_OF_POLICE_TYPES];
	CharacterInfo zombieInfo[NUMBER_OF_ZOMBIE_TYPES];

	void InitPoliceInfo(NNXML *PoliceInfoXml);
	static void ReleaseInstance();
	static CCharacterConfig* GetInstance();
	void initialize_Xpath(std::string *xPath, int idx);
	CharacterInfo *GetPoliceInfo(){return policeInfo;};
	CharacterInfo *GetZombieInfo(){return zombieInfo;};



private:
	int num_of_police_type;
	int num_of_zombie_type;

};

