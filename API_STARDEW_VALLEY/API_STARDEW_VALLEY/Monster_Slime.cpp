#include "stdafx.h"
#include "Monster_Slime.h"


CMonster_Slime::CMonster_Slime()
{
}


CMonster_Slime::~CMonster_Slime()
{
	Release();
}

void CMonster_Slime::Initialize(void)
{
	m_tInfo.fX = 1050.f;
	m_tInfo.fY = 700.f;   // 임시 테스트용 생성위치.

	m_tInfo.fCX = 64.f;
	m_tInfo.fCY = 64.f;

	m_fSpeed = 5.f;
	m_tInfo.m_iAttack = 1;
	m_bDash = false;

	fDashAngle = 0.f;
	fDashX = 0.f;
	fDashY = 0.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/slime.bmp", L"Slime");

	m_pFrameKey = L"Slime";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 7;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = GetTickCount();
}

void CMonster_Slime::Update(void)
{
	float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
	float		fRadian = acosf(fWidth / fDiagonal);
	m_fAngle = (fRadian * 180.f) / PI;

	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		m_fAngle *= -1.f;

	if (!m_bDash)
	{
		fDashAngle = m_fAngle;
		fDashX = m_pTarget->Get_Info().fX;
		fDashY = m_pTarget->Get_Info().fY;
	}
	
	if ((360.f <= fDiagonal) && (500 >= fDiagonal))
	{
		m_tInfo.fX += 0.1 * m_fSpeed * cosf((m_fAngle)* PI / 180.f);
		m_tInfo.fY -= 0.1 * m_fSpeed * sinf((m_fAngle)* PI / 180.f);
	}
	else if ((200.f <= fDiagonal) && (350 >= fDiagonal))
	{
		m_bDash = true;
		CSoundMgr::Get_Instance()->PlaySound(L"slimeHit.wav", SOUND_MONSTER_Slime, g_fSound);
	}
	if (m_bDash)
	{
		m_tInfo.fX += m_fSpeed * cosf((fDashAngle)* PI / 180.f);
		m_tInfo.fY -= m_fSpeed * sinf((fDashAngle)* PI / 180.f);
		if ( (10.f > abs(m_tInfo.fX - fDashX)) && (10.f > abs(m_tInfo.fY - fDashY)))
		{
			m_bDash = false;
		}
	}

	Update_Rect();
}

void CMonster_Slime::Late_Update(void)
{
	Move_Frame();
}

void CMonster_Slime::Render(HDC hDC)
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
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CMonster_Slime::Release(void)
{
}

void CMonster_Slime::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
