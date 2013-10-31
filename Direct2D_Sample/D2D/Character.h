#pragma once
class CCharacter
{
public:
	CCharacter(void);
	~CCharacter(void);

public:
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CCharacter);
};

