#pragma once
#include "police.h"

class CNormalPolice :
	public CPolice
{
public:
	CNormalPolice(void);
	~CNormalPolice(void);

public:

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CNormalPolice);

protected:
	virtual void initStatus( void );

};

