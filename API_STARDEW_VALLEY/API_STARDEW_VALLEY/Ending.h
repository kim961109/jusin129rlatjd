#pragma once
#include "Scene.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"

class CEnding :
	public CScene
{
public:
	CEnding();
	virtual ~CEnding();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void key_Input(void);

private:
	HDC		hGroundMemDC;
	int     iNum;
};

