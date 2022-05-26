#pragma once
#include "Obj.h"

class CMonster :
	public CObj
{
public:
	CMonster();
	CMonster(CObj * pObj);
	virtual ~CMonster();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	CObj* m_pTarget;

protected:
	float m_fSpeed;
	float m_fAngle;
};

