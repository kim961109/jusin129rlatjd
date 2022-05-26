#pragma once
#include "Obj.h"
#include "KeyMgr.h"
#include "BmpMgr.h"
#include "UIMgr.h"

class CShopButton :
	public CObj
{
public:
	CShopButton();
	CShopButton(float _fX, float _fY);
	virtual ~CShopButton();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	int			m_iDrawID;
	HDC		    hMemDC;
};

