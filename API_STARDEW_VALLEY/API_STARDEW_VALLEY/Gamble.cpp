#include "stdafx.h"
#include "Gamble.h"


CGamble::CGamble()
{
}


CGamble::~CGamble()
{
	Release();
}

void CGamble::Initialize(void)
{
	m_bGamble = true;
	m_iWin = 0;
	m_iLose = 0;

	CScrollMgr::Get_Instance()->Make_ScrollX(-424.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(-344.f);    //스크롤 개변.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/Minigame1.bmp", L"Minigame1");

	// Shop의 밖을 벗어나지 못하게하는 충돌체.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(900.f, 570.f, 100.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(875.f, 700.f, YY, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(905.f, 700.f, YY, 400.f));

	CUIMgr::Get_Instance()->Add_UIGambleTalkvec(CUIFactory<CUI_TalkNPC>::Create_UIBAG(3, 100.f, 130.f));//  프사.
	CUIMgr::Get_Instance()->Add_UIGambleTalkvec(CUIFactory<CUI_GambleTalk>::Create_UIBAG(0, 500.f, 150.f));//  대화.
}

void CGamble::Update(void)
{
	key_Input();
	Warning();

	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();

	Transport();
}

void CGamble::Late_Update(void)
{
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CObjMgr::Get_Instance()->Late_Update();

	//농장으로의 씬전환.
	if ((m_ChangePoint.x > 860.f) && (m_ChangePoint.x < 900.f) && (m_ChangePoint.y > 800.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		CScrollMgr::Get_Instance()->Make_ScrollX(-788.f); // 농장신으로 갈때의 스크롤 변화.
		CScrollMgr::Get_Instance()->Make_ScrollY(-516.f);

		POINT p = { LONG(1200),LONG(980) };//농장으로 갔을때의 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}
}

void CGamble::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Minigame1");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);

	CUIMgr::Get_Instance()->Render(hDC);
}

void CGamble::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
}

void CGamble::key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_J))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"jingle1.wav", SOUND_Win, g_fSound);
		static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(3);
		m_iWin += 1;
		m_iLose = 0;
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Earn_money(1000);
	}
	else if (CKeyMgr::Get_Instance()->Key_Down(VK_K))
	{
		static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(2);
		m_iLose += 1;
	}
}

void CGamble::Warning(void)
{
	if (m_iLose == 3)
	{
		static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Set_iNum(4);
		m_bGamble = false;
	}
}

void CGamble::Transport(void)
{
	if ((m_bGamble == false) && (static_cast<CUI_GambleTalk*>(CUIMgr::Get_Instance()->Get_UIGambleTalkvec()[1])->Get_TalkState() == false))
	{
		//3번 틀리면 강제 농장으로 쫓겨남.
		CScrollMgr::Get_Instance()->Make_ScrollX(-788.f); // 농장신으로 갈때의 스크롤 변화.
		CScrollMgr::Get_Instance()->Make_ScrollY(-516.f);

		POINT p = { LONG(1200),LONG(980) };//농장으로 갔을때의 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}
}
