#pragma once
#include "UI.h"
class CUI_Talk :
	public CUI
{
public:
	CUI_Talk();
	CUI_Talk(int _iNum, float _fX, float _fY);
	virtual ~CUI_Talk();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_TalkState(void) { return m_bTalkOn; }
	void Set_TalkState(bool _b) { m_bTalkOn = _b; }

	void Set_iNum(int iA) { iNum = iA; }// 버튼객체에서 int 값을 변경 해줌.

private:
	bool m_bTalkOn;
	int iNum;
};

