#pragma once
#include "Zombie.h"

class CHeroZombie :	public CZombie
{
public:
	CHeroZombie(void);
	virtual	~CHeroZombie(void);

public :
	NNSprite	*m_HeroZombie;

	void Render();
	void Update( float dTime );



	NNCREATE_FUNC(CHeroZombie);

protected:
	virtual void initStatus( void );

};