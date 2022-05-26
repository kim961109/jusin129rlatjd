#include "stdafx.h"
#include "Imoji.h"


CImoji::CImoji()
{
}

CImoji::CImoji(int iA, float _fX, float _fY)
	:iNum(iA)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CImoji::~CImoji()
{
	Release();
}

void CImoji::Initialize(void)
{
	m_tInfo.fCX = 14.f;
	m_tInfo.fCY = 14.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_Imoji.bmp", L"UI_Imoji");

	m_pFrameKey = L"UI_Imoji";
}

void CImoji::Update(void)
{
	Update_Rect();
}

void CImoji::Late_Update(void)
{
}

void CImoji::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left + iScrollX),	            // 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top + iScrollY),
		2 * int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		2 * int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		int(m_tInfo.fCX * iNum),				// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CImoji::Release(void)
{
}

void CImoji::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}