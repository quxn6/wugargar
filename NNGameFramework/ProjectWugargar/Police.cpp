#include "Police.h"
#include "Zombie.h"
#include "PlayScene.h"


CPolice::CPolice(void)
{
//	enemyList = &(CPlayScene::GetInstance()->GetZombieList());
}


CPolice::~CPolice(void)
{
}

void CPolice::Render()
{
	NNObject::Render();
}

void CPolice::Update( float dTime )
{
	CCharacter::Update(dTime);
}

//(int)PoliceType을 idx로
void CPolice::InitStatusByXML( NNXML *PoliceInfoXml, int policeInfoIdx )
{
	if(!(PoliceInfoXml->GetLoadSuccess())){
		printf_s("Police Information XML Load Fail!\n");
		return;
	}

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

void CPolice::initStatus( CharacterInfo policeInfo )
{
	m_HealthPoint = policeInfo.HealthPoint;
	m_HPRatioPer100 = m_HealthPoint/100;
	m_MovingSpeed = policeInfo.MovingSpeed;
	m_AttackRange = policeInfo.AttackRange;
	m_SplashAttackRange = policeInfo.SplashRange;
	m_AttackPower = policeInfo.AttackPower;
	m_DefensivePower = policeInfo.DefensivePower;
	m_AttackSpeed = policeInfo.AttackSpeed;
	m_SplashAttack = policeInfo.IsSplash;
	m_Identity = policeInfo.identity;
	m_policeType = policeInfo.policeType;
	m_spritePath = policeInfo.SpritePath;
	m_typeName = policeInfo.TypeName;
}



