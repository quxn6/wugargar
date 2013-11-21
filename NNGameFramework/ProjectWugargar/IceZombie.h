#pragma once
#include "Zombie.h"

class CIceZombie :	public CZombie
{
public:
	CIceZombie(void);
	virtual	~CIceZombie(void);

public :
	NNSprite	*m_IceZombie;

	void Render();
	void Update( float dTime );
	void Attack();
	NNCREATE_FUNC(CIceZombie);

protected:
	virtual void initStatus( void );

};