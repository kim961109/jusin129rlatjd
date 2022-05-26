#include "stdafx.h"
#include "UI_Item.h"


CUI_Item::CUI_Item()
{
}

CUI_Item::CUI_Item(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_Item::~CUI_Item()
{
	Release();
}

void CUI_Item::Initialize(void)
{
	m_tInfo.fCX = 222.f;
	m_tInfo.fCY = 24.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_1.bmp", L"UI_1");

	m_pFrameKey = L"UI_1";
}

void CUI_Item::Update(void)
{
	Update_Rect();
}

void CUI_Item::Late_Update(void)
{
}

void CUI_Item::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 			    // 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	            // 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		3 * int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		3 * int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		0,								// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CUI_Item::Release(void)
{
}
