#include "stdafx.h"
#include "UI_GambleTalk.h"


CUI_GambleTalk::CUI_GambleTalk()
{
}

CUI_GambleTalk::CUI_GambleTalk(int _iNum, float _fX, float _fY)
	:m_bTalkOn(false), iNum(_iNum), iChangeNum(0)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CUI_GambleTalk::~CUI_GambleTalk()
{
	Release();
}

void CUI_GambleTalk::Initialize(void)
{
	m_tInfo.fCX = 593.f;
	m_tInfo.fCY = 181.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_MINIGAME1.bmp", L"UI_MINIGAME1");

	m_pFrameKey = L"UI_MINIGAME1";
}

void CUI_GambleTalk::Update(void)
{
	Check_Num();
	Update_Rect();
}

void CUI_GambleTalk::Late_Update(void)
{
}

void CUI_GambleTalk::Render(HDC hDC)
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
			0,				// ��Ʈ�� ��� ���� ��ǥ, X,Y
			m_tInfo.fCY * iNum,
			(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
	}
}

void CUI_GambleTalk::Release(void)
{
}
