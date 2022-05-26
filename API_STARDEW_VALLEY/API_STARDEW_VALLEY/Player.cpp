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
	cout << "�÷��̾� ��ǥ : " << m_tInfo.fX << "\t" << m_tInfo.fY << endl;


#endif // _DEBUG
}

void CPlayer::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	/*BitBlt(hDC,							// ���� ����, ���������� �׸��� �׸� DC
	int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
	int(m_tRect.top),
	int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
	int(m_tInfo.fCY),
	hMemDC,							// ��Ʈ���� ������ �ִ� DC
	0,								// 7, 8���� : ��Ʈ���� ����� ���� ��ǥ, X,Y
	0,
	SRCCOPY);*/						// ���ȿ��, �״�� ���� ���

	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top + iScrollY),
		2 * int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		2 * int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		m_tFrame.iFrameStart * (int)m_tInfo.fCX,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		m_tFrame.iMotion * (int)m_tInfo.fCY,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
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
	// ���⿡ LBUTTON�������� ������ true�� �Ʒ� wasd�� false�϶��� ����
	// �׸��� �÷��̾� ��������Ʈ�� �������� �ڵ� false ����.

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
		// ������ TV���� .360-390x 
		if ((m_curScene == SC_Stage) && (m_tInfo.fX <= 390.f) && (m_tInfo.fX >= 360.f) && (m_tInfo.fY < 410.f))
		{
			static_cast<CTV*>(CObjMgr::Get_Instance()->Get_List(OBJ_TV).front())->TurnOnTV();
		}

		if ((m_curScene == SC_Shop)&&(m_tInfo.fX < 983.f)&&(m_tInfo.fY >= 640.f)&&(m_tInfo.fY <= 670.f))//���ܸ����� ��ȭ.
		{
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_NPCNum(0);
			bool _b = static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[0])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[0])->Set_TalkState(_b);
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_TalkState(_b);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_TalkState(_b);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(0);
		}
		if ((m_curScene == SC_Shop) && (m_tInfo.fY < 501.f) && (m_tInfo.fX >= 750.f) && (m_tInfo.fX <= 790.f))//������� ��ȭ.
		{
			bool _b = static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_TalkState(_b);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_TalkState(_b);
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UITalkvec()[1])->Set_NPCNum(1);
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(3);
		}
		if ((m_curScene == SC_Farm) && (m_tInfo.fY < 1040.f) && (m_tInfo.fX >= 245.f) && (m_tInfo.fX <= 270.f))//��������� ��ȭ.
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
				//Set num�� +1�� �߰��ϴ� ���???????
				static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_iNum(0);
				//���� �߰� �Ͽ� �Ʒ����� RŰ���� ��ȭ�ϱ� ����.
			}
		}
		if ((m_curScene == SC_MinigameGamble) && (m_tInfo.fY < 591.f) && (m_tInfo.fX >= 880.f) && (m_tInfo.fX <= 900.f))//�������� ��ȭ.
		{
			static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(0);
			bool _b = static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[0])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_TalkNPC*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[0])->Set_TalkState(_b);
			static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_TalkState(_b);
			//static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(0);
		}
		if ((m_curScene == SC_MinigameWall) && (m_tInfo.fY < 470.f) && (m_tInfo.fX >= 450.f) && (m_tInfo.fX <= 470.f))//�������� ��ȭ.
		{
			bool _b = static_cast<CUI_WallTalk*>(CUIMgr::Get_Instance()->Get_UIWallTalkvec()[0])->Get_TalkState();
			_b = !_b;
			static_cast<CUI_WallTalk*>(CUIMgr::Get_Instance()->Get_UIWallTalkvec()[0])->Set_TalkState(_b);
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_E))
	{
		// ���ǹ��� �༭ ending
		if ((m_curScene == SC_Farm)&&(m_bTalkOver == true))
		{
			// ����ȯ.
			CSceneMgr::Get_Instance()->Scene_Change(SC_Ending);
		}
	}

	if (CKeyMgr::Get_Instance()->Key_Down(VK_R))
	{
		//�������� ���ϸ� �� ȹ��.
		if ((m_curScene == SC_Shop) && (m_tInfo.fY < 501.f) && (m_tInfo.fX >= 750.f) && (m_tInfo.fX <= 790.f))
		{
			static_cast<CUI_Talk*>(CUIMgr::Get_Instance()->Get_UITalkvec()[2])->Set_iNum(4);
			CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(3, 1, 578.f, 677.f));
		}
		// ��������� ��ȭ���� ������ �ѱ�.
		if ((m_curScene == SC_Farm) && (m_tInfo.fY < 1040.f) && (m_tInfo.fX >= 245.f) && (m_tInfo.fX <= 270.f))
		{
			static_cast<CUI_FarmTalk*>(CUIMgr::Get_Instance()->Get_UIFarmTalkvec()[1])->Set_iNum(1);
			m_bTalkOver = true;
		}
		// Ȧ¦ ���߱� ��ȭ.
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

		if ((m_curScene == SC_Cave3) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[7])->Get_BallBool() == true))   //��Ĺ���� ���.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			// ���콺. ��ġ�� �־��༭ ���ͺ� �����ϴ� �Լ� CObjMgr:: 
			CObjMgr::Get_Instance()->Add_Object(OBJ_Ball, CAbstractFactory<CBall>::Create_Bullet(m_tInfo.fX, m_tInfo.fY, pt.x, pt.y));

		}

		// ��ո�� �ɱ�.
		if (((m_curScene == SC_Cave3)) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[6])->Get_PepperBool() == true)&&(m_bFruit == false))
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			// ���콺. ��ġ�� �־��༭ ��� �����ϴ� �Լ� CObjMgr:: 
			CObjMgr::Get_Instance()->Add_Object(OBJ_HugeCrop, CAbstractFactory<CCrop_Pepper>::Create_HugeCrop(0, pt.x, pt.y));
			// ����� ��ǥ�� ���׿��� �Ѱ���.
			static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Set_FruitPos(pt.x, pt.y);

			m_bFruit = true;
		}

		// �Ѿ� �߻�.
		if (((m_curScene == SC_Cave2) || (m_curScene == SC_Cave1) || (m_curScene == SC_Cave3)) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[4])->Get_WeaponBool() == true))   //������ ���.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			// ���콺. ��ġ�� �־��༭ �Ѿ� �����ϴ� �Լ� CObjMgr:: 
			CObjMgr::Get_Instance()->Add_Object(OBJ_Bullet, CAbstractFactory<CBullet>::Create_Bullet(m_tInfo.fX, m_tInfo.fY, pt.x, pt.y));
			CSoundMgr::Get_Instance()->PlaySound(L"fireball.wav", SOUND_Bullet, g_fSound);
		}


		if (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[0])->Get_AxeBool() == true)   //����� ���.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
			{
				//���⼭ �浹 ����. // ����, ��, Ǯ  ��   ���.
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Source).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Source).end();)
				{
					RECT m_tRC =(*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//��� ��������Ʈ.
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
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//��� ��������Ʈ.
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
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//��� ��������Ʈ.
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
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[0])->Set_Render(true);//��� ��������Ʈ.
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

		if (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[1])->Get_HoeBool() == true)   //������ ���.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
			{
				//���⼭ �浹 ����. // ����, ��, Ǯ  ��   ���.
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Wood).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Wood).end();)
				{
					RECT m_tRC = (*iter)->Get_Rect();
					if (PtInRect(&m_tRC, pt))
					{
						m_bUseTool = true;
						static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[1])->Set_Render(true);//���� ��������Ʈ.
						CSoundMgr::Get_Instance()->PlaySound(L"axchop.wav", SOUND_Wood, g_fSound);
						iter = CObjMgr::Get_Instance()->Get_List(OBJ_Wood).erase(iter);
						// ���⼭ ���� � ������ ������ ȹ�� �Ͽ� �κ��丮�� �߰� ��Ŵ.
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

		if ((m_curScene == SC_Farm)&&(static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[2])->Get_PickaxBool() == true)) // ȣ���� ���.
		{
			POINT		pt;
			GetCursorPos(&pt);
			ScreenToClient(g_hWnd, &pt);

			pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScrollX();
			pt.y -= (int)CScrollMgr::Get_Instance()->Get_ScrollY();

			if ((50.f > abs(pt.x - m_tInfo.fX)) && (50.f > abs(pt.y - m_tInfo.fY)))
			{
				m_bUseTool = true;
				static_cast<CTool*>(CObjMgr::Get_Instance()->Get_Toolvec()[2])->Set_Render(true);//ȣ��. ��������Ʈ.
				CObjMgr::Get_Instance()->Add_Object(OBJ_Land, CAbstractFactory<CLand>::Create_Land(pt.x, pt.y, 0));
				CSoundMgr::Get_Instance()->PlaySound(L"hoeHit.wav", SOUND_Land, g_fSound);
			}
		}
		else if ((m_curScene == SC_Farm) && (static_cast<CUI_Icon*>(CUIMgr::Get_Instance()->Get_UIvec()[3])->Get_WaterBool() == true)) // ���ֱ�.
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
			// ���� ��ٸ� bool = true;
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


	// �κ��丮 ����
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

	//���� ��ũ��.
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

		case TOOL_LEFT://���ʿ��� ���� ���
			m_tFrame.iFrameStart = 0;
			m_tFrame.iFrameEnd = 4;
			m_tFrame.iMotion = 4;
			m_tFrame.dwSpeed = 150;
			m_tFrame.dwTime = GetTickCount();
			break;

		case TOOL_RIGHT://�����ʿ��� ���� ���
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