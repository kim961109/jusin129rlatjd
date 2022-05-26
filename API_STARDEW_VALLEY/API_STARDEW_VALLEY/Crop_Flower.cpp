#include "stdafx.h"
#include "Crop_Flower.h"



CCrop_Flower::CCrop_Flower()
{
}

CCrop_Flower::CCrop_Flower(float _fX, float _fY)
	:iNum(0)
{
	m_iDay = g_iDay;
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CCrop_Flower::~CCrop_Flower()
{
	Release();
}

void CCrop_Flower::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Crops/Crops12.bmp", L"Crops12");

	m_pFrameKey = L"Crops12";

	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 16.f;
	m_tFrame.iMotion = 0;
}

void CCrop_Flower::Update(void)
{
	Update_Rect();
}

void CCrop_Flower::Late_Update(void)
{
}

void CCrop_Flower::Render(HDC hDC)
{
	iNum = g_iDay - m_iDay;
	if (6 < iNum)
	{
		iNum = 6;
	}

	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top + iScrollY),
		2 * int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		2 * int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		int(iNum * m_tInfo.fCX),		// 비트맵 출력 시작 좌표, X,Y
		(int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CCrop_Flower::Release(void)
{
}

void CCrop_Flower::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
