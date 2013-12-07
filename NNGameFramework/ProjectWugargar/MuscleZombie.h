#pragma once
#include "Zombie.h"

class CMuscleZombie :	public CZombie
{
public:
	CMuscleZombie(void);
	virtual	~CMuscleZombie(void);

public :
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CMuscleZombie);

protected:
	virtual void initStatus( void );

};