#pragma once
#include "Zombie.h"

class CSmogZombie :	public CZombie
{
public:
	CSmogZombie(void);
	virtual	~CSmogZombie(void);

public :
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CSmogZombie);

protected:
	virtual void initStatus( void );

};