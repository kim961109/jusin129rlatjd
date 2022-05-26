#include "stdafx.h"
#include "Wall.h"


CWall::CWall()
{
}


CWall::~CWall()
{
	Release();
}

void CWall::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(4.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(-340.f);    //스크롤 개변.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/Minigame2.bmp", L"Minigame2");

	//맵범위안에 가두는 충돌체.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(250.f, 450.f, 400.f, YY));//좌상
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(40.f, 530.f, YY, 200.f));//좌측1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(40.f, 820.f, YY, 200.f));//좌측2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(730.f, 860.f, 1500.f, YY));//하
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1470.f, 500.f, YY, 1200.f));//우
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1290.f, 580.f, YY, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1320.f, 580.f, YY, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1300.f, 800.f, 30.f, YY));//젤 오른쪽벽.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1210.f, 690.f, YY, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1240.f, 690.f, YY, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1110.f, 480.f, 270.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1110.f, 510.f, 270.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(880.f, 430.f, 850.f, YY));//상
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(960.f, 565.f, YY, 180.f));//투명구간 왼쪽수직벽1.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(990.f, 565.f, YY, 180.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(980.f, 650.f, 30.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(960.f, 805.f, YY, 180.f));//투명구간 왼쪽수직벽2.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(990.f, 805.f, YY, 180.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(980.f, 720.f, 30.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1150.f, 690.f, YY, 230.f));//투명구간 오른쪽수직벽.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1180.f, 690.f, YY, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1170.f, 580.f, 30.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1080.f, 760.f, 180.f, YY));//투명구간 아래쪽수직벽.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1080.f, 800.f, 180.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(600.f, 550.f, YY, 240.f));//보통구간 제일 왼쪽수직벽1.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(630.f, 550.f, YY, 240.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(615.f, 670.f, 35.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(600.f, 830.f, YY, 200.f));//보통구간 제일 왼쪽수직벽2.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(630.f, 830.f, YY, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(615.f, 730.f, 35.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(690.f, 670.f, YY, 350.f));//보통구간 중간 수직벽1.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(720.f, 670.f, YY, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(705.f, 500.f, 35.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(820.f, 830.f, YY, 200.f));//아래T.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(850.f, 830.f, YY, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 720.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 690.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(820.f, 500.f, YY, 200.f));//윗T.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(850.f, 500.f, YY, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 610.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 580.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1040.f, 660.f, YY, 180.f));//투명1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1100.f, 610.f, YY, 180.f));//투명2

	//화살 5-6개 정도 생성.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(2000.f, 500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(2500.f, 600.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(3480.f, 650.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(2040.f, 700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(3200.f, 800.f));
	// 보물 상자 추가.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Treasure, CAbstractFactory<CTreasure>::Create_Arrow(1400.f, 800.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Key, CAbstractFactory<CKey>::Create_Arrow(1026.f, 844.f));//키생성위치.

	//대화 UI생성.
	CUIMgr::Get_Instance()->Add_UIWallTalkvec(CUIFactory<CUI_WallTalk>::Create_UI(500.f, 150.f));// 게임 규칙 대화.
}

void CWall::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();
}

void CWall::Late_Update(void)
{
	CCollisionMgr::Collision_Key(CObjMgr::Get_Instance()->Get_List(OBJ_Key), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Box(CObjMgr::Get_Instance()->Get_List(OBJ_Treasure), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Arrow(CObjMgr::Get_Instance()->Get_List(OBJ_Player), CObjMgr::Get_Instance()->Get_List(OBJ_Arrow));
	CObjMgr::Get_Instance()->Late_Update();

	//농장으로의 씬전환.
	if ((m_ChangePoint.x < 40.f)||((m_ChangePoint.x > 1300.f )&& (m_ChangePoint.y < 400.f)))
	{
		CScrollMgr::Get_Instance()->Make_ScrollX(-900.f); // 농장신으로 갈때의 스크롤 변화.
		CScrollMgr::Get_Instance()->Make_ScrollY(-76.f);

		POINT p = { LONG(1770),LONG(453) };//농장으로 갔을때의 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 씬으로 바뀔때 플레이어 위치 주기.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}

}

void CWall::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Minigame2");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);

	CUIMgr::Get_Instance()->Render(hDC);
}

void CWall::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Arrow);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Treasure);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Key);
}
