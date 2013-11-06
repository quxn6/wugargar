#pragma once
#include "nnobject.h"
#include "NNSprite.h"
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

	NNCREATE_FUNC(CIceZombie);

protected:
	virtual void initStatus( void );

};