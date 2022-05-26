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
	void Next_Cut(void);//�����ð��� ������.

private:
	int m_iMovie;//��� ��ȭ�ΰ�.
	int m_iFrame;//���� ���° ���ΰ�.�ִ� 9 
	bool m_bTVOn;//Ƽ�� ��û ���ΰ�?

	DWORD dwOldTime;
};

