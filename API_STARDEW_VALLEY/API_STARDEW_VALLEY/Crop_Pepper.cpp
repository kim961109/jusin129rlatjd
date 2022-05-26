#include "stdafx.h"
#include "Crop_Pepper.h"


CCrop_Pepper::CCrop_Pepper()
{
}

CCrop_Pepper::CCrop_Pepper(int iA, float _fX, float _fY)
	:m_iNum(iA)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CCrop_Pepper::~CCrop_Pepper()
{
	Release();
}

void CCrop_Pepper::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Crops/Crops3.bmp", L"Crops3");

	m_pFrameKey = L"Crops3";

	m_tInfo.fCX = 46.f;
	m_tInfo.fCY = 55.f;

	m_iDay = g_iDay;
}

void CCrop_Pepper::Update(void)
{
	Grow();
	Update_Rect();
}

void CCrop_Pepper::Late_Update(void)
{
}

void CCrop_Pepper::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top + iScrollY),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		int(m_iNum * m_tInfo.fCX),		// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CCrop_Pepper::Release(void)
{
}

void CCrop_Pepper::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 1.5f * m_tInfo.fCY);// �����ϴ� ���̰� �ٸ�.
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CCrop_Pepper::Grow(void)
{
	if((m_iDay != g_iDay) && (m_iNum == 0))
	{
		m_iNum = 1;
	}
}
