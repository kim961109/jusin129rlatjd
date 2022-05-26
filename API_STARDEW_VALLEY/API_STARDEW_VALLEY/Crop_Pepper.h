#pragma once
#include "Crops.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CCrop_Pepper :
	public CCrops
{
public:
	CCrop_Pepper();
	CCrop_Pepper(int iA, float _fX, float _fY);
	virtual ~CCrop_Pepper();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Grow(void);
	const int& Get_Num(void) { return m_iNum; }

private:
	int m_iNum;
	int m_iDay;
};

