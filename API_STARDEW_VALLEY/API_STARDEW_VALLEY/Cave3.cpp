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

	CObj* pObj = CObjMgr::Get_Instance()->Get_List(OBJ_Player).front(); // 플레이어의 좌표를 얻어옴.

	CObjMgr::Get_Instance()->Add_Object(OBJ_Monster, CAbstractFactory<CMonster_Boss>::Create_Monster(pObj)); //보스 생성.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Caves/cave3.bmp", L"cave3");

	// Cave1의 밖을 벗어나지 못하게하는 충돌체.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 430.f, 260.f, YY));//동굴상.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(950.f, 860.f, 350.f, YY));//동굴하.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(770.f, 650.f, YY, 500.f));//동굴좌.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1140.f, 650.f, YY, 500.f));//동굴우.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1090.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(830.f, 470.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1120.f, 490.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(810.f, 490.f, 50.f, YY));

	//imoji 생성->CObj객체로 생성.
	//CUIMgr::Get_Instance()->Add_UIImoji(CUIFactory<CUI_Imoji>::Create_UIBAG(0, 500.f,500.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Imoji,CAbstractFactory<CImoji>::Create_Imoji(0, 1000.f, 480.f));

}

void CCave3::Update(void)
{
	// 이모트의 iNum을 바꿔주는 함수.
	if (!CObjMgr::Get_Instance()->Get_List(OBJ_Monster).empty())
	{
		if (!CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop).empty())
		{
			if (!CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).empty())//이모지가 존재할때만 잠에서 깬 이모트 표시.
			{
				static_cast<CImoji*>(CObjMgr::Get_Instance()->Get_List(OBJ_Imoji).front())->Change_Imoji(1);
			}
			if (static_cast<CCrop_Pepper*>(CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop).front())->Get_Num() != 0)//과일로 자랐다면.
			{
				// 보스의 상태를 bool로 깨여있음으로 바꿈.
				static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Set_Awaken(true);

				//Move라는 bool변수를 트루로 만들어주는 기능으로 몬스터한테 줌.
				static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Set_Move(true);

				// 이모트를 지우고 보스를 과일로 돌진하게.
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
	//보스가 스킬을 쓸지 말지 판단하는 충돌검사.
	if (!CObjMgr::Get_Instance()->Get_List(OBJ_Monster).empty())
	{
		CCollisionMgr::Collision_Boss(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
		// 보스와 과일이 충돌 했는지 검사.
		CCollisionMgr::Collision_Boss2(CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop), CObjMgr::Get_Instance()->Get_List(OBJ_Monster));
		CCollisionMgr::Collision_Ball(CObjMgr::Get_Instance()->Get_List(OBJ_Ball), CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	}

	//몬스터와 작물의 충돌을 추가. 몬스터와 보스의 충돌 추가(보스 충돌 판정 따로->플레이어 피 1로 하는)
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_HugeCrop), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Ball));

	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Monster), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine1), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));
	CCollisionMgr::Collision_Bullet2(CObjMgr::Get_Instance()->Get_List(OBJ_Mine2), CObjMgr::Get_Instance()->Get_List(OBJ_Bullet));

	CObjMgr::Get_Instance()->Late_Update();

	//농장으로의 씬전환.
	if ((m_ChangePoint.x > 850.f) && (m_ChangePoint.x < 870.f) && (m_ChangePoint.y < 460.f))
	{
		CScrollMgr::Get_Instance()->Make_ScrollX(-76.f);
		CScrollMgr::Get_Instance()->Make_ScrollY(4.f);

		POINT p = { LONG(471),LONG(191) };//농장으로 갔을때의 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 씬으로 바뀔때 플레이어 위치 주기.

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
