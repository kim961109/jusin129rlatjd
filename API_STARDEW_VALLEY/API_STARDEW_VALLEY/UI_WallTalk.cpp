#include "stdafx.h"
#include "UI_WallTalk.h"


CUI_WallTalk::CUI_WallTalk()
{
}

CUI_WallTalk::CUI_WallTalk(float _fX, float _fY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_WallTalk::~CUI_WallTalk()
{
	Release();
}

void CUI_WallTalk::Initialize(void)
{
	m_tInfo.fCX = 593.f;
	m_tInfo.fCY = 181.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_MINIGAME2.bmp", L"UI_MINIGAME2");

	m_pFrameKey = L"UI_MINIGAME2";
}

void CUI_WallTalk::Update(void)
{
	Update_Rect();
}

void CUI_WallTalk::Late_Update(void)
{
}

void CUI_WallTalk::Render(HDC hDC)
{
	if (m_bTalkOn == true)
	{
		HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

		GdiTransparentBlt(hDC, 			    // 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left),	            // 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			0,				// 비트맵 출력 시작 좌표, X,Y
			0,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// 제거하고자 하는 색상
	}
}

void CUI_WallTalk::Release(void)
{
}
