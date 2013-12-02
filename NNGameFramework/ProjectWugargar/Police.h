#pragma once
#include "character.h"
#include "NNXML.h"
#include "GameConfig.h"


//Create할 때, 해당 타입에 맞는 PoliceInfo가 설정되도록
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
};

class CPolice : public CCharacter
{
public:
	CPolice(void);
	virtual ~CPolice(void);

public:
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CPolice);

public:	
	bool IsInfected() {return m_infected;};
	void SetInfectedStatus(bool infected) {m_infected = infected;};
	void InitStatusByXML(NNXML *PoliceInfoXml, int policeInfoIdx);

	CharacterInfo policeInfo[6];

protected:
	bool m_infected;
	PoliceType m_policeType;

	virtual void initStatus( CharacterInfo policeInfo );

};
