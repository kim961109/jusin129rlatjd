#include "stdafx.h"
#include "Cave3.h"


CCave3::CCave3()
{
}


CCave3::~CCave3()
{
	Release();
}

void CCave3::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(-492.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(-132.f);

	CObj* pObj = CObjMgr::Get_Instance()->Get_List(OBJ_Player).front(); // �÷��̾��� ��ǥ�� ����.

	CObjMgr::Get_Instance()->Add_Object(OBJ_Monster, CAbstractFactory<CMonster_Boss>::Create_Monster(pObj)); //���� ����.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Caves/cave3.bmp", L"cave3");

	// Cave1�� ���� ����� ���ϰ��ϴ� �浹ü.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 430.f, 260.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 860.f, 350.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(770.f, 650.f, YY, 500.f));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1140.f, 650.f, YY, 500.f));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1090.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(830.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1120.f, 490.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(810.f, 490.f, 50.f, YY));

	//imoji ����->CObj��ü�� ����.
	//CUIMgr::Get_Instance()->Add_UIImoji(CUIFactory<CUI_Imoji>::Create_UIBAG(0, 500.f,500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Imoji,CAbstractFactory<CImoji>::Create_Imoji(0, 1000.f, 480.f));

}

void CCave3::Update(void)
{
	// �̸�Ʈ�� iNum�� �ٲ��ִ� �Լ�.
	if (!CObjMgr::Get_Instance()->Get_List(OBJ_Monster).empty())
	{
		if (!CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop).empty())
		{
			if (!CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).empty())//�̸����� �����Ҷ��� �ῡ�� �� �̸�Ʈ ǥ��.
			{
				static_cast<CImoji*>(CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).front())->Change_Imoji(1);
			}
			if (static_cast<CCrop_Pepper*>(CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop).front())->Get_Num() != 0)//���Ϸ� �ڶ��ٸ�.
			{
				// ������ ���¸� bool�� ������������ �ٲ�.
				static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Set_Awaken(true);

				//Move��� bool������ Ʈ��� ������ִ� ������� �������� ��.
				static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Set_Move(true);

				// �̸�Ʈ�� ����� ������ ���Ϸ� �����ϰ�.
				for (auto& iter = CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).begin(); iter != CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).end();)
				{
					iter = (CObjMgr::Get_Instance()->Get_List(OBJ_Imoji)).erase(iter);
					if (iter == CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).end())
					{
						return;
					}

				}

			}
		}
	}

	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();
}

void CCave3::Late_Update(void)
{
	//������ ��ų�� ���� ���� �Ǵ��ϴ� �浹�˻�.
	if (!CObjMgr::Get_Instance()->Get_List(OBJ_Monster).empty())
	{
		CCollisionMgr::Collision_Boss(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
		// ������ ������ �浹 �ߴ��� �˻�.
		CCollisionMgr::Collision_Boss2(CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop), CObjMgr::Get_Instance()->Get_List(OBJ_Monster));
		CCollisionMgr::Collision_Ball(CObjMgr::Get_Instance()->Get_List(OBJ_Ball), CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	}

	//���Ϳ� �۹��� �浹�� �߰�. ���Ϳ� ������ �浹 �߰�(���� �浹 ���� ����->�÷��̾� �� 1�� �ϴ�)
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Ball));

	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));

	CObjMgr::Get_Instance()->Late_Update();

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

void CCave3::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"cave3");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);

	CUIMgr::Get_Instance()->Render(hDC);
}

void CCave3::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Monster);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Imoji);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Bullet);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_HugeCrop);
}
