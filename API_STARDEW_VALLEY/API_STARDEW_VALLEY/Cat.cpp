#include "stdafx.h"
#include "Cat.h"


CCat::CCat()
{
}

CCat::CCat(float _fX, float _fY)
	:m_Cur(END), m_Pre(END)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CCat::~CCat()
{
	Release();
}

void CCat::Initialize(void)
{
	m_tInfo.fCX = 32.f;
	m_tInfo.fCY = 32.f;

	m_fSpeed = 1.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Effect/cat.bmp", L"Cat");

	m_pFrameKey = L"Cat";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.iMotion = SLEEP;
}

void CCat::Update(void)
{
	Moving_Cat();
	Update_Rect();
}

void CCat::Late_Update(void)
{
	Move_Change();
	Move_Frame();
}

void CCat::Render(HDC hDC)
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

void CCat::Release(void)
{
}

void CCat::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CCat::Moving_Cat(void)
{
	if (m_Cur == WALK)
	{
		m_tInfo.fX -= m_fSpeed;// ����̰� ������.
	}
}

void CCat::Move_Change(void)
{
	if (m_Pre != m_Cur)
	{
		switch (m_Cur)
		{
		case CCat::SLEEP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iMotion = SLEEP;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case CCat::WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = WALK;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			CSoundMgr::Get_Instance()->PlaySound(L"cat_meow2.wav", SOUND_Cat, g_fSound);
			break;
		}

		m_Pre = m_Cur;
	}
}
