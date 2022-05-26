#pragma once
#include "Obj.h"

class CCrops :
	public CObj
{
public:
	CCrops();
	CCrops(float _fX, float _fY);
	virtual ~CCrops();

public:
	virtual void Initialize(void) PURE;
	virtual void Update(void) PURE;
	virtual void Late_Update(void) PURE;
	virtual void Render(HDC hDC) PURE;
	virtual void Release(void) PURE;

	virtual void Update_Rect(void) PURE;

protected:
	int m_iDay;//ó�� �۹��� ���� ����.
};

