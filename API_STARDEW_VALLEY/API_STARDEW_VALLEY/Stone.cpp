#include "stdafx.h"
#include "Stone.h"


CStone::CStone()
{
}

CStone::CStone(int iNum, float _fX, float _fY)
	:m_iID(iNum)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
	m_tInfo.m_iHp = 5;
}


CStone::~CStone()
{
	Release();
}

void CStone::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Source/Source.bmp", L"Source");

	m_pFrameKey = L"Source";

	m_tInfo.fCX = 66;
	m_tInfo.fCY = 62;
	m_tFrame.iMotion = 1;
}

void CStone::Update(void)
{
	Update_Rect();
}

void CStone::Late_Update(void)
{
}

void CStone::Render(HDC hDC)
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
		m_iID * (int)m_tInfo.fCX,		// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CStone::Release(void)
{
}

void CStone::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
