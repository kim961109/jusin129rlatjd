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

	GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		3 * int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		3 * int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CUI_Item::Release(void)
{
}
