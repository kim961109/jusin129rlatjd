#include "stdafx.h"
#include "Tool.h"


CTool::CTool()
{
}

CTool::CTool(CObj * pObj, int _Tool)
	:m_pTarget(pObj), TOOLTYPE(TOOLID(_Tool)), m_bRender(false)
{
}

//CTool::CTool(float _fX, float _fY, int _Tool)
//	: TOOLTYPE(TOOLID(_Tool))
//{
//	m_tInfo.fX = _fX;
//	m_tInfo.fY = _fY;
//}


CTool::~CTool()
{
	Release();
}

void CTool::Initialize(void)
{
	m_tInfo.fX = m_pTarget->Get_Info().fX;
	m_tInfo.fY = m_pTarget->Get_Info().fY;

	m_tInfo.fCX = 64.f;
	m_tInfo.fCY = 64.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/farmer/farmer_tool.bmp", L"farmer_tool");

	m_pFrameKey = L"farmer_tool";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.iMotion = (int)TOOLTYPE;
}

void CTool::Update(void)
{
	Update_Pos();
	Use_Tool();
	Update_Rect();
}

void CTool::Late_Update(void)
{
	Move_Frame();
	Render_Cancel();
}

void CTool::Render(HDC hDC)
{
	if (m_bRender == true)
	{
		int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
		int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top + iScrollY),
			2 * int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			2 * int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
			m_tFrame.iMotion * (int)m_tInfo.fCY,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// 제거하고자 하는 색상
	}
}

void CTool::Release(void)
{
}

void CTool::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CTool::Update_Pos(void)
{
	m_tInfo.fX = m_pTarget->Get_Info().fX - 20.f;
	m_tInfo.fY = m_pTarget->Get_Info().fY - 30.f;// 구체적인 위치는 플레이어의 스프라이트에 따라 변동.
}

void CTool::Render_Cancel(void)
{
	if (m_tFrame.iFrameStart == 4)//마지막 스프라이트에 도착 하면 렌더 취소.
	{
		m_bRender = false;
		m_tFrame.iFrameEnd = 0;
		static_cast<CPlayer*>(m_pTarget)->Set_UseToolBool(false);
	}
}

void CTool::Use_Tool(void)
{
	if (m_bRender == true)
	{
		m_tFrame.iFrameEnd = 4;// 렌더 시작한뒤로 스프라이트 작동. 이전엔 0 상태 유지.
	}
}
