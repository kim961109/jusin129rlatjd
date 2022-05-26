#include "stdafx.h"
#include "Imoji.h"


CImoji::CImoji()
{
}

CImoji::CImoji(int iA, float _fX, float _fY)
	:iNum(iA)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CImoji::~CImoji()
{
	Release();
}

void CImoji::Initialize(void)
{
	m_tInfo.fCX = 14.f;
	m_tInfo.fCY = 14.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_Imoji.bmp", L"UI_Imoji");

	m_pFrameKey = L"UI_Imoji";
}

void CImoji::Update(void)
{
	Update_Rect();
}

void CImoji::Late_Update(void)
{
}

void CImoji::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 			    // 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left + iScrollX),	            // 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top + iScrollY),
		2 * int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		2 * int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		int(m_tInfo.fCX * iNum),				// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CImoji::Release(void)
{
}

void CImoji::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}