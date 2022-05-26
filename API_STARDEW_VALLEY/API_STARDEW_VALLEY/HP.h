#pragma once
#include "UI.h"
#include "Player.h"

class CHP :
	public CUI
{
public:
	CHP();
	CHP(CObj* _Player);
	virtual ~CHP();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	float Percentage_Hp(void);

private:
	CObj* m_pTarget;
};

