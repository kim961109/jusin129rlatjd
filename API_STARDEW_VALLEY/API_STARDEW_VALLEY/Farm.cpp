#include "stdafx.h"
#include "Farm.h"


CFarm::CFarm()
{
}


CFarm::~CFarm()
{
	Release();
}

void CFarm::Initialize(void)
{
	//플레이어는 다른 씬에서 전환 될때 위치를 받아옴. 위치 받는 함수 예제: Stage씬에 있음.
	// 농장의 밖을 벗어나지 못하게하는 충돌체.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 450.f, float(WINCY >> 1) - 270.f, 1700.f, YY));//상
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 360.f, float(WINCY >> 1) + 220.f, YY, 1100.f));//좌
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 450.f, float(WINCY >> 1) + 710.f, 1700.f, YY));//하
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 1270.f, float(WINCY >> 1) - 130.f, YY, 350.f));//우1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 1270.f, float(WINCY >> 1) + 450.f, YY, 650.f));//우2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(560.f, 130.f, YY, 50.f));//동굴.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(420.f, 130.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(540.f, 170.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(450.f, 170.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1630.f, 710.f, YY, 120.f));//호수.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1730.f, 710.f, YY, 120.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1680.f, 650.f, 100.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1680.f, 770.f, 100.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1200.f, 220.f, YY, 230.f));//집.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1490.f, 220.f, YY, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1270.f, 330.f, 120.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1350.f, 240.f, 320.f, YY));//집내부.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1450.f, 330.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(340.f, 960.f, YY, 100.f));//마법사집.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(210.f, 960.f, YY, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(270.f, 1020.f, 120.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(270.f, 890.f, 120.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1340.f, 800.f, 470.f, YY));//잡화점.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1580.f, 900.f, YY, 150.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1100.f, 900.f, YY, 150.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1150.f, 980.f, 80.f, YY));//하1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1330.f, 980.f, 180.f, YY));//하2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1530.f, 980.f, 90.f, YY));//하3

	//여기서 부턴 나무,돌,풀 등 자원.
	if (CObjMgr::Get_Instance()->Get_List(OBJ_Wood).empty())//나무가 없다면 생성하라.
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(0, 400.f, 500.f));// 나무 source.
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(0, 500.f, 750.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(1, 850.f, 550.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(0, 1250.f, 650.f));
	}

	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 1000.f, 850.f));//풀1 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 968.f, 850.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 936.f, 850.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 904.f, 850.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 872.f, 850.f));//추가1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 1000.f, 881.f));//추가2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 968.f, 881.f));//추가 3
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 1000.f, 819.f));//풀2 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 968.f, 819.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 936.f, 819.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 904.f, 819.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 1000.f, 788.f));//풀3 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 968.f, 788.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 936.f, 788.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 904.f, 788.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 400.f, 350.f));//풀4 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 400.f, 319.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 650.f, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 900.f, 1000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 900.f, 1031.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 868.f, 1031.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_Stone, CAbstractFactory<CStone>::Create_Source(0, 600.f, 600.f));//큰돌 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Stone, CAbstractFactory<CStone>::Create_Source(0, 800.f, 270.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Stone, CAbstractFactory<CStone>::Create_Source(0, 1300.f, 500.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine2, CAbstractFactory<CMines>::Create_Source(1, 900.f, 300.f));//광석.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 932.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 900.f, 269.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine2, CAbstractFactory<CMines>::Create_Source(1, 932.f, 269.f));


	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/farm2.bmp", L"farm");

	//CTileMgr::Get_Instance()->Initialize();

	// NPC 프사 + 대화 추가.
	CUIMgr::Get_Instance()->Add_UIFarmTalkvec(CUIFactory<CUI_TalkNPC>::Create_UIBAG(2, 100.f, 130.f));// 마법사 프사.
	CUIMgr::Get_Instance()->Add_UIFarmTalkvec(CUIFactory<CUI_FarmTalk>::Create_UIBAG(0, 500.f, 150.f));// 마법사 대화.

	// 환경에 날아다니는 새 추가.
	CObj* pObj = CObjMgr::Get_Instance()->Get_List(OBJ_Player).front(); // 플레이어의 좌표를 얻어옴.

	//CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(0, 1, 1000.f, 300.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(0, 1, 1600.f, 250.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(1, 1, 1700.f, 950.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(3, 1, 740.f, 570.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(2, 1, 490.f, 720.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(1, 1, 460.f, 310.f, pObj));

	//공구사용 스프라이트 용도구 객체 생성.
	CObjMgr::Get_Instance()->Add_Tool(CAbstractFactory<CTool>::Create_Tool(pObj, 0));//곡괭이
	CObjMgr::Get_Instance()->Add_Tool(CAbstractFactory<CTool>::Create_Tool(pObj, 1));//도끼
	CObjMgr::Get_Instance()->Add_Tool(CAbstractFactory<CTool>::Create_Tool(pObj, 2));//호미.
}

void CFarm::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	//CTileMgr::Get_Instance()->Update();
	CUIMgr::Get_Instance()->Update();
}

void CFarm::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Source), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Wood), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Stone), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Player));

	CCollisionMgr::Collision_Crops(CObjMgr::Get_Instance()->Get_List(OBJ_Player), CObjMgr::Get_Instance()->Get_List(OBJ_Crops));

	// 씬전환 추가.

	// 집으로 들어가는 씬.
	if ((m_ChangePoint.x > 1330.f) && (m_ChangePoint.x < 1380.f) && (m_ChangePoint.y < 260.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		POINT p = { LONG(360),LONG(400) };//Stage씬중 집문안 좌표.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Stage 씬으로 바뀔때 플레이어 위치 주기.
		CSceneMgr::Get_Instance()->Scene_Change(SC_Stage);
	}
	// 동굴로 들어가는 씬.
	if ((m_ChangePoint.x > 470.f) && (m_ChangePoint.x < 520.f) && (m_ChangePoint.y < 140.f))
	{
		POINT p = { LONG(880),LONG(470) };
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Cave1);
	}
	// 상점으로 들어가는 씬.
	if ((m_ChangePoint.x > 1420.f) && (m_ChangePoint.x < 1480.f) && (m_ChangePoint.y < 1000.f) && (m_ChangePoint.y > 950.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		POINT p = { LONG(880),LONG(870) };//상점에서 생성될 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Shop 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Shop);
	}
	// 홀짝 미니게임 씬/
	if ((m_ChangePoint.x > 1180.f) && (m_ChangePoint.x < 1250.f) && (m_ChangePoint.y < 970.f) && (m_ChangePoint.y > 920.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		POINT p = { LONG(888),LONG(770) };//미니게임(홀짝)에서 생성될 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//미니게임(홀짝) 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_MinigameGamble);
	}
	// 미로길찾기. 미니게임 씬/
	if ((m_ChangePoint.x > 1800.f) && (m_ChangePoint.y < 550.f))
	{
		POINT p = { LONG(70),LONG(660) };//미니게임(홀짝)에서 생성될 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//미니게임(홀짝) 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_MinigameWall);
	}
}

void CFarm::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"farm");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->Render(hDC);
	//CTileMgr::Get_Instance()->Render(hDC);
	CUIMgr::Get_Instance()->Render(hDC);
}

void CFarm::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Source);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Wood);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Stone);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Mine1);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Mine2);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Birds);
}
