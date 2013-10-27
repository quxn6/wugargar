#pragma once
#include "nnobject.h"
#include "NNSprite.h"

class CPoorZombie :	public NNObject
{
public:
	CPoorZombie(void);
	virtual	~CPoorZombie(void);

public :
	NNSprite	*m_PoorZombie;

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CPoorZombie);

};

