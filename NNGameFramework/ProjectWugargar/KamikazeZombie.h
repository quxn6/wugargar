#pragma once
#include "Zombie.h"

class CKamikazeZombie :	public CZombie
{
public:
	CKamikazeZombie(void);
	virtual	~CKamikazeZombie(void);

public :
	NNSprite	*m_KamikazeZombie;

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CKamikazeZombie);

protected:
	virtual void initStatus( void );

};