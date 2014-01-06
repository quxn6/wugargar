#pragma once
#include "nnscene.h"


class CLoadingScene :
	public NNScene
{
public:
	CLoadingScene(void);
	~CLoadingScene(void);


	NNCREATE_FUNC(CLoadingScene);

	void Render();
	void Update( float dTime );


private:
	float elapsed_time;


};

