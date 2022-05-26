#include "stdafx.h"
#include "MyButton.h"


CMyButton::CMyButton()
	: m_iDrawID(0)
{
}


CMyButton::~CMyButton()
{
	Release();
}

void CMyButton::Initialize(void)
{
	m_tInfo.fCX = 148.f;
	m_tInfo.fCY = 116.f;// 버튼 이미지의 픽셀사이즈.(시작메뉴중)
}

void CMyButton::Update(void)
{
	Update_Rect();
}

void CMyButton::Late_Update(void)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(L"Start", m_pFrameKey))
			{
				CSoundMgr::Get_Instance()->PlaySound(L"button1.wav", SOUND_Button, g_fSound);
				CSceneMgr::Get_Instance()->Scene_Change(SC_Stage);
			}

			else if (!lstrcmp(L"Load", m_pFrameKey))
				DestroyWindow(g_hWnd);

			else if (!lstrcmp(L"Exit", m_pFrameKey))
				DestroyWindow(g_hWnd);

			return;
		}

		m_iDrawID = 1;
	}

	else
		m_iDrawID = 0;


}

void CMyButton::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		int(m_tInfo.fCX) * m_iDrawID,	// 비트맵 출력 시작 좌표, X,Y
		0,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(0, 0, 0));			// 제거하고자 하는 색상

}

void CMyButton::Release(void)
{

}

void CMyButton::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
