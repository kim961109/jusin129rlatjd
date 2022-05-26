#pragma once
#include "Monster.h"
#include "Player.h"

class CMonster_Bat :
	public CMonster
{
public:
	CMonster_Bat();
	virtual ~CMonster_Bat();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;
};

