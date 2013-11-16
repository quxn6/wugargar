
#include "CameraSample.h"

CameraSample::CameraSample()
{
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);
	//GetCamera().SetPosition(100.f,100.f);
	GetCamera().SetZoom( 3.f ); // �� 2��
	//GetCamera().SetRotation(90.f);

	// ī�޶� ȭ���� �߽����� �� 0.f, 0.f�� ȭ���� �߾����� ���Ե�

	m_Sprite = NNSprite::Create(L"Resources/Texture/walk_0.png");
	AddChild(m_Sprite);
}
CameraSample::~CameraSample()
{

}

void CameraSample::Render()
{
	NNScene::Render();
}
void CameraSample::Update( float dTime )
{
	NNScene::Update(dTime);
}