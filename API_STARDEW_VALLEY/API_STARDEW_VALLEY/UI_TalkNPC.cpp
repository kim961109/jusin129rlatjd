#include "stdafx.h"
#include "UI_TalkNPC.h"


CUI_TalkNPC::CUI_TalkNPC()
{
}

CUI_TalkNPC::CUI_TalkNPC(int _Num, float _fX, float _fY)
	:iNum(_Num), m_bTalkOn(false)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CUI_TalkNPC::~CUI_TalkNPC()
{
	Release();
}

void CUI_TalkNPC::Initialize(void)
{
	m_tInfo.fCX = 141.f;
	m_tInfo.fCY = 141.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/UI_NPC.bmp", L"UI_NPC");

	m_pFrameKey = L"UI_NPC";
}

void CUI_TalkNPC::Update(void)
{
	Update_Rect();
}

void CUI_TalkNPC::Late_Update(void)
{
}

void CUI_TalkNPC::Render(HDC hDC)
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
			m_tInfo.fCX * iNum,				// 비트맵 출력 시작 좌표, X,Y
			0,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// 제거하고자 하는 색상
	}
}

void CUI_TalkNPC::Release(void)
{
}
