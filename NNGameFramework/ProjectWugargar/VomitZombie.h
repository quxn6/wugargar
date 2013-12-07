#pragma once
#include "Zombie.h"

class CVomitZombie :	public CZombie
{
public:
	CVomitZombie(void);
	virtual	~CVomitZombie(void);

public :
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CVomitZombie);

protected:
	virtual void initStatus( void );

};