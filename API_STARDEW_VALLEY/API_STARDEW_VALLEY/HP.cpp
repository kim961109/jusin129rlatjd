#include "stdafx.h"
#include "HP.h"


CHP::CHP()
{
}

CHP::CHP(CObj * _Player)
	:m_pTarget(_Player)
{
	m_tInfo.fX = 995.f;
	m_tInfo.fY = 660.f;
}


CHP::~CHP()
{
	Release();
}

void CHP::Initialize(void)
{
	m_tInfo.fCX = 6.f;
	m_tInfo.fCY = 41.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_2_2.bmp", L"UI_2_2");

	m_pFrameKey = L"UI_2_2";
}

void CHP::Update(void)
{

	Update_Rect();
}

void CHP::Late_Update(void)
{
}

void CHP::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top + 3 * Percentage_Hp() * m_tInfo.fCY),
		3 * int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		3 * int(m_tInfo.fCY * (1.f - Percentage_Hp())),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)(m_tInfo.fCY * (1.f - Percentage_Hp())),
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CHP::Release(void)
{
}

float CHP::Percentage_Hp(void)
{
	int iHp = static_cast<CPlayer*>(m_pTarget)->Get_Hp();
	float fPercentage = 1.f - (float)iHp / 100.f;

	return fPercentage;
}
