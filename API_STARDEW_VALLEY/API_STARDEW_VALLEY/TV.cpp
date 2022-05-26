#include "stdafx.h"
#include "TV.h"


CTV::CTV()
{
}

CTV::CTV(float _fX, float _fY)
	:m_iMovie(0), m_bTVOn(false)
{
	m_tInfo.fX = _fX;//화면 중심으로 고정 시킬것. 생성시.
	m_tInfo.fY = _fY;
}


CTV::~CTV()
{
	Release();
}

void CTV::Initialize(void)
{
	m_tInfo.fCX = 338.f;
	m_tInfo.fCY = 246.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Effect/tv_final.bmp", L"tv_final");

	m_pFrameKey = L"tv_final";
	m_iFrame = 0;
	dwOldTime = GetTickCount();
}

void CTV::Update(void)
{
	Next_Cut();
	Update_Rect();
}

void CTV::Late_Update(void)
{
	Check_Movie();
}

void CTV::Render(HDC hDC)
{
	if (m_bTVOn == true)
	{
		//int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
		//int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			m_iFrame * (int)m_tInfo.fCX,								// 비트맵 출력 시작 좌표, X,Y
			m_iMovie * (int)m_tInfo.fCY,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// 제거하고자 하는 색상
	}
}

void CTV::Release(void)
{
}

void CTV::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CTV::Check_Movie(void)
{
	if (m_bTVOn == false)
	{
		m_iMovie = g_iDay % 2;
	}

	if (m_iFrame == 11)
	{
		m_iFrame = 0;
		m_bTVOn = false;
	}
}

void CTV::Next_Cut(void)
{
	if ((dwOldTime + 700 < GetTickCount()) && (m_bTVOn == true)) 
	{
		m_iFrame += 1;
		dwOldTime = GetTickCount();
	}
	if ((m_iFrame == 8) && (m_iMovie == 1))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"log_break1.wav", SOUND_MOVIE_BOOM, g_fSound);
	}
	else if ((m_iFrame == 3) && (m_iMovie == 0))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"owl.wav", SOUND_MOVIE_WOOD, g_fSound);
	}
	else if ((m_iFrame == 6) && (m_iMovie == 0))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"cacklingWitch.wav", SOUND_MOVIE_GHOST, g_fSound);
	}
}
