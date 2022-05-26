#include "stdafx.h"
#include "UI_Imoji.h"


CUI_Imoji::CUI_Imoji()
{
}

CUI_Imoji::CUI_Imoji(int iA, float _fX, float _fY)
	:iNum(iA)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CUI_Imoji::~CUI_Imoji()
{
	Release();
}

void CUI_Imoji::Initialize(void)
{
	m_tInfo.fCX = 14.f;
	m_tInfo.fCY = 14.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_Imoji.bmp", L"UI_Imoji");

	m_pFrameKey = L"UI_Imoji";
}

void CUI_Imoji::Update(void)
{
	Update_Rect();
}

void CUI_Imoji::Late_Update(void)
{
}

void CUI_Imoji::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		int(m_tInfo.fCX * iNum),				// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CUI_Imoji::Release(void)
{
}
