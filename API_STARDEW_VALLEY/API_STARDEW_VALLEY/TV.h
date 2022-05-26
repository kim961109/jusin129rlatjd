#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"

class CTV :
	public CObj
{
public:
	CTV();
	CTV(float _fX, float _fY);
	virtual ~CTV();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void TurnOnTV(void) { m_bTVOn = true; }
	void Check_Movie(void);
	void Next_Cut(void);//일정시간뒤 다음컷.

private:
	int m_iMovie;//어느 영화인가.
	int m_iFrame;//현재 몇번째 컷인가.최대 9 
	bool m_bTVOn;//티비 시청 중인가?

	DWORD dwOldTime;
};

