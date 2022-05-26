#include "stdafx.h"
#include "ShopButton.h"
#include "Player.h"


CShopButton::CShopButton()
	: m_iDrawID(0)
{
}

CShopButton::CShopButton(float _fX, float _fY)
	: m_iDrawID(0)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}

CShopButton::~CShopButton()
{
	Release();
}

void CShopButton::Initialize(void)
{
	m_tInfo.fCX = 561.f;
	m_tInfo.fCY = 56.f;// 버튼 이미지의 픽셀사이즈.(상점 구매중.)
}

void CShopButton::Update(void)
{
	Update_Rect();
}

void CShopButton::Late_Update(void)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		//  지금 업데이트 타이밍이 달라서 버튼을 누를때 될때 있고 안될때 있어요.......

		if (CKeyMgr::Get_Instance()->Key_Down(VK_Q))//VK_LBUTTON, VK_Q
		{
			if (!lstrcmp(L"Shop_Button1", m_pFrameKey))
			{
				// 추후에 여기에 돈 크기 비교 코드 추가.
				if (static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_Money() < 10000)
				{
					static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(1);
				}
				else
				{
					CSoundMgr::Get_Instance()->PlaySound(L"coins.wav", SOUND_Coin, g_fSound);
					static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Use_Money(10000);
					CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(1, 4, 417.f, 677.f));
					static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(2);
				}
			}
			else if (!lstrcmp(L"Shop_Button2", m_pFrameKey))
				static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(1);

			else if (!lstrcmp(L"Shop_Button3", m_pFrameKey))
				static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(1);

			else if (!lstrcmp(L"Shop_Button4", m_pFrameKey))
				static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(1);//돈 부족토크.

			return;
		}

		m_iDrawID = 1;
	}

	else
		m_iDrawID = 0;
}

void CShopButton::Render(HDC hDC)
{
	hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// 복사 받을, 최종적으로 그림을 그릴 DC
		int(m_tRect.left),	// 2,3 인자 :  복사받을 위치 X, Y
		int(m_tRect.top),
		int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
		int(m_tInfo.fCY),
		hMemDC,							// 비트맵을 가지고 있는 DC
		0,	                            // 비트맵 출력 시작 좌표, X,Y
		int(m_tInfo.fCY) * m_iDrawID,
		(int)m_tInfo.fCX,				// 복사할 비트맵의 가로, 세로 길이
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// 제거하고자 하는 색상
}

void CShopButton::Release(void)
{
}

void CShopButton::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
