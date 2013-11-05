#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "Zombie.h"

class CPoorZombie :	public CZombie
{
public:
	CPoorZombie(void);
	virtual	~CPoorZombie(void);

public :
	NNSprite	*m_PoorZombie;

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CPoorZombie);

protected:
	virtual void initStatus( void );

};

