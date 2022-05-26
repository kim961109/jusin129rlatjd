#include "stdafx.h"
#include "UI_Hp.h"


CUI_Hp::CUI_Hp()
{
}

CUI_Hp::CUI_Hp(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_Hp::~CUI_Hp()
{
	Release();
}

void CUI_Hp::Initialize(void)
{
	m_tInfo.fCX = 12.f;
	m_tInfo.fCY = 56.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_2.bmp", L"UI_2");

	m_pFrameKey = L"UI_2";
}

void CUI_Hp::Update(void)
{
	Update_Rect();
}

void CUI_Hp::Late_Update(void)
{
}

void CUI_Hp::Render(HDC hDC)
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

void CUI_Hp::Release(void)
{
}
