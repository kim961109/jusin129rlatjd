#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}

CPlayer::CPlayer(const POINT& _Pos)
	:m_Pos(_Pos), m_curScene(SC_End), m_bFruit(false), m_bMonster(false), m_bTalkOver(false), m_bWatered(false), m_bUseTool(false)
{
	m_tInfo.m_iHp = 100;
	m_iMoney = 0;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize(void)
{
	m_tInfo.fX = (float)m_Pos.x;
	m_tInfo.fY = (float)m_Pos.y;
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 32.f;

	m_fSpeed = 4.f;
	m_Dir = Dir_Down;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/farmer/farmer_base2.bmp", L"Player");

	m_pFrameKey = L"Player";
	m_tFrame.iFrameStart = 0;
	m_tFrame.iFrameEnd = 0;
	m_tFrame.iMotion = m_Dir;
	m_tFrame.dwSpeed = 150;
	m_tFrame.dwTime = GetTickCount();
}

void CPlayer::Update(void)
{
	m_curScene = CSceneMgr::Get_Instance()->Get_SceneID();
	Key_Input();

	OffSet();

	Update_Rect();

	m_Pos.x = (LONG)m_tInfo.fX;
	m_Pos.y = (LONG)m_tInfo.fY;

	g_iMoney = m_iMoney;
}

void CPlayer::Late_Update(void)
{
	Motion_Change();
	Move_Frame();

#ifdef _DEBUG

	//system("cls");
	cout << "플레이어 좌표 : " << m_tInfo.fX << "\t" << m_tInfo.fY << endl;


#endif // _DEBUG
}

void CPlayer::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	/*BitBlt(hDC,							// 복사 받을, 최종적으로 그림을 그릴 DC
	int(m_tRect.left + iScrollX),	// 2,3 인자 :  복사받을 위치 X, Y
	int(m_tRect.top),
	int(m_tInfo.fCX),				// 4,5 인자 : 복사받을 가로, 세로 길이
	int(m_tInfo.fCY),
	hMemDC,							// 비트맵을 가지고 있는 DC
	0,								// 7, 8인자 : 비트맵을 출력할 시작 좌표, X,Y
	0,
	SRCCOPY);*/						// 출력효과, 그대로 복사 출력

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

void CPlayer::Release(void)
{
}

void CPlayer::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CPlayer::Key_Input(void)
{
	// 여기에 LBUTTON눌럿을때 뭔가를 true로 아래 wasd는 false일때만 성립
	// 그리고 플레이어 스프라이트가 끝났을때 자동 false 변경.

	if (m_bUseTool == true)
	{
		m_eCurState = TOOL_RIGHT;
	}
	else if (m_bUseTool == false)
	{
		if (GetAsyncKeyState(VK_A))
		{
			m_tInfo.fX -= m_fSpeed;
			//m_pFrameKey = L"Player";
			m_eCurState = WALK_LEFT;
			m_Dir = Dir_Left;
			//cout << "motionchange" << endl;
		}
		else if (GetAsyncKeyState(VK_D))//CKeyMgr::Get_Instance()->Key_Down(VK_D))
		{
			m_tInfo.fX += m_fSpeed;
			//m_pFrameKey = L"Player";
			m_eCurState = WALK_RIGHT;
			m_Dir = Dir_Right;
		}
		else if (GetAsyncKeyState(VK_W))
		{
			m_tInfo.fY -= m_fSpeed;
			//m_pFrameKey = L"Player";
			m_eCurState = WALK_UP;
			m_Dir = Dir_Up;
		}
		else if (GetAsyncKeyState(VK_S))
		{
			m_tInfo.fY += m_fSpeed;
			//m_pFrameKey = L"Player";
			m_eCurState = WALK_DOWN;
			m_Dir = Dir_Down;
		}
		else
			m_eCurState = IDLE;
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_Z))
	{
		// 집에서 TV켜짐 .360-390x 
		if ((m_curScene == SC_Stage) && (m_tInfo.fX <= 390.f) && (m_tInfo.fX >= 360.f) && (m_tInfo.fY < 410.f))
		{
			static_cast<CTV*>(CObjMgr::Get_Instance()->Get_List(OBJ_TV).front())->TurnOnTV();
		}

		if ((m_curScene == SC_Shop)&&(m_tInfo.fX < 983.f)&&(m_tInfo.fY >= 640.f)&&(m_tInfo.fY <= 670.f))//아줌마와의 대화.
		{
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_NPCNum(0);
			bool _b = static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[0])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[0])->Set_TalkState(_b);
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_TalkState(_b);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_TalkState(_b);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(0);
		}
		if ((m_curScene == SC_Shop) && (m_tInfo.fY < 501.f) && (m_tInfo.fX >= 750.f) && (m_tInfo.fX <= 790.f))//점장과의 대화.
		{
			bool _b = static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_TalkState(_b);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_TalkState(_b);
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_NPCNum(1);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(3);
		}
		if ((m_curScene == SC_Farm) && (m_tInfo.fY < 1040.f) && (m_tInfo.fX >= 245.f) && (m_tInfo.fX <= 270.f))//마법사와의 대화.
		{
			if (m_bMonster == false)
			{
				static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_iNum(2);
				bool _b = static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[0])->Get_TalkState();
				_b = !_b;
				static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[0])->Set_TalkState(_b);
				static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_TalkState(_b);
			}
			else if (m_bMonster == true)
			{
				bool _b = static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[0])->Get_TalkState();
				_b = !_b;
				static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[0])->Set_TalkState(_b);
				static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_TalkState(_b);
				//Set num를 +1씩 추가하는 방법???????
				static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_iNum(0);
				//새로 추가 하여 아래에서 R키에서 변화하기 쉽게.
			}
		}
		if ((m_curScene == SC_MinigameGamble) && (m_tInfo.fY < 591.f) && (m_tInfo.fX >= 880.f) && (m_tInfo.fX <= 900.f))//갬블러와의 대화.
		{
			static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(0);
			bool _b = static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[0])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[0])->Set_TalkState(_b);
			static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_TalkState(_b);
			//static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(0);
		}
		if ((m_curScene == SC_MinigameWall) && (m_tInfo.fY < 470.f) && (m_tInfo.fX >= 450.f) && (m_tInfo.fX <= 470.f))//갬블러와의 대화.
		{
			bool _b = static_cast<CUI_WallTalk*>(CUIMgr::Get_Instance()->Get_UIWallTalkvec()[0])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_WallTalk*>(CUIMgr::Get_Instance()->Get_UIWallTalkvec()[0])->Set_TalkState(_b);
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_E))
	{
		// 조건문을 줘서 ending
		if ((m_curScene == SC_Farm)&&(m_bTalkOver == true))
		{
			// 씬전환.
			CSceneMgr::Get_Instance()->Scene_Change(SC_Ending);
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_R))
	{
		//상점에서 포켓몬 볼 획득.
		if ((m_curScene == SC_Shop) && (m_tInfo.fY < 501.f) && (m_tInfo.fX >= 750.f) && (m_tInfo.fX <= 790.f))
		{
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(4);
			CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(3, 1, 578.f, 677.f));
		}
		// 마법사와의 대화에서 페이지 넘김.
		if ((m_curScene == SC_Farm) && (m_tInfo.fY < 1040.f) && (m_tInfo.fX >= 245.f) && (m_tInfo.fX <= 270.f))
		{
			static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_iNum(1);
			m_bTalkOver = true;
		}
		// 홀짝 맞추기 대화.
		if ((m_curScene == SC_MinigameGamble) && (m_tInfo.fY < 591.f) && (m_tInfo.fX >= 888.f) && (m_tInfo.fY <= 892.f))
		{
			if (m_iMoney >= 100)
			{
				static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(1);
				static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Use_Money(100);
			}
			else
			{
				static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(5);
			}
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	{

		if ((m_curScene == SC_Cave3) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[7])->Get_BallBool() == true))   //포캣몬볼의 사용.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			// 마우스. 위치를 넣어줘서 몬스터볼 생성하는 함수 CObjMgr:: 
			CObjMgr::Get_Instance()->Add_Object(OBJ_Ball, CAbstractFactory<CBall>::Create_Bullet(m_tInfo.fX, m_tInfo.fY, pt.x, pt.y));

		}

		// 대왕멜론 심기.
		if (((m_curScene == SC_Cave3)) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[6])->Get_PepperBool() == true)&&(m_bFruit == false))
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			// 마우스. 위치를 넣어줘서 멜론 생성하는 함수 CObjMgr:: 
			CObjMgr::Get_Instance()->Add_Object(OBJ_HugeCrop, CAbstractFactory<CCrop_Pepper>::Create_HugeCrop(0, pt.x, pt.y));
			// 멜론의 좌표를 몬스테에게 넘겨줌.
			static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Set_FruitPos(pt.x, pt.y);

			m_bFruit = true;
		}

		// 총알 발사.
		if (((m_curScene == SC_Cave2) || (m_curScene == SC_Cave1) || (m_curScene == SC_Cave3)) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[4])->Get_WeaponBool() == true))   //도끼의 사용.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			// 마우스. 위치를 넣어줘서 총알 생성하는 함수 CObjMgr:: 
			CObjMgr::Get_Instance()->Add_Object(OBJ_Bullet, CAbstractFactory<CBullet>::Create_Bullet(m_tInfo.fX, m_tInfo.fY, pt.x, pt.y));
			CSoundMgr::Get_Instance()->PlaySound(L"fireball.wav", SOUND_Bullet, g_fSound);
		}


		if (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[0])->Get_AxeBool() == true)   //곡괭이의 사용.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
			{
				//여기서 충돌 판정. // 광석, 돌, 풀  과   곡괭이.
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Source).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Source).end();)
				{
					RECT m_tRC =(*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//곡괭이 스프라이트.
						CSoundMgr::Get_Instance()->PlaySound(L"hoe.wav", SOUND_Grass, g_fSound);
						iter = CObjMgr::Get_Instance()->Get_List(OBJ_Source).erase(iter);

						for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
						{
							if (L"Inventory" == dest.first)
							{
								static_cast<CUI_Inven*>(dest.second)->Set_GrassNum();
							}
						}
					}
					else
					{
						++iter;
					}
				}

				//OBJ_Stone
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Stone).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Stone).end();)
				{
					RECT m_tRC = (*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//곡괭이 스프라이트.
						CSoundMgr::Get_Instance()->PlaySound(L"boulderBreak.wav", SOUND_Stone, g_fSound);
						iter = CObjMgr::Get_Instance()->Get_List(OBJ_Stone).erase(iter);

						for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
						{
							if (L"Inventory" == dest.first)
							{
								static_cast<CUI_Inven*>(dest.second)->Set_StoneNum();
							}
						}
					}
					else
					{
						++iter;
					}
				}
			
				//OBJ_Mine1
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Mine1).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Mine1).end();)
				{
					RECT m_tRC = (*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//곡괭이 스프라이트.
						CSoundMgr::Get_Instance()->PlaySound(L"hammer.wav", SOUND_Mine, g_fSound);
						iter = CObjMgr::Get_Instance()->Get_List(OBJ_Mine1).erase(iter);

						for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
						{
							if (L"Inventory" == dest.first)
							{
								static_cast<CUI_Inven*>(dest.second)->Set_GoldNum();
							}
						}
					}
					else
					{
						++iter;
					}
				}

				//OBJ_Mine2
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Mine2).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Mine2).end();)
				{
					RECT m_tRC = (*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//곡괭이 스프라이트.
						CSoundMgr::Get_Instance()->PlaySound(L"hammer.wav", SOUND_Mine, g_fSound);
						iter = CObjMgr::Get_Instance()->Get_List(OBJ_Mine2).erase(iter);

						for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
						{
							if (L"Inventory" == dest.first)
							{
								static_cast<CUI_Inven*>(dest.second)->Set_IridiumNum();
							}
						}
					}
					else
					{
						++iter;
					}
				}

			}
		}

		if (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[1])->Get_HoeBool() == true)   //도끼의 사용.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
			{
				//여기서 충돌 판정. // 광석, 돌, 풀  과   곡괭이.
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Wood).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Wood).end();)
				{
					RECT m_tRC = (*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[1])->Set_Render(true);//도끼 스프라이트.
						CSoundMgr::Get_Instance()->PlaySound(L"axchop.wav", SOUND_Wood, g_fSound);
						iter = CObjMgr::Get_Instance()->Get_List(OBJ_Wood).erase(iter);
						// 여기서 지운 쏘스 기준의 아이템 획득 하여 인벤토리에 추가 시킴.
						for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
						{
							if (L"Inventory" == dest.first)
							{
								static_cast<CUI_Inven*>(dest.second)->Set_WoodNum();
							}
						}
					}
					else
					{
						++iter;
					}
				}

			}
		}

		if ((m_curScene == SC_Farm)&&(static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[2])->Get_PickaxBool() == true)) // 호미의 사용.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
			{
				m_bUseTool = true;
				static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[2])->Set_Render(true);//호미. 스프라이트.
				CObjMgr::Get_Instance()->Add_Object(OBJ_Land, CAbstractFactory<CLand>::Create_Land(pt.x, pt.y, 0));
				CSoundMgr::Get_Instance()->PlaySound(L"hoeHit.wav", SOUND_Land, g_fSound);
			}
		}
		else if ((m_curScene == SC_Farm) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[3])->Get_WaterBool() == true)) // 물주기.
		{
			POINT	pt{};
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			RECT m_R = {};
			for (auto& iter : CObjMgr::Get_Instance()->Get_List(OBJ_Land))
			{
			    m_R = static_cast<CLand*>(iter)->Get_RectLand();
			    if (PtInRect(&m_R, pt))
			    {
			        if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
		        	{
		    		    CObjMgr::Get_Instance()->Add_Object(OBJ_Land, CAbstractFactory<CLand>::Create_Land(pt.x, pt.y, 1));
	    	    	}
	    		}
			}
			// 물을 줬다면 bool = true;
			m_bWatered = true;
		}
		if ((m_curScene == SC_Farm) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[5])->Get_FlowerBool() == true))
		{
			POINT	pt{};
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			RECT m_R = {};
			for (auto& iter : CObjMgr::Get_Instance()->Get_List(OBJ_Land))
			{
				m_R = static_cast<CLand*>(iter)->Get_RectLand();
				if (PtInRect(&m_R, pt))
				{
					if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
					{
			            CObjMgr::Get_Instance()->Add_Object(OBJ_Crops, CCropFactory::Create_Flower(m_R.left + 5.f , m_R.top + 7.f));

					}
				}
			}
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_1))
	{

		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[0])->Get_AxeBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[0])->Set_AxeBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_2))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[1])->Get_HoeBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[1])->Set_HoeBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_3))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[2])->Get_PickaxBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[2])->Set_PickaxBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_4))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[3])->Get_WaterBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[3])->Set_WaterBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_5))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[4])->Get_WeaponBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[4])->Set_WeaponBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_6))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[5])->Get_FlowerBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[5])->Set_FlowerBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_7))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[6])->Get_PepperBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[6])->Set_PepperBool(_b);
	}
	if (CKeyMgr::Get_Instance()->Key_Down(VK_8))
	{
		bool _b = static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[7])->Get_BallBool();
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIvec())
		{
			static_cast<CUI_Icon*>(iter)->Set_False();
		}
		_b = !_b;
		static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[7])->Set_BallBool(_b);
	}


	// 인벤토리 열기
	if (CKeyMgr::Get_Instance()->Key_Down(VK_TAB))
	{
		for (auto& iter : CUIMgr::Get_Instance()->Get_UIInvenmap())
		{
			if (L"Inventory" == iter.first)
			{
				bool _b = static_cast<CUI_Inven*>(iter.second)->Get_InvenBool();
				_b = !_b;
				static_cast<CUI_Inven*>(iter.second)->Set_InvenBool(_b);
			}
		}
	}

	//
	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_F2))
	{
		g_fSound -= 0.1f;

		if (g_fSound < 0.f)
			g_fSound = 0.f;

		CSoundMgr::Get_Instance()->SetChannelVolume(SOUND_EFFECT, g_fSound);
	}

	else if (CKeyMgr::Get_Instance()->Key_Pressing(VK_F3))
	{
		g_fSound += 0.1f;

		if (g_fSound > 1.f)
			g_fSound = 1.f;

		CSoundMgr::Get_Instance()->SetChannelVolume(SOUND_EFFECT, g_fSound);

	}
}

