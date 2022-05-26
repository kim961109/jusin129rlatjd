#pragma once
#include "Include.h"
class CObj
{
public:
	CObj();
	virtual ~CObj();

public:
	void Move_Frame(void);

public:
	virtual void Initialize(void) PURE;
	virtual void Update(void) PURE;
	virtual void Late_Update(void) PURE;
	virtual void Render(HDC hDC) PURE;
	virtual void Release(void) PURE;

	virtual void Update_Rect(void) PURE;

public:
	void		Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void		Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

public:
	INFO Get_Info(void) { return m_tInfo; }
	RECT Get_Rect(void) { return m_tRect; }
public:
	void Set_Damage(int iA) { m_tInfo.m_iHp -= iA; }
	int& Get_Damage(void) { return m_tInfo.m_iAttack; }


	void		Set_PosX(float _fX) { m_tInfo.fX += _fX; }
	void		Set_PosY(float _fY) { m_tInfo.fY += _fY; }

protected:
	INFO m_tInfo;
	RECT m_tRect;
	FRAME		m_tFrame;

	TCHAR*		m_pFrameKey;
};

