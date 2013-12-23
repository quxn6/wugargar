#pragma once
#include "nnobject.h"


class NNSprite;
class CCharacter;

class CLightning :
	public NNObject
{
public:
	CLightning(void);
	~CLightning(void);


public:
	virtual void Render();
	virtual void Update( float dTime );
	NNCREATE_FUNC(CLightning);	


private:
	void InitSprite(std::wstring imagePath);
	bool IsCrash(CCharacter *crash_check_sprite);

protected:
	NNSprite	*m_cloudSprite;
	NNSprite	*m_lightning_sprite;
	NNSprite	*m_fall_lightning_sprite;
	bool		m_is_fall_lightning;
	int			m_lightning_damage;
	int			m_pay_lightning;
	clock_t	m_startTime;
	clock_t	m_currentTime;

};
