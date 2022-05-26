#include "stdafx.h"
#include "Treasure.h"


CTreasure::CTreasure()
{
}

CTreasure::CTreasure(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CTreasure::~CTreasure()
{
	Release();
}

void CTreasure::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Minigame2_Obj/Box.bmp", L"Box");

	m_pFrameKey = L"Box";

	m_tInfo.fCX = 20;
	m_tInfo.fCY = 25;
}

void CTreasure::Update(void)
{
	Update_Rect();
}

void CTreasure::Late_Update(void)
{
}

void CTreasure::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top + iScrollY),
		2 * int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		2 * int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CTreasure::Release(void)
{
}

void CTreasure::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
