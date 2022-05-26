#include "stdafx.h"
#include "Cave.h"


CCave::CCave()
{
}


CCave::~CCave()
{
	Release();
}

void CCave::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(-492.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(-132.f);

	CObj* pObj = CObjMgr::Get_Instance()->Get_List(OBJ_Player).front(); // �÷��̾��� ��ǥ�� ����.

	CObjMgr::Get_Instance()->Add_Object(OBJ_Monster, CAbstractFactory<CMonster_Bat>::Create_Monster(pObj));   // ����_Bat ����.
	
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Caves/cave1.bmp", L"cave1");

	// Cave1�� ���� ����� ���ϰ��ϴ� �浹ü.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 430.f, 260.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 860.f, 350.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(770.f, 650.f, YY, 500.f));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1140.f, 650.f, YY, 500.f));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1090.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(830.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1120.f, 490.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(810.f, 490.f, 50.f, YY));

	//�������� �ҷ��� ���� ��ġ.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine2, CAbstractFactory<CMines>::Create_Source(1, 880.f, 600.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 1000.f, 700.f));

}

void CCave::Update(void)
{
	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();
}

void CCave::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();

	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Rect(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Bullet(SC_Cave1, CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));

	//����2���� ����ȯ.
	if ((m_ChangePoint.x > 1000.f) && (m_ChangePoint.x < 1050.f) && (m_ChangePoint.y < 830.f)&& (m_ChangePoint.y > 770.f))
	{
		POINT p = { LONG(880),LONG(470) };
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Cave2);
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

void CCave::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"cave1");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);

	CUIMgr::Get_Instance()->Render(hDC);
}

void CCave::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Source);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Monster);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Mine1);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Mine2);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Bullet);
}
