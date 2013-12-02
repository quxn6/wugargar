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

void CCharacterConfig::SetPoliceInfo( NNXML *PoliceInfoXml, int policeInfoIdx )
{
	

	policeInfo[policeInfoIdx].HealthPoint = (std::stof(PoliceInfoXml->XPathToString("/Police/HealthPoint/text()").c_str()) );
	policeInfo[policeInfoIdx].MovingSpeed = (std::stof(PoliceInfoXml->XPathToString("/Police/MovingSpeed/text()").c_str()) );
	policeInfo[policeInfoIdx].AttackRange = (std::stof(PoliceInfoXml->XPathToString("/Police/AttackRange/text()").c_str()) );
	policeInfo[policeInfoIdx].SplashRange = (std::stof(PoliceInfoXml->XPathToString("/Police/SplashRange/text()").c_str()) );
	policeInfo[policeInfoIdx].AttackPower = (std::stoi(PoliceInfoXml->XPathToString("/Police/AttackPower/text()").c_str()) );
	policeInfo[policeInfoIdx].DefensivePower = (std::stoi(PoliceInfoXml->XPathToString("/Police/DefensivePower/text()").c_str()) );
	policeInfo[policeInfoIdx].AttackSpeed = (std::stoi(PoliceInfoXml->XPathToString("/Police/AttackSpeed/text()").c_str()) );
	policeInfo[policeInfoIdx].SpritePath = (PoliceInfoXml->XPathToString("/Police/SpritePath/text()").c_str());
	policeInfo[policeInfoIdx].TypeName = (PoliceInfoXml->XPathToString("/Police/TypeName/text()").c_str());
	policeInfo[policeInfoIdx].identity = Police;

	//enum PoliceType
	//{
	//	NONE, //CreatePolice를 위한 상수, 없애는 것 고심중
	//	NORMAL_POLICE,
	//	MACHINEGUN_POLICE,
	//	SHIELD_POLICE,
	//	GRENADE_POLICE,
	//	SHOTGUN_POLICE,
	//	FIRTBAT_POLICE
	//};

	policeInfo[policeInfoIdx].policeType = (PoliceType)policeInfoIdx;
	/*switch (int tmp_policeType = (std::stoi(PoliceInfoXml->XPathToString("/Police/policeType/text()").c_str()) ))
	{
	case 0:
	policeInfo[policeInfoIdx].policeType = NORMAL_POLICE;
	break;
	case 1:
	policeInfo[policeInfoIdx].policeType = MACHINEGUN_POLICE;
	break;
	case 2:
	policeInfo[policeInfoIdx].policeType = SHIELD_POLICE;
	break;
	case 3:
	policeInfo[policeInfoIdx].policeType = GRENADE_POLICE;
	break;
	case 4:
	policeInfo[policeInfoIdx].policeType = SHOTGUN_POLICE;
	break;
	case 5:
	policeInfo[policeInfoIdx].policeType = FIREBAT_POLICE;
	break;
	default:
	break;
	}
	*/


	if(int tmp_isSplash = (std::stoi(PoliceInfoXml->XPathToString("/Police/IsSplash/text()").c_str()) ))
		policeInfo[policeInfoIdx].IsSplash = true;
	else
		policeInfo[policeInfoIdx].IsSplash = false;

	if(int tmp_isIce = (std::stoi(PoliceInfoXml->XPathToString("/Police/IsIceAttack/text()").c_str()) ))
		policeInfo[policeInfoIdx].IsIceAttack = true;
	else
		policeInfo[policeInfoIdx].IsIceAttack = false;
	//bool은 1이면 true, 0이면 false로 설정


	switch (policeInfo[policeInfoIdx].policeType)
	{
	case NORMAL_POLICE:
		break;
	case SHIELD_POLICE:
		break;
	case GRENADE_POLICE:
		break;
	case MACHINEGUN_POLICE:
		break;
	case SHOTGUN_POLICE:
		break;
	case FIREBAT_POLICE:
		break;
	default:
		break;
	}

}
