#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CBall :
	public CObj
{
public:
	CBall();
	CBall(float _fX, float _fY, float _TX, float _TY);
	virtual ~CBall();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Move_Ball(void);

private:
	float m_TargetX;
	float m_TargetY;
	float m_fAngle;
	float m_fSpeed;
	float fRadian;
};

