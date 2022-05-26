#include "stdafx.h"
#include "UI_TalkNPC.h"


CUI_TalkNPC::CUI_TalkNPC()
{
}

CUI_TalkNPC::CUI_TalkNPC(int _Num, float _fX, float _fY)
	:iNum(_Num), m_bTalkOn(false)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CUI_TalkNPC::~CUI_TalkNPC()
{
	Release();
}

void CUI_TalkNPC::Initialize(void)
{
	m_tInfo.fCX = 141.f;
	m_tInfo.fCY = 141.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_NPC.bmp", L"UI_NPC");

	m_pFrameKey = L"UI_NPC";
}

void CUI_TalkNPC::Update(void)
{
	Update_Rect();
}

void CUI_TalkNPC::Late_Update(void)
{
}

void CUI_TalkNPC::Render(HDC hDC)
{
	if (m_bTalkOn == true)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
			int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
			int(m_tInfo.fCY),
			hMemDC,							// ��Ʈ���� ������ �ִ� DC
			m_tInfo.fCX * iNum,				// ��Ʈ�� ��� ���� ��ǥ, X,Y
			0,
			(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
	}
}

void CUI_TalkNPC::Release(void)
{
}
