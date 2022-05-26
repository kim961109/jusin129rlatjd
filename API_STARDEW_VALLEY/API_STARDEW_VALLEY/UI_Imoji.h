#pragma once
#include "UI.h"
class CUI_Imoji :
	public CUI
{
public:
	CUI_Imoji();
	CUI_Imoji(int iA, float _fX, float _fY);
	virtual ~CUI_Imoji();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int iNum;//몇번째 이모트.
};

