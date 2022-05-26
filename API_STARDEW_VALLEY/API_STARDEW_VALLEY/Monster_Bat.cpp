#include "stdafx.h"
#include "Monster_Bat.h"


CMonster_Bat::CMonster_Bat()
{
}

CMonster_Bat::~CMonster_Bat()
{
	Release();
}

void CMonster_Bat::Initialize(void)
{
	CSoundMgr::Get_Instance()->PlaySound(L"batScreech.wav", SOUND_MONSTER_Bat, g_fSound);

	m_tInfo.fX = 1300.f;
	m_tInfo.fY = 1000.f;   // 임시 테스트용 생성위치.

	m_tInfo.fCX = 48.f;
	m_tInfo.fCY = 36.f;

	m_fSpeed = 1.5f;
	m_tInfo.m_iAttack = 1;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/bat.bmp", L"Bat");

	m_pFrameKey = L"Bat";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 3;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = GetTickCount();
}

void CMonster_Bat::Update(void)
{
	float		fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
	float		fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

	float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float		fRadian = acosf(fWidth / fDiagonal);	// acos값으로 나올 수 있는 각도의 범위는 0~180도 사이 값에 해당한다.

	/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		fRadian = (2 * PI) - fRadian;*/

	//	// 라디안 값을 디그리로 치환
	m_fAngle = (fRadian * 180.f) / PI;

	if (m_pTarget->Get_Info().fY > m_tInfo.fY)
		m_fAngle *= -1.f;

	m_tInfo.fX += m_fSpeed * cosf((m_fAngle)* PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf((m_fAngle)* PI / 180.f); 

	Update_Rect();
}

void CMonster_Bat::Late_Update(void)
{
	Move_Frame();
}

void CMonster_Bat::Render(HDC hDC)
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

void CMonster_Bat::Release(void)
{
}

void CMonster_Bat::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}