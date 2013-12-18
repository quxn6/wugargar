#include "Zombie.h"
#include "PlayScene.h"
#include "NNResourceManager.h"
#include "NNAudioSystem.h"


CZombie::CZombie(void)
{
	PlayCreationSound();
//	enemyList = &(CPlayScene::GetInstance()->GetPoliceList());
	m_Shadow = NNSprite::Create(L"wugargar/shadow.png");
	m_Shadow->SetPosition(-35,20);
	AddChild(m_Shadow);
}


CZombie::~CZombie(void)
{
}

void CZombie::Render()
{
	NNObject::Render();
}

void CZombie::Update( float dTime )
{
	CCharacter::Update(dTime);
}

void CZombie::ApplyZombieLevel()
{
	CPlayer* player = CPlayer::GetInstance();
	int currentZombieLevel = player->GetZombieLevel(m_zombieType);

	m_HealthPoint += m_HealthPoint/10*currentZombieLevel;
	m_AttackPower += m_AttackPower/5 *currentZombieLevel;
	m_DefensivePower += m_DefensivePower/5 + currentZombieLevel;
}


//12.09 정인호
//좀비의 생성시 사운드를 재생하는 함수.
void CZombie::PlayCreationSound()
{
	std::string soundPath;

	//랜덤하게 두 개의 생성 소리 중 하나를 재생하거나
	//재생을 하지 않는다.
	switch (rand() % 3)
	{
	case 0:
		soundPath = "sound/ZombieCreateSound1.wav";
		break;
	case 1:
		soundPath = "sound/ZombieCreateSound2.wav";
		break;
	default:
		return;
	}

	m_creation_sound = NNResourceManager::GetInstance()->LoadSoundFromFile(soundPath, false, false);
	
	NNAudioSystem::GetInstance()->Play(m_creation_sound);

}

void CZombie::initStatus( CharacterInfo *zombieInfo, int zombie_type_idx )
{
	m_FullHP = zombieInfo[zombie_type_idx].FullHP;
	m_HealthPoint = m_FullHP;
	m_MovingSpeed = zombieInfo[zombie_type_idx].MovingSpeed;
	m_AttackPower = zombieInfo[zombie_type_idx].AttackPower;
	m_DefensivePower = zombieInfo[zombie_type_idx].DefensivePower;
	m_AttackRange = zombieInfo[zombie_type_idx].AttackRange;
	m_SplashAttackRange = zombieInfo[zombie_type_idx].SplashRange;
	m_AttackSpeed = zombieInfo[zombie_type_idx].AttackSpeed;
	m_SplashAttack = zombieInfo[zombie_type_idx].IsSplash;
	m_Identity = zombieInfo[zombie_type_idx].identity;
	m_zombieType = zombieInfo[zombie_type_idx].zombieType;
	m_FreezingAttack = zombieInfo[zombie_type_idx].IsIceAttack;
	m_spritePath = CCharacter::string2wstring(zombieInfo[zombie_type_idx].SpritePath.c_str());
	m_typeName = zombieInfo[zombie_type_idx].TypeName;
	m_WalkAniImageNum = zombieInfo[zombie_type_idx].WalkAniImageNum;
	m_DeadAniImageNum = zombieInfo[zombie_type_idx].DeadAniImageNum;
	m_CreateAniImageNum = zombieInfo[zombie_type_idx].CreateAniImageNum;
	m_AttackAniImageNum = zombieInfo[zombie_type_idx].AttackAniImageNum;


	for(int idx=0; idx<m_CreateAniImageNum; ++idx)
		CreateAnimationImagePath.push_back(CCharacter::string2wstring(zombieInfo[zombie_type_idx].CreateAniImagePath[idx]));

	for(int idx=0; idx<m_AttackAniImageNum; ++idx)
		AttackAnimationImagePath.push_back(CCharacter::string2wstring(zombieInfo[zombie_type_idx].AttackAniImagePath[idx]));

	for(int idx=0; idx<m_WalkAniImageNum; ++idx)
		WalkAnimationImagePath.push_back(CCharacter::string2wstring(zombieInfo[zombie_type_idx].WalkAniImagePath[idx]));

	for(int idx=0; idx<m_DeadAniImageNum; ++idx)
		DeadAnimationImagePath.push_back(CCharacter::string2wstring(zombieInfo[zombie_type_idx].DeadAniImagePath[idx]));


	m_CreateCost = zombieInfo[zombie_type_idx].CreationCost;
	m_FreezingAttackDuration = zombieInfo[zombie_type_idx].FreezingAttackDuration;
	m_SuicideBomber = zombieInfo[zombie_type_idx].IsSelfDestruction;

	InitZombieAnimation();
	ApplyZombieLevel();


}



