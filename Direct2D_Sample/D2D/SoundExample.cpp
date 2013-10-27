
#include "SoundExample.h"
#include "NNInputSystem.h"
#include "NNAudioSystem.h"

SoundExample::SoundExample()
{
	m_Label = NNLabel::Create( L"엔터를 눌러보세요", L"맑은 고딕", 40.f );
	AddChild( m_Label );

	NNAudioSystem::GetInstance()->SetBackgroundSound( L"Sound/bg.wav" );
	NNAudioSystem::GetInstance()->AddEffectSound( "Effect", L"Sound/effect.wav" );

	NNAudioSystem::GetInstance()->PlayBackgroundSound();
}
SoundExample::~SoundExample()
{

}

void SoundExample::Render()
{
	NNObject::Render();
}
void SoundExample::Update( float dTime )
{
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_RETURN ) == KEY_DOWN )
	{
		NNAudioSystem::GetInstance()->PlayEffectSound( "Effect" );
	}
}