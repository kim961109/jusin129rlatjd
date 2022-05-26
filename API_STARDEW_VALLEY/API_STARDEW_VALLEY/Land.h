#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CLand :
	public CObj
{
public:
	CLand();
	CLand(float _fX, float _fY, int iA);
	virtual ~CLand();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

	void Picking_Land(void);

public:
	RECT Get_RectLand(void) { return m_tRect; }

private:
	int			m_iDrawID;
	int			m_iOption;
};

