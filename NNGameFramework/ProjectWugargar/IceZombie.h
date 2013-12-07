#pragma once
#include "Zombie.h"

class CIceZombie :	public CZombie
{
public:
	CIceZombie(void);
	virtual	~CIceZombie(void);

public :

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CIceZombie);

protected:
	virtual void initStatus( void );

};