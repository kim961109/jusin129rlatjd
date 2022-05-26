#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CStone :
	public CObj
{
public:
	CStone();
	CStone(int iNum, float _fX, float _fY);
	virtual ~CStone();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	int m_iID;//���� ID�� �ϳ��� ���丮 ����ҷ��� default�� ID�� ���� ����.
};

