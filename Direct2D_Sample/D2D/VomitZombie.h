#pragma once
#include "nnobject.h"
#include "NNSprite.h"
#include "Zombie.h"

class CVomitZombie :	public CZombie
{
public:
	CVomitZombie(void);
	virtual	~CVomitZombie(void);

public :
	NNSprite	*m_VomitZombie;

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CVomitZombie);

protected:
	virtual void initStatus( void );

};