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
	if(m_Freeze)
		FrozenStatus->SetVisible(true);
	else
		FrozenStatus->SetVisible(false);
}


void CPolice::initStatus( CharacterInfo *policeInfo, int police_type_idx )
{
	m_FullHP = policeInfo[police_type_idx].FullHP;
	m_HealthPoint = m_FullHP;
	m_MovingSpeed = policeInfo[police_type_idx].MovingSpeed;
	m_AttackPower = policeInfo[police_type_idx].AttackPower;
	m_DefensivePower = policeInfo[police_type_idx].DefensivePower;
	m_AttackRange = policeInfo[police_type_idx].AttackRange;
	m_SplashAttackRange = policeInfo[police_type_idx].SplashRange;
	m_AttackSpeed = policeInfo[police_type_idx].AttackSpeed;
	m_SplashAttack = policeInfo[police_type_idx].IsSplash;
	m_Identity = policeInfo[police_type_idx].identity;
	m_policeType = policeInfo[police_type_idx].policeType;
	m_spritePath = CCharacter::string2wstring(policeInfo[police_type_idx].SpritePath.c_str());
	m_typeName = policeInfo[police_type_idx].TypeName;

	FrozenStatus = NNSprite::Create(L"wugargar/ice.png");
	FrozenStatus->SetOpacity(0.5f);
	FrozenStatus->SetPosition(-25,-25);//¾óÃß
	FrozenStatus->SetVisible(false);
	AddChild(FrozenStatus,20);

}



