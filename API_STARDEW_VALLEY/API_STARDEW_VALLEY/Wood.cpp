#include "stdafx.h"
#include "Wood.h"


CWood::CWood()
{
	m_tInfo.m_iHp = 5;
}

CWood::CWood(int iNum, float _fX, float _fY)
	:m_WoodID((WOODID)iNum)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
	m_tInfo.m_iHp = 5;
}

// 좌표,나무종류를 입력받는 생성자.추가

CWood::~CWood()
{
	Release();
}

void CWood::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Source/Source.bmp", L"Source");

	m_pFrameKey = L"Source";

	m_tInfo.fCX = 66;
	m_tInfo.fCY = 62;
	m_tFrame.iMotion = 0;
}

void CWood::Update(void)
{
	Update_Rect();
}

void CWood::Late_Update(void)
{

}

void CWood::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top + iScrollY),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		m_WoodID * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CWood::Release(void)
{
}

void CWood::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
