#include "stdafx.h"
#include "Grass.h"


CGrass::CGrass()
{
}

CGrass::CGrass(int iNum, float _fX, float _fY)
	:m_GrassID((GRASSID)iNum)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
	m_tInfo.m_iHp = 1;
}


CGrass::~CGrass()
{
	Release();
}

void CGrass::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Source/Source.bmp", L"Source");

	m_pFrameKey = L"Source";

	m_tInfo.fCX = 32;
	m_tInfo.fCY = 31;
	m_tFrame.iMotion = 4;
}

void CGrass::Update(void)
{
	Update_Rect();
}

void CGrass::Late_Update(void)
{
}

void CGrass::Render(HDC hDC)
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
		m_GrassID * (int)m_tInfo.fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CGrass::Release(void)
{
}

void CGrass::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
