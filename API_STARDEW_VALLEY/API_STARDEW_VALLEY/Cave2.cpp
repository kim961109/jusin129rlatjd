#include "stdafx.h"
#include "Cave2.h"


CCave2::CCave2()
{
}


CCave2::~CCave2()
{
	Release();
}

void CCave2::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(-492.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(-132.f);

	CObj* pObj = CObjMgr::Get_Instance()->Get_List(OBJ_Player).front(); // �÷��̾��� ��ǥ�� ����.

	CObjMgr::Get_Instance()->Add_Object(OBJ_Monster, CAbstractFactory<CMonster_Slime>::Create_Monster(pObj)); //����_Slime ����.
																											  									  
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Caves/cave2.bmp", L"cave2");

	// Cave1�� ���� ����� ���ϰ��ϴ� �浹ü.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 430.f, 260.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 860.f, 350.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(770.f, 650.f, YY, 500.f));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1140.f, 650.f, YY, 500.f));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1090.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(830.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1120.f, 490.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(810.f, 490.f, 50.f, YY));

	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine2, CAbstractFactory<CMines>::Create_Source(1, 950.f, 550.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 982.f, 550.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 982.f, 581.f));
}

void CCave2::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();
}

void CCave2::Late_Update(void)
{
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Source), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Rect(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));

	CCollisionMgr::Collision_Bullet(SC_Cave2, CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CObjMgr::Get_Instance()->Late_Update();

	// ���� ������ ����.
	if ((m_ChangePoint.x > 1000.f) && (m_ChangePoint.x < 1050.f) && (m_ChangePoint.y < 800.f) && (m_ChangePoint.y > 780.f))
	{
		POINT p = { LONG(880),LONG(470) };
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Cave3);
	}

	//���������� ����ȯ.
	if ((m_ChangePoint.x > 850.f) && (m_ChangePoint.x < 870.f) && (m_ChangePoint.y < 460.f))
	{
		CScrollMgr::Get_Instance()->Make_ScrollX(-76.f);
		CScrollMgr::Get_Instance()->Make_ScrollY(4.f);

		POINT p = { LONG(471),LONG(191) };//�������� �������� ��ġ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}
}

void CCave2::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"cave2");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);

	CUIMgr::Get_Instance()->Render(hDC);
}

void CCave2::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Source);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Monster);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Mine1);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Mine2);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Bullet);
}
