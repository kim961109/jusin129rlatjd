#pragma once
#include "UI.h"
class CUI_Gold :
	public CUI
{
public:
	CUI_Gold();
	CUI_Gold(float _fX,float _fY);
	virtual ~CUI_Gold();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
};

