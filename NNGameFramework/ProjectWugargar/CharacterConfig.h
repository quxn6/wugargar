#pragma once
#include "GameConfig.h"
#include <string>
#include "Character.h"



struct CharacterInfo{
	float HealthPoint;
	float HPRatioPer100;
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
	ZombieType zombieType;
};

class CCharacterConfig
{
public:
	CCharacterConfig(void);
	~CCharacterConfig(void);

	CharacterInfo policeInfo[NUMBER_OF_POLICE_TYPES];
	CharacterInfo zombieInfo[NUMBER_OF_ZOMBIE_TYPES];



};

