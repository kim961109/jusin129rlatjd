#pragma once
#include "Monster.h"
#include "Player.h"

class CMonster_Slime :
	public CMonster
{
public:
	CMonster_Slime();
	virtual ~CMonster_Slime();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	bool m_bDash;

	float fDashAngle;
	float fDashX;
	float fDashY;
};

