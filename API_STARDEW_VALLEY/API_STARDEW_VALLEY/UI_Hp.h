#pragma once
#include "UI.h"

class CUI_Hp :
	public CUI
{
public:
	CUI_Hp();
	CUI_Hp(float _fX, float _fY);
	virtual ~CUI_Hp();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
};

