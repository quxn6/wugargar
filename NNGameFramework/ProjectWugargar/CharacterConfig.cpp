#include "CharacterConfig.h"
#include "NNMacroSet.h"


CCharacterConfig::CCharacterConfig(void)
{
}


CCharacterConfig::~CCharacterConfig(void)
{
	

	for (int i=0; i<NUMBER_OF_IDENTITIES ; ++i)
	{		
		for(int j=0; j<m_NumberOfCharacterType[i]; ++j)
		{
			for (int k=0 ; k<NUMBER_OF_CHARACTER_STATUS ; ++k) 
			{
				SafeArrayDelete(m_CharacterInfo[i][j].animationPath[k]);
			}
			
		}
		SafeArrayDelete(m_CharacterInfo[i]);
	}
	
	
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


void CCharacterConfig::initialize_Xpath( std::string *xPath, int idx, CharacterIdentity identity )
{
	xPath->clear();
	switch (identity)
	{
	case ZOMBIE:
		*xPath = "/ZombieInfo/Zombie" + std::to_string(idx+1);
		break;
	case POLICE:
		*xPath = "/PoliceInfo/Police" + std::to_string(idx+1);
		break;	
	default:
		break;
	}
	

}

void CCharacterConfig::InitCharacterInfo( NNXML *CharacterInfoXml, CharacterIdentity identity )
{
	switch (identity)
	{
	case ZOMBIE:
		m_NumberOfCharacterType[identity] = std::stoi(CharacterInfoXml->XPathToString("/ZombieInfo/ZombieTypeNum/text()").c_str());		
		break;
	case POLICE:
		m_NumberOfCharacterType[identity] = std::stoi(CharacterInfoXml->XPathToString("/PoliceInfo/PoliceTypeNum/text()").c_str());
		break;
	default:
		break;
	}
	
	m_CharacterInfo[identity] = new CharacterInfo[m_NumberOfCharacterType[identity]];

	for(int characterType=0; characterType<m_NumberOfCharacterType[identity]; ++characterType)
	{
		m_CharacterInfo[identity][characterType].characterType = characterType;
		std::string xPath;
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].FullHP = (std::stof(CharacterInfoXml->XPathToString(xPath.append("/HealthPoint/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].MovingSpeed = (std::stof(CharacterInfoXml->XPathToString(xPath.append("/MovingSpeed/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].AttackRange = (std::stof(CharacterInfoXml->XPathToString(xPath.append("/AttackRange/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].SplashRange = (std::stof(CharacterInfoXml->XPathToString(xPath.append("/SplashRange/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].AttackPower = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/AttackPower/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].DefensivePower = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/DefensivePower/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].AttackSpeed = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/AttackSpeed/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].SpritePath = (CharacterInfoXml->XPathToString(xPath.append("/SpritePath/text()").c_str()));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].TypeName = (CharacterInfoXml->XPathToString(xPath.append("/TypeName/text()").c_str()));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].CreationCost = std::stoi(CharacterInfoXml->XPathToString(xPath.append("/CreationPrice/text()").c_str()));		
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].FreezingAttackDuration= std::stoi(CharacterInfoXml->XPathToString(xPath.append("/FreezingAttackDuration/text()").c_str()));		
		
		m_CharacterInfo[identity][characterType].identity = identity;

		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].numberOfAnimationImage[CHARACTER_WALK] = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/WalkAniImageNum/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].numberOfAnimationImage[CHARACTER_DEAD] = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/DeadAniImageNum/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].numberOfAnimationImage[CHARACTER_CREATE]  = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/CreateAniImageNum/text()").c_str())));
		initialize_Xpath(&xPath, characterType, identity);
		m_CharacterInfo[identity][characterType].numberOfAnimationImage[CHARACTER_ATTACK]  = (std::stoi(CharacterInfoXml->XPathToString(xPath.append("/AttackAniImageNum/text()").c_str())));

		// for문을 위한 애니메이션 종류 저장
		std::string animationStatus[4];
		animationStatus[0] = "/Create";
		animationStatus[1] = "/Walk";
		animationStatus[2] = "/Attack";
		animationStatus[3] = "/Dead";

		for (int type=0 ; type<NUMBER_OF_CHARACTER_STATUS ; ++type)
		{
			int animationLength = m_CharacterInfo[identity][characterType].numberOfAnimationImage[type];
			m_CharacterInfo[identity][characterType].animationPath[type] = new std::string[animationLength];
			for ( int sprite=0 ; sprite<animationLength ; ++sprite )
			{				
				initialize_Xpath(&xPath, characterType, identity);		
				xPath = (xPath + animationStatus[type] + "AniImagePath" + std::to_string(sprite) + "/text()").c_str();
				m_CharacterInfo[identity][characterType].animationPath[type][sprite] = CharacterInfoXml->XPathToString(xPath);
			}

		}
		
		initialize_Xpath(&xPath, characterType, identity);		
		int intForBool = std::stoi(CharacterInfoXml->XPathToString(xPath.append("/IsSplash/text()").c_str()));
		if( 1 == intForBool ) 
		{
			m_CharacterInfo[identity][characterType].IsSplash = true;
		} 
		else if (0 ==  intForBool)
		{
			m_CharacterInfo[identity][characterType].IsSplash = false;
		}
		else
		{
			printf_s("bool type script isSplash error");
		}

		initialize_Xpath(&xPath, characterType, identity);
		intForBool = std::stoi(CharacterInfoXml->XPathToString(xPath.append("/IsIceAttack/text()").c_str()));
		if( 1 == intForBool ) 
		{
			m_CharacterInfo[identity][characterType].IsIceAttack = true;
		} 
		else if ( 0 == intForBool)
		{
			m_CharacterInfo[identity][characterType].IsIceAttack = false;
		}
		else
		{
			printf_s("bool type script IsIceAttack error");
		}	

		initialize_Xpath(&xPath, characterType, identity);
		intForBool = std::stoi(CharacterInfoXml->XPathToString(xPath.append("/IsSelfDestruction/text()").c_str()));
		if( 1 == intForBool ) 
		{
			m_CharacterInfo[identity][characterType].IsSelfDestruction = true;
		} 
		else if ( 0 == intForBool)
		{
			m_CharacterInfo[identity][characterType].IsSelfDestruction = false;
		}
		else
		{
			printf_s("bool type script suisidebomber error");
		}		
	}
}
