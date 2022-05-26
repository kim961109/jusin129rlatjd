#pragma once
#include "Obj.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"

class CObjCollision :
	public CObj
{
public:
	CObjCollision();
	CObjCollision(float _X, float _Y, float CX, float CY);
	virtual ~CObjCollision();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

private:
	float m_FirstX;
	float m_FirstY;
};

