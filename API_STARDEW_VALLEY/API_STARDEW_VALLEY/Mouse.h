#pragma once
#include "Obj.h"
class CMouse :
	public CObj
{
public:
	CMouse();
	virtual ~CMouse();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	RECT Get_MOUSERECT(void) { return m_tRect; }
};

