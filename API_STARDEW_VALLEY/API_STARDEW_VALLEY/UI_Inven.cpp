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

		GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
			int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
			int(m_tInfo.fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
			0,
			(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����

		// ��Ʈ ���.
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

		SetBkMode(hDC, TRANSPARENT); // ��Ʈ ��½� ����� �����ִ� �Լ�.���� ���� 1�̸� ����, 2�̸� �Ͼ��.(TextOut �ٷ� ���ٿ� ��.)
									 //TextOut(hDC, (int)0.5 * WINCX, (int)0.5*WINCY, (LPCWSTR)Hour, lstrlen((LPCWSTR)Hour));
		TextOut(hDC, 355, 255, Grass, lstrlen(Grass));
		TextOut(hDC, 409, 255, Stone, lstrlen(Stone));
		TextOut(hDC, 463, 255, Wood, lstrlen(Wood));
		TextOut(hDC, 517, 255, Flower, lstrlen(Flower));
		TextOut(hDC, 571, 255, Gold, lstrlen(Gold));
		TextOut(hDC, 625, 255, Iridium, lstrlen(Iridium));
		TextOut(hDC, 679, 255, Bat, lstrlen(Bat));
		TextOut(hDC, 355, 310, Slime, lstrlen(Slime));//�ι�° ��.
	}
}

void CUI_Inven::Release(void)
{
}
