#include "stdafx.h"
#include "Birds.h"

CBirds::CBirds()
{
}

CBirds::CBirds(int _iNum, int _iDir, float _fX, float _fY, CObj* pObj)
	:m_iKind(_iNum), m_iDir(_iDir), m_fSpeed(4.f), m_pTarget(pObj)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;

	m_fFirstX = _fX;
	m_fFirstY = _fY;
}

CBirds::~CBirds()
{
	Release();
}

void CBirds::Initialize(void)
{
	m_Cur = SLEEP;
	m_Pre = SLEEP;
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 16.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Effect/birds.bmp", L"birds");

	m_pFrameKey = L"birds";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = GetTickCount();
	m_tFrame.iMotion = (STATEID)(m_iKind * 2) + m_Cur;
}

void CBirds::Update(void)
{
	Check_Distance();
	Moving_Birds();
	Update_Rect();
}

void CBirds::Late_Update(void)
{
	Move_Change();
	Move_Frame();
	ChangePos();
	ComeBack();
}

void CBirds::Render(HDC hDC)
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

void CBirds::Release(void)
{
}

void CBirds::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CBirds::Check_Distance(void)
{
	float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	if (100.f > fDiagonal)
	{
		m_Cur = WALK;
	}
}

void CBirds::Moving_Birds(void)
{
	if (m_Cur == WALK)
	{
		if (1 == m_iDir)
		{
			m_tInfo.fX -= m_fSpeed;// 새가 움직임.
		}
		else if (0 == m_iDir)
		{
			m_tInfo.fX += m_fSpeed;
		}
	}
}

void CBirds::Move_Change(void)
{
	if (m_Pre != m_Cur)
	{
		switch (m_Cur)
		{
		case CBirds::SLEEP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iMotion = (STATEID)(m_iKind * 2) + SLEEP;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case CBirds::WALK:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 1;
			m_tFrame.iMotion = (STATEID)(m_iKind * 2) + WALK;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			CSoundMgr::Get_Instance()->PlaySound(L"bird_tweet2.wav", SOUND_Birds, g_fSound);
			break;
		}

		m_Pre = m_Cur;
	}
}

void CBirds::ChangePos(void)
{
	if (m_tInfo.fX < -100.f)
	{
		m_tInfo.fX = 2000.f;
		m_tInfo.fY = m_fFirstY;
	}
}

void CBirds::ComeBack(void)
{
	float		fWidth = m_tInfo.fX - m_fFirstX;

	if ((fWidth > 0.f) && (fWidth < 5.f))
	{
		m_Cur = SLEEP;
		m_tInfo.fX = m_fFirstX;
		m_tInfo.fY = m_fFirstY;
	}
}
