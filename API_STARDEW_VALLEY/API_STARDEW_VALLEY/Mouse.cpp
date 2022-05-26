#include "stdafx.h"
#include "Mouse.h"


CMouse::CMouse()
{
}


CMouse::~CMouse()
{
	Release();
}

void CMouse::Initialize(void)
{
	m_tInfo.fCX = 32.f;
	m_tInfo.fCY = 32.f;
}

void CMouse::Update(void)
{
	POINT	pt{};

	GetCursorPos(&pt);	// 현재 마우스의 위치 좌표를 얻어오는 함수
	ScreenToClient(g_hWnd, &pt);	// 전체 스크린영역에서 생성한 클라이언트(창) 좌표로 변환

	m_tInfo.fX = (float)pt.x;
	m_tInfo.fY = (float)pt.y;

	m_tInfo.fX = float((int)m_tInfo.fX / 32 * 32);
	//m_tInfo.fX += 8.f;
	m_tInfo.fY = float((int)m_tInfo.fY / 32 * 32);
	//m_tInfo.fY += 8.f;

	Update_Rect();
	ShowCursor(false);		// 마우스 커서를 출력하지 않겠다.
}

void CMouse::Late_Update(void)
{
	/*m_tInfo.fX = float((int)m_tInfo.fX / 32 * 32);
	m_tInfo.fX += 8.f;
	m_tInfo.fY = float((int)m_tInfo.fY / 32 * 32);
	m_tInfo.fY += 8.f;*/
}

void CMouse::Render(HDC hDC)
{
	//Rectangle(hDC, m_tInfo.fX-10, m_tInfo.fY-10, m_tInfo.fX+10, m_tInfo.fY+10);

	MoveToEx(hDC, m_tInfo.fX - m_tInfo.fCX * 0.5f, m_tInfo.fY - m_tInfo.fCY * 0.5f, nullptr);
	LineTo(hDC, m_tInfo.fX - m_tInfo.fCX * 0.5f + 32.f, m_tInfo.fY - m_tInfo.fCY * 0.5f);
	LineTo(hDC, m_tInfo.fX + 32.f - m_tInfo.fCX * 0.5f, m_tInfo.fY+32.f - m_tInfo.fCY * 0.5f);
	LineTo(hDC, m_tInfo.fX - m_tInfo.fCX * 0.5f, m_tInfo.fY+32.f - m_tInfo.fCY * 0.5f);
	LineTo(hDC, m_tInfo.fX - m_tInfo.fCX * 0.5f, m_tInfo.fY - m_tInfo.fCY * 0.5f);
}

void CMouse::Release(void)
{
}

void CMouse::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
