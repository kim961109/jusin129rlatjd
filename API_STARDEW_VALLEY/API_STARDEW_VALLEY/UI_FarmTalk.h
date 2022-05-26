#pragma once
#include "UI.h"
class CUI_FarmTalk :
	public CUI
{
public:
	CUI_FarmTalk();
	CUI_FarmTalk(int _iNum, float _fX, float _fY);
	virtual ~CUI_FarmTalk();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_TalkState(void) { return m_bTalkOn; }
	void Set_TalkState(bool _b) { m_bTalkOn = _b; }

	void Set_iNum(const int& iA) { iChangeNum = iA; }// �ٸ����� int ���� ���� ����.->����� ��ȭ ���� ����.
	void Check_Num(void) { iNum = iChangeNum; }

private:
	bool m_bTalkOn;
	int iNum;
	int iChangeNum;
};

