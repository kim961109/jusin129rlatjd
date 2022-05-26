#pragma once
#include "UI.h"
class CUI_TalkNPC :
	public CUI
{
public:
	CUI_TalkNPC();
	CUI_TalkNPC(int _Num, float _fX, float _fY);
	virtual ~CUI_TalkNPC();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_TalkState(void) { return m_bTalkOn; }
	void Set_TalkState(bool _b) { m_bTalkOn = _b; }
	void Set_NPCNum(int iA) { iNum = iA; }

private:
	int iNum;
	bool m_bTalkOn;
};

