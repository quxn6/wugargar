#include "CharacterConfig.h"


CCharacterConfig::CCharacterConfig(void)
{
}


CCharacterConfig::~CCharacterConfig(void)
{
	SafeArrayDelete(policeInfo);
	for(int idx=0; idx<num_of_zombie_type; ++idx)
	{
		SafeArrayDelete(zombieInfo[idx].DeadAniImagePath);
		SafeArrayDelete(zombieInfo[idx].WalkAniImagePath);
	}
	SafeArrayDelete(zombieInfo);

	//delete policeInfo;
	//delete zombieInfo;
}

CCharacterConfig* CCharacterConfig::m_pInstance = nullptr;

CCharacterConfig* CCharacterConfig::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new CCharacterConfig();
	}

	return m_pInstance;
}

void CCharacterConfig::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}


void CCharacterConfig::initialize_Xpath_Police(std::string *xPath, int idx)
{
	xPath->clear();
	*xPath = "/PoliceInfo/Police" + std::to_string(idx+1);

}

void CCharacterConfig::initialize_Xpath_Zombie( std::string *xPath, int idx )
{
	xPath->clear();
	*xPath = "/ZombieInfo/Zombie" + std::to_string(idx+1);
}


void CCharacterConfig::InitPoliceInfo( NNXML *PoliceInfoXml)
{
	
	num_of_police_type = std::stoi(PoliceInfoXml->XPathToString("/PoliceInfo/PoliceTypeNum/text()").c_str());
	
	policeInfo = new CharacterInfo[num_of_police_type];

	for(int idx=0; idx<num_of_police_type; ++idx)
	{
		policeInfo[idx].policeType = (PoliceType)idx;
		std::string xPath;
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].FullHP = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/HealthPoint/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].MovingSpeed = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/MovingSpeed/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].AttackRange = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/AttackRange/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].SplashRange = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/SplashRange/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].AttackPower = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/AttackPower/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].DefensivePower = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/DefensivePower/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].AttackSpeed = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/AttackSpeed/text()").c_str())));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].SpritePath = (PoliceInfoXml->XPathToString(xPath.append("/SpritePath/text()").c_str()));
		initialize_Xpath_Police(&xPath, idx);
		policeInfo[idx].TypeName = (PoliceInfoXml->XPathToString(xPath.append("/TypeName/text()").c_str()));
		policeInfo[idx].identity = Police;


		initialize_Xpath_Police(&xPath, idx);
		if(int tmp_isSplash = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/IsSplash/text()").c_str()) )))
			policeInfo[idx].IsSplash = true;
		else
			policeInfo[idx].IsSplash = false;

		initialize_Xpath_Police(&xPath, idx);
		if(int tmp_isIce = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/IsIceAttack/text()").c_str()) )))
			policeInfo[idx].IsIceAttack = true;
		else
			policeInfo[idx].IsIceAttack = false;

	}
}

void CCharacterConfig::InitZombieInfo( NNXML *ZombieInfoXml )
{
	num_of_zombie_type =  std::stoi(ZombieInfoXml->XPathToString("/ZombieInfo/ZombieTypeNum/text()").c_str());
	
	zombieInfo = new CharacterInfo[num_of_zombie_type];

	for(int idx=0; idx<num_of_zombie_type; ++idx)
	{
		std::string xPath;
		zombieInfo[idx].zombieType = (ZombieType)idx;
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].FullHP = (std::stof(ZombieInfoXml->XPathToString(xPath.append("/HealthPoint/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].MovingSpeed = (std::stof(ZombieInfoXml->XPathToString(xPath.append("/MovingSpeed/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].AttackRange = (std::stof(ZombieInfoXml->XPathToString(xPath.append("/AttackRange/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].SplashRange = (std::stof(ZombieInfoXml->XPathToString(xPath.append("/SplashRange/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].AttackPower = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/AttackPower/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].DefensivePower = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/DefensivePower/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].AttackSpeed = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/AttackSpeed/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].TypeName = (ZombieInfoXml->XPathToString(xPath.append("/TypeName/text()").c_str()));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].CreationCost = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/CreationPrice/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		zombieInfo[idx].WalkAniImageNum = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/WalkAniImageNum/text()").c_str())));
		initialize_Xpath_Zombie(&xPath, idx);
		
		zombieInfo[idx].DeadAniImageNum = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/DeadAniImageNum/text()").c_str())));
		
		zombieInfo[idx].WalkAniImagePath = new std::string[zombieInfo[idx].WalkAniImageNum];
		zombieInfo[idx].DeadAniImagePath = new std::string[zombieInfo[idx].DeadAniImageNum];

		for(int walk_ani_idx=0; walk_ani_idx<zombieInfo[idx].WalkAniImageNum; ++walk_ani_idx)
		{
			initialize_Xpath_Zombie(&xPath, idx);
			xPath = (xPath + "/WalkAniImagePath" + std::to_string(walk_ani_idx+1) + "/text()").c_str();
			zombieInfo[idx].WalkAniImagePath[walk_ani_idx] = (ZombieInfoXml->XPathToString(xPath));

		}

		for(int dead_ani_idx=0; dead_ani_idx<zombieInfo[idx].DeadAniImageNum; ++dead_ani_idx)
		{
			initialize_Xpath_Zombie(&xPath, idx);
			xPath = xPath + "/DeadAniImagePath" + std::to_string(dead_ani_idx+1) + "/text()";
			zombieInfo[idx].DeadAniImagePath[dead_ani_idx] = (ZombieInfoXml->XPathToString(xPath));

		}

		initialize_Xpath_Zombie(&xPath, idx);
		if(int tmp_isSplash = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/IsSplash/text()").c_str()) )))
			zombieInfo[idx].IsSplash = true;
		else
			zombieInfo[idx].IsSplash = false;

		initialize_Xpath_Zombie(&xPath, idx);
		if(std::stoi(ZombieInfoXml->XPathToString(xPath.append("/IsIceAttack/text()").c_str()) ))
			zombieInfo[idx].IsIceAttack = true;
		else
			zombieInfo[idx].IsIceAttack = false;

		initialize_Xpath_Zombie(&xPath, idx);
		if(std::stoi(ZombieInfoXml->XPathToString(xPath.append("/IsSelfDestruction/text()").c_str()) ))
			zombieInfo[idx].IsSelfDestruction = true;
		else
			zombieInfo[idx].IsSelfDestruction = false;


		if(zombieInfo[idx].IsIceAttack)
		{
			initialize_Xpath_Zombie(&xPath, idx);
			zombieInfo[idx].FreezingAttackDuration = (std::stoi(ZombieInfoXml->XPathToString(xPath.append("/FreezingAttackDuration/text()").c_str()) ));
		}
		zombieInfo[idx].identity = Zombie;

	}

}

