#include "stdafx.h"
#include "UI_Gold.h"


CUI_Gold::CUI_Gold()
{
}

CUI_Gold::CUI_Gold(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_Gold::~CUI_Gold()
{
	Release();
}

void CUI_Gold::Initialize(void)
{
	m_tInfo.fCX = 72.f;
	m_tInfo.fCY = 57.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_3.bmp", L"UI_3");

	m_pFrameKey = L"UI_3";
}

void CUI_Gold::Update(void)
{
	Update_Rect();
}

void CUI_Gold::Late_Update(void)
{
}

void CUI_Gold::Render(HDC hDC)
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

void CUI_Gold::Release(void)
{
}
