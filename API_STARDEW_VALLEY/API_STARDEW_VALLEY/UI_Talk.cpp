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

void CUI_Talk::Initialize(void)//.......---> 버튼의 클릭마다 iNUm값을 부여해서 부동한 내용이 렌더.
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

		GdiTransparentBlt(hDC, 			    // 복사 받을, 최종적으로 그림을 그릴 DC
			int(m_tRect.left),	            // 2,3 인자 :  복사받을 위치 X, Y
			int(m_tRect.top),
			int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
			int(m_tInfo.fCY),
			hMemDC,							// 비트맵을 가지고 있는 DC
			0,				// 비트맵 출력 시작 좌표, X,Y
			m_tInfo.fCY * iNum,
			(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
			(int)m_tInfo.fCY,
			RGB(255, 255, 255));			// 제거하고자 하는 색상
	}
}

void CUI_Talk::Release(void)
{
}
