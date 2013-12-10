#include "CharacterConfig.h"


CCharacterConfig::CCharacterConfig(void)
{
}


CCharacterConfig::~CCharacterConfig(void)
{
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


void CCharacterConfig::initialize_Xpath(std::string *xPath, int idx)
{
	xPath->clear();
	*xPath = "/PoliceInfo/Police" + std::to_string(idx+1);

}

void CCharacterConfig::InitPoliceInfo( NNXML *PoliceInfoXml)
{
	
	num_of_police_type = std::stoi(PoliceInfoXml->XPathToString("/PoliceInfo/PoliceTypeNum/text()").c_str());

	for(int idx=0; idx<num_of_police_type; ++idx)
	{
		std::string xPath;
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].FullHP = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/HealthPoint/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].MovingSpeed = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/MovingSpeed/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].AttackRange = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/AttackRange/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].SplashRange = (std::stof(PoliceInfoXml->XPathToString(xPath.append("/SplashRange/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].AttackPower = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/AttackPower/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].DefensivePower = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/DefensivePower/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].AttackSpeed = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/AttackSpeed/text()").c_str())));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].SpritePath = (PoliceInfoXml->XPathToString(xPath.append("/SpritePath/text()").c_str()));
		initialize_Xpath(&xPath, idx);
		policeInfo[idx].TypeName = (PoliceInfoXml->XPathToString(xPath.append("/TypeName/text()").c_str()));
		policeInfo[idx].identity = Police;


		initialize_Xpath(&xPath, idx);
		if(int tmp_isSplash = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/IsSplash/text()").c_str()) )))
			policeInfo[idx].IsSplash = true;
		else
			policeInfo[idx].IsSplash = false;

		initialize_Xpath(&xPath, idx);
		if(int tmp_isIce = (std::stoi(PoliceInfoXml->XPathToString(xPath.append("/IsIceAttack/text()").c_str()) )))
			policeInfo[idx].IsIceAttack = true;
		else
			policeInfo[idx].IsIceAttack = false;

	}
}
