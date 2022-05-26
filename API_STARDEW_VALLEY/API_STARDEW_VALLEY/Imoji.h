#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CImoji :
	public CObj
{
public:
	CImoji();
	CImoji(int iA, float _fX, float _fY);
	virtual ~CImoji();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Change_Imoji(int iA) { iNum = iA; }// 다른 객체에서 이함수를 이용해 이모지를 체인지.

private:
	int iNum;//몇번째 이모트.
};

