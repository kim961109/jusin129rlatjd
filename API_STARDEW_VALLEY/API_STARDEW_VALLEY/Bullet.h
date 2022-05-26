#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CBullet :
	public CObj
{
public:
	CBullet();
	CBullet(float _fX, float _fY, float _TX, float _TY);
	virtual ~CBullet();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Move_Bullet(void);

private:
	float m_TargetX;
	float m_TargetY;
	float m_fAngle;
	float m_fSpeed;
	float fRadian;
};

