#pragma once
#include "UI.h"
class CUI_WallTalk :
	public CUI
{
public:
	CUI_WallTalk();
	CUI_WallTalk(float _fX, float _fY);
	virtual ~CUI_WallTalk();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_TalkState(void) { return m_bTalkOn; }
	void Set_TalkState(bool _b) { m_bTalkOn = _b; }

private:
	bool m_bTalkOn;
};

