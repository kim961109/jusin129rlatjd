#include "stdafx.h"
#include "Arrow.h"


CArrow::CArrow()
{
}

CArrow::CArrow(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CArrow::~CArrow()
{
	Release();
}

void CArrow::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Minigame2_Obj/Arrow.bmp", L"Arrow");

	m_pFrameKey = L"Arrow";

	m_tInfo.fCX = 64;
	m_tInfo.fCY = 8;
	m_fSpeed = 8.f;
}

void CArrow::Update(void)
{
	Move_Arrow();
	Update_Rect();
}

void CArrow::Late_Update(void)
{
	// ��ǥ ����.
	ChangePos();
}

void CArrow::Render(HDC hDC)
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
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CArrow::Release(void)
{
}

void CArrow::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CArrow::Move_Arrow(void)
{
	m_tInfo.fX -= m_fSpeed;
}

void CArrow::ChangePos(void)
{
	if (m_tInfo.fX < 0.f)
	{
		m_tInfo.fX = 2200.f;
	}
}