void CPlayer::OffSet(void)
{
	int		iOffSetX = WINCX >> 1;
	int		iOffSetY = WINCY >> 1;
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();
	int		iItvX = 124;
	int		iItvY = 64;

	//왼쪽 스크롤.
	if (iOffSetX - iItvX > m_tInfo.fX + iScrollX)
	    CScrollMgr::Get_Instance()->Set_ScrollX(m_fSpeed);

	if (iOffSetX + iItvX < m_tInfo.fX + iScrollX)
		CScrollMgr::Get_Instance()->Set_ScrollX(-m_fSpeed);

	if (iOffSetY - iItvY > m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(m_fSpeed);

	if (iOffSetY + iItvY < m_tInfo.fY + iScrollY)
		CScrollMgr::Get_Instance()->Set_ScrollY(-m_fSpeed);

	std::cout << CScrollMgr::Get_Instance()->Get_ScrollX() << "," << CScrollMgr::Get_Instance()->Get_ScrollY() << std::endl;
}

void CPlayer::Motion_Change(void)
{
	if (m_ePreState != m_eCurState)
	{
		switch (m_eCurState)
		{
		case IDLE:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 0;
			m_tFrame.iMotion = m_Dir;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case WALK_UP:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = m_Dir;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case WALK_DOWN:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = m_Dir;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case WALK_LEFT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = m_Dir;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case WALK_RIGHT:
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 3;
			m_tFrame.iMotion = m_Dir;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case TOOL_LEFT://왼쪽에서 도구 사용
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iMotion = 4;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case TOOL_RIGHT://오른쪽에서 도구 사용
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iMotion = 5;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;
		}

		m_ePreState = m_eCurState;
	}
}