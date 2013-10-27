
#include "LabelExample.h"

LabelExample::LabelExample()
{
	m_NormalLabel = NNLabel::Create( L"Normal Label", L"¸¼Àº °íµñ", 35.f );
	AddChild( m_NormalLabel );

	m_BoldLabel = NNLabel::Create( L"Bold Label", L"¸¼Àº °íµñ", 35.f );
	m_BoldLabel->SetBold( true );
	m_BoldLabel->SetPosition( 0.f, 40.f );
	AddChild( m_BoldLabel );

	m_ItalicLabel = NNLabel::Create( L"Italic Label", L"¸¼Àº °íµñ", 35.f );
	m_ItalicLabel->SetItalic( true );
	m_ItalicLabel->SetPosition( 0.f, 80.f );
	AddChild( m_ItalicLabel );

	m_ColorLabel = NNLabel::Create( L"Color Label", L"¸¼Àº °íµñ", 35.f );
	m_ColorLabel->SetColor( 255, 0, 0 );
	m_ColorLabel->SetPosition( 0.f, 120.f );
	AddChild( m_ColorLabel );

	m_OpacityLabel = NNLabel::Create( L"Opacity Label", L"¸¼Àº °íµñ", 35.f );
	m_OpacityLabel->SetOpacity( 0.2f );
	m_OpacityLabel->SetPosition( 0.f, 160.f );
	AddChild( m_OpacityLabel );

	m_DifferentFontLabel = NNLabel::Create( L"ÁøÁöÇÑ ±Ã¼­Ã¼ ¶óº§", L"±Ã¼­Ã¼", 35.f );
	m_DifferentFontLabel->SetPosition( 0.f, 200.f );
	AddChild( m_DifferentFontLabel );
}
LabelExample::~LabelExample()
{

}

void LabelExample::Render()
{
	NNObject::Render();
}
void LabelExample::Update( float dTime )
{

}