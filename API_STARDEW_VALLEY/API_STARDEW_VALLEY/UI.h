#pragma once
#include "Include.h"
#include "BmpMgr.h"

class CUI
{
public:
	CUI();
	virtual ~CUI();

public:
	virtual void Initialize(void) PURE;
	virtual void Update(void) PURE;
	virtual void Late_Update(void) PURE;
	virtual void Render(HDC hDC) PURE;
	virtual void Release(void) PURE;

	void Update_Rect(void);

protected:
	UIINFO m_tInfo;
	ICON m_tIcon;
	RECT m_tRect;

	TCHAR*		m_pFrameKey;
};

