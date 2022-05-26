#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CArrow :
	public CObj
{
public:
	CArrow();
	CArrow(float _fX, float _fY);
	virtual ~CArrow();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Move_Arrow(void);
	void ChangePos(void);

private:
	float m_fSpeed;
};

