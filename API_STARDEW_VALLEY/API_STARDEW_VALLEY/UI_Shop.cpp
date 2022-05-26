#include "stdafx.h"
#include "UI_Shop.h"


CUI_Shop::CUI_Shop()
{
}

CUI_Shop::CUI_Shop(float _fX, float _fY)
	:m_bTalkOn(false)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CUI_Shop::~CUI_Shop()
{
	Release();
}

void CUI_Shop::Initialize(void)
{
	m_tInfo.fCX = 593.f;
	m_tInfo.fCY = 254.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_Shop4.bmp", L"UI_Shop4");

	m_pFrameKey = L"UI_Shop4";
}

void CUI_Shop::Update(void)
{
	Update_Rect();
}

void CUI_Shop::Late_Update(void)
{
}

void CUI_Shop::Render(HDC hDC)
{
	if (m_bTalkOn == true)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
			int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
			int(m_tInfo.fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			0,				// ��Ʈ�� ��� ���� ��ǥ, X,Y
			0,
			(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
	}
}

void CUI_Shop::Release(void)
{
}
