#pragma once
#include "UI.h"
class CUI_GambleTalk :
	public CUI
{
public:
	CUI_GambleTalk();
	CUI_GambleTalk(int _iNum, float _fX, float _fY);
	virtual ~CUI_GambleTalk();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_TalkState(void) { return m_bTalkOn; }
	void Set_TalkState(bool _b) { m_bTalkOn = _b; }

	void Set_iNum(const int& iA) { iChangeNum = iA; }// 다른에서 int 값을 변경 해줌.->출력할 대화 내용 변경.
	void Check_Num(void) { iNum = iChangeNum; }

private:
	bool m_bTalkOn;
	int iNum;
	int iChangeNum;
};

