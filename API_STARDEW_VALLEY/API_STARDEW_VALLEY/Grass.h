#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CGrass :
	public CObj
{
public:
	CGrass();
	CGrass(int iNum, float _fX, float _fY);
	virtual ~CGrass();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	GRASSID m_GrassID;
};

