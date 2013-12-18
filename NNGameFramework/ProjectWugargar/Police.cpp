#include "Police.h"
#include "Zombie.h"
#include "PlayScene.h"
#include "NNAnimation.h"


CPolice::CPolice(void)
{
//	enemyList = &(CPlayScene::GetInstance()->GetZombieList());
	InitAttackEffect();
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

//	printf_s("%f",GetHP());
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

void CPolice::InitAttackEffect()
{
	m_AttackEffect = NNAnimation::Create();
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame0.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame1.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame2.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame3.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame4.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame5.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame6.png");
	m_AttackEffect -> AddSpriteNode(L"wugargar/muzzle/Frame7.png");

	m_AttackEffect -> SetFrameTimeInSection(0.2f,0,7);
	m_AttackEffect -> SetPosition(-40,-30);

	AddChild(m_AttackEffect);
}




