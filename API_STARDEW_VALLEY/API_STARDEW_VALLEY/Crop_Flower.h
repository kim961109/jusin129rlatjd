#pragma once
#include "Crops.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CCrop_Flower :
	public CCrops   // 이름: 콜리플라워
{
public:
	CCrop_Flower();
	CCrop_Flower(float _fX,float _fY);
	virtual ~CCrop_Flower();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	const int& Get_FlowerNum(void) { return iNum; }

private:
	int iNum;
};

