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

		GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
			int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
			int(m_tRect.top + iScrollY),
			2 * int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
			2 * int(m_tInfo.fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
			m_tFrame.iMotion * (int)m_tInfo.fCY,
			(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
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
	m_tInfo.fY = m_pTarget->Get_Info().fY - 30.f;// ��ü���� ��ġ�� �÷��̾��� ��������Ʈ�� ���� ����.
}

void CTool::Render_Cancel(void)
{
	if (m_tFrame.iFrameStart == 4)//������ ��������Ʈ�� ���� �ϸ� ���� ���.
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
		m_tFrame.iFrameEnd = 4;// ���� �����ѵڷ� ��������Ʈ �۵�. ������ 0 ���� ����.
	}
}
