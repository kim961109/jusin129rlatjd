#include "stdafx.h"
#include "ObjCollision.h"


CObjCollision::CObjCollision()
{
}

CObjCollision::CObjCollision(float _X, float _Y, float CX, float CY)
{
	m_tInfo.fX = _X;
	m_tInfo.fY = _Y;
	m_tInfo.fCX = CX;
	m_tInfo.fCY = CY;   // 부동한 크기의 콜리젼 생성가능.
}


CObjCollision::~CObjCollision()
{
	Release();
}

void CObjCollision::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Collision.bmp", L"Collision");

	m_pFrameKey = L"Collision";
}

void CObjCollision::Update(void)
{
	Update_Rect();
}

void CObjCollision::Late_Update(void)
{
}

void CObjCollision::Render(HDC hDC)
{

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC,
		int(m_tRect.left + iScrollX),
		int(m_tRect.top + iScrollY),
		int(m_tInfo.fCX),
		int(m_tInfo.fCY),
		hMemDC,
		0,
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 255, 254)); //나중에 255로 바꿈, 현재는 효과 검사.
}

void CObjCollision::Release(void)
{
}

void CObjCollision::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
