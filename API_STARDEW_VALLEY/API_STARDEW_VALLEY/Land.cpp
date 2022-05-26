#include "stdafx.h"
#include "Land.h"


CLand::CLand()
{
}

CLand::CLand(float _fX, float _fY, int iA)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
	m_iDrawID = iA;
}


CLand::~CLand()
{
	Release();
}

void CLand::Initialize(void)
{
	m_tInfo.fCX = 16;
	m_tInfo.fCY = 16;

	m_iOption = 0;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Tile/hoeDirt2.bmp", L"Tile");
}

void CLand::Update(void)
{
	Picking_Land();
	Update_Rect();
}

void CLand::Late_Update(void)
{
}

void CLand::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Tile");

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top + iScrollY),
		2 * m_tInfo.fCX,				// 4,5 인자 : 복사받을 가로, 세로 길이                      ------------- 복사받을 크기 조절.
		2 * m_tInfo.fCY,
		hMemDC,							// 비트맵을 가지고 있는 DC
		TILECX * m_iDrawID,								// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CLand::Release(void)
{
}

void CLand::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CLand::Picking_Land(void)
{
	int		x = (int)m_tInfo.fX / 32;
	int		y = (int)m_tInfo.fY / 32;

	//int	iIndex = y * 32 + x;

	m_tInfo.fX = float(x * 32);
	m_tInfo.fY = float(y * 32);
}