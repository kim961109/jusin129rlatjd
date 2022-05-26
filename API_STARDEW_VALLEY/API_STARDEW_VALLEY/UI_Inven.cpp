#include "stdafx.h"
#include "UI_Inven.h"


CUI_Inven::CUI_Inven()
{
}

CUI_Inven::CUI_Inven(float _fX, float _fY)
	:m_bOn(false), m_iBat(0), m_iFlower(0), m_iGold(0), m_iGrass(0), m_iIridium(0), m_iSlime(0), m_iStone(0), m_iWood(0)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_Inven::~CUI_Inven()
{
	Release();
}

void CUI_Inven::Initialize(void)
{
	m_tInfo.fCX = 396.f;
	m_tInfo.fCY = 446.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_Inventory2.bmp", L"UI_Inventory");

	m_pFrameKey = L"UI_Inventory";
}

void CUI_Inven::Update(void)
{
	Update_Rect();
}

void CUI_Inven::Late_Update(void)
{
}

void CUI_Inven::Render(HDC hDC)
{
	if (m_bOn == true)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC, 			    // 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left),	            // 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			0,								// 비트맵 출력 시작 좌표, X,Y
			0,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// 제거하고자 하는 색상

		// 폰트 출력.
		TCHAR Grass[32] = L"";
		TCHAR Stone[32] = L"";
		TCHAR Wood[32] = L"";
		TCHAR Flower[32] = L"";
		TCHAR Gold[32] = L"";
		TCHAR Iridium[32] = L"";
		TCHAR Bat[32] = L"";
		TCHAR Slime[32] = L"";

		swprintf_s(Grass, L"%02d", m_iGrass);
		swprintf_s(Stone, L"%02d", m_iStone);
		swprintf_s(Wood, L"%02d", m_iWood);
		swprintf_s(Flower, L"%02d", m_iFlower);
		swprintf_s(Gold, L"%02d", m_iGold);
		swprintf_s(Iridium, L"%02d", m_iIridium);
		swprintf_s(Bat, L"%02d", m_iBat);
		swprintf_s(Slime, L"%02d", m_iSlime);

		SetBkMode(hDC, TRANSPARENT); // 폰트 출력시 배경을 지워주는 함수.뒤의 값이 1이면 투명, 2이면 하얀색.(TextOut 바로 앞줄에 씀.)
									 //TextOut(hDC, (int)0.5 * WINCX, (int)0.5*WINCY, (LPCWSTR)Hour, lstrlen((LPCWSTR)Hour));
		TextOut(hDC, 355, 255, Grass, lstrlen(Grass));
		TextOut(hDC, 409, 255, Stone, lstrlen(Stone));
		TextOut(hDC, 463, 255, Wood, lstrlen(Wood));
		TextOut(hDC, 517, 255, Flower, lstrlen(Flower));
		TextOut(hDC, 571, 255, Gold, lstrlen(Gold));
		TextOut(hDC, 625, 255, Iridium, lstrlen(Iridium));
		TextOut(hDC, 679, 255, Bat, lstrlen(Bat));
		TextOut(hDC, 355, 310, Slime, lstrlen(Slime));//두번째 줄.
	}
}

void CUI_Inven::Release(void)
{
}
