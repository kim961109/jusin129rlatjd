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
	CScrollMgr::Get_Instance()->Make_ScrollY(-340.f);    //��ũ�� ����.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/Minigame2.bmp", L"Minigame2");

	//�ʹ����ȿ� ���δ� �浹ü.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(250.f, 450.f, 400.f, YY));//�»�
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(40.f, 530.f, YY, 200.f));//����1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(40.f, 820.f, YY, 200.f));//����2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(730.f, 860.f, 1500.f, YY));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1470.f, 500.f, YY, 1200.f));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1290.f, 580.f, YY, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1320.f, 580.f, YY, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1300.f, 800.f, 30.f, YY));//�� �����ʺ�.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1210.f, 690.f, YY, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1240.f, 690.f, YY, 400.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1110.f, 480.f, 270.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1110.f, 510.f, 270.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(880.f, 430.f, 850.f, YY));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(960.f, 565.f, YY, 180.f));//������ ���ʼ�����1.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(990.f, 565.f, YY, 180.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(980.f, 650.f, 30.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(960.f, 805.f, YY, 180.f));//������ ���ʼ�����2.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(990.f, 805.f, YY, 180.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(980.f, 720.f, 30.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1150.f, 690.f, YY, 230.f));//������ �����ʼ�����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1180.f, 690.f, YY, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1170.f, 580.f, 30.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1080.f, 760.f, 180.f, YY));//������ �Ʒ��ʼ�����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1080.f, 800.f, 180.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(600.f, 550.f, YY, 240.f));//���뱸�� ���� ���ʼ�����1.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(630.f, 550.f, YY, 240.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(615.f, 670.f, 35.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(600.f, 830.f, YY, 200.f));//���뱸�� ���� ���ʼ�����2.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(630.f, 830.f, YY, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(615.f, 730.f, 35.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(690.f, 670.f, YY, 350.f));//���뱸�� �߰� ������1.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(720.f, 670.f, YY, 350.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(705.f, 500.f, 35.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(820.f, 830.f, YY, 200.f));//�Ʒ�T.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(850.f, 830.f, YY, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 720.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 690.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(820.f, 500.f, YY, 200.f));//��T.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(850.f, 500.f, YY, 200.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 610.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(835.f, 580.f, 150.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1040.f, 660.f, YY, 180.f));//����1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1100.f, 610.f, YY, 180.f));//����2

	//ȭ�� 5-6�� ���� ����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(2000.f, 500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(2500.f, 600.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(3480.f, 650.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(2040.f, 700.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Arrow, CAbstractFactory<CArrow>::Create_Arrow(3200.f, 800.f));
	// ���� ���� �߰�.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Treasure, CAbstractFactory<CTreasure>::Create_Arrow(1400.f, 800.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Key, CAbstractFactory<CKey>::Create_Arrow(1026.f, 844.f));//Ű������ġ.

	//��ȭ UI����.
	CUIMgr::Get_Instance()->Add_UIWallTalkvec(CUIFactory<CUI_WallTalk>::Create_UI(500.f, 150.f));// ���� ��Ģ ��ȭ.
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

	//���������� ����ȯ.
	if ((m_ChangePoint.x < 40.f)||((m_ChangePoint.x > 1300.f )&& (m_ChangePoint.y < 400.f)))
	{
		CScrollMgr::Get_Instance()->Make_ScrollX(-900.f); // ��������� ������ ��ũ�� ��ȭ.
		CScrollMgr::Get_Instance()->Make_ScrollY(-76.f);

		POINT p = { LONG(1770),LONG(453) };//�������� �������� ��ġ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 ������ �ٲ� �÷��̾� ��ġ �ֱ�.

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
