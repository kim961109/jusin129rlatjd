#pragma once
#include "Obj.h"
#include "KeyMgr.h"
#include"SceneMgr.h"
#include "BmpMgr.h"

class CMyButton :
	public CObj
{
public:
	CMyButton();
	virtual ~CMyButton();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	int			m_iDrawID;
};

