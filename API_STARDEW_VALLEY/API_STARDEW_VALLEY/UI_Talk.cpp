#include "stdafx.h"
#include "UI_Talk.h"


CUI_Talk::CUI_Talk()
{
}

CUI_Talk::CUI_Talk(int _iNum, float _fX, float _fY)
	:m_bTalkOn(false), iNum(_iNum)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_Talk::~CUI_Talk()
{
	Release();
}

void CUI_Talk::Initialize(void)//.......---> ��ư�� Ŭ������ iNUm���� �ο��ؼ� �ε��� ������ ����.
{
	m_tInfo.fCX = 593.f;
	m_tInfo.fCY = 181.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_Talk.bmp", L"UI_Talk");

	m_pFrameKey = L"UI_Talk";
}

void CUI_Talk::Update(void)
{
	Update_Rect();
}

void CUI_Talk::Late_Update(void)
{
}

void CUI_Talk::Render(HDC hDC)
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

void CUI_Talk::Release(void)
{
}
