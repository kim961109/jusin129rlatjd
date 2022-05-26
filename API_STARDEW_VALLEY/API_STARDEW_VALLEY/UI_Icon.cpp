#include "stdafx.h"
#include "UI_Icon.h"


CUI_Icon::CUI_Icon()
{
}

CUI_Icon::CUI_Icon(int _iX, int _iY, float _fX, float _fY)
	:iXNum(_iX),iYNum(_iY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
	
	bAxe = false;
	bHoe = false;
	bPickax = false;
	bWater = false;
	bFlower = false;
	bPepper = false;
	bWeapon = false;
	bBall = false;
}

CUI_Icon::~CUI_Icon()
{
	Release();
}

void CUI_Icon::Initialize(void)
{
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 16.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/icon.bmp", L"Icon");

	m_pFrameKey = L"Icon";
}

void CUI_Icon::Update(void)
{
	Update_Rect();
}

void CUI_Icon::Late_Update(void)
{
}

void CUI_Icon::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 			    // 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	            // 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		3 * int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		3 * int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		int(m_tInfo.fCX * iXNum),			// 비트맵 출력 시작 좌표, X,Y
		int(m_tInfo.fCY * iYNum),
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CUI_Icon::Release(void)
{
}
