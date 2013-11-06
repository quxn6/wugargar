#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "Zombie.h"

class CMuscleZombie :	public CZombie
{
public:
	CMuscleZombie(void);
	virtual	~CMuscleZombie(void);

public :
	NNSprite	*m_MuscleZombie;

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CMuscleZombie);

protected:
	virtual void initStatus( void );

};