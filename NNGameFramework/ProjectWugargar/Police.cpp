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


void CPolice::initStatus( CharacterInfo *characterInfo, int characterType )
{	
	// 부모 클래스의 initstatus 호출
	CCharacter::initStatus(characterInfo,characterType);
	
	// 포돌이 타입 설정
	m_policeType = static_cast<PoliceType>(characterInfo[characterType].characterType);

	// 포돌이 특유 init내용 호출
	FrozenStatus = NNSprite::Create(L"wugargar/ice.png");
	FrozenStatus->SetOpacity(0.5f);
	FrozenStatus->SetPosition(-25,-25);//얼추
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
	m_AttackEffect -> SetPosition(-190,-70);

	AddChild(m_AttackEffect);
}




