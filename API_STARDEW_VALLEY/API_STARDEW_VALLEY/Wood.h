#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CWood :
	public CObj
{
public:
	CWood();
	CWood(int iNum, float _fX, float _fY);
	virtual ~CWood();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	WOODID m_WoodID;
};

