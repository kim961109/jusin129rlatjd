#pragma once
#include "UI.h"
class CUI_Item : // æ∆¿Ã≈€ ΩΩ∑‘.
	public CUI
{
public:
	CUI_Item();
	CUI_Item(float _fX, float _fY);
	virtual ~CUI_Item();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
};

