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
	//�÷��̾�� �ٸ� ������ ��ȯ �ɶ� ��ġ�� �޾ƿ�. ��ġ �޴� �Լ� ����: Stage���� ����.
	// ������ ���� ����� ���ϰ��ϴ� �浹ü.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 450.f, float(WINCY >> 1) - 270.f, 1700.f, YY));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 360.f, float(WINCY >> 1) + 220.f, YY, 1100.f));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 450.f, float(WINCY >> 1) + 710.f, 1700.f, YY));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 1270.f, float(WINCY >> 1) - 130.f, YY, 350.f));//��1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 1270.f, float(WINCY >> 1) + 450.f, YY, 650.f));//��2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(560.f, 130.f, YY, 50.f));//����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(420.f, 130.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(540.f, 170.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(450.f, 170.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1630.f, 710.f, YY, 120.f));//ȣ��.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1730.f, 710.f, YY, 120.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1680.f, 650.f, 100.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1680.f, 770.f, 100.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1200.f, 220.f, YY, 230.f));//��.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1490.f, 220.f, YY, 230.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1270.f, 330.f, 120.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1350.f, 240.f, 320.f, YY));//������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1450.f, 330.f, 50.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(340.f, 960.f, YY, 100.f));//��������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(210.f, 960.f, YY, 100.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(270.f, 1020.f, 120.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(270.f, 890.f, 120.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1340.f, 800.f, 470.f, YY));//��ȭ��.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1580.f, 900.f, YY, 150.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1100.f, 900.f, YY, 150.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1150.f, 980.f, 80.f, YY));//��1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1330.f, 980.f, 180.f, YY));//��2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1530.f, 980.f, 90.f, YY));//��3

	//���⼭ ���� ����,��,Ǯ �� �ڿ�.
	if (CObjMgr::Get_Instance()->Get_List(OBJ_Wood).empty())//������ ���ٸ� �����϶�.
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(0, 400.f, 500.f));// ���� source.
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(0, 500.f, 750.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(1, 850.f, 550.f));
		CObjMgr::Get_Instance()->Add_Object(OBJ_Wood, CAbstractFactory<CWood>::Create_Source(0, 1250.f, 650.f));
	}

	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 1000.f, 850.f));//Ǯ1 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 968.f, 850.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 936.f, 850.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 904.f, 850.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 872.f, 850.f));//�߰�1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 1000.f, 881.f));//�߰�2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 968.f, 881.f));//�߰� 3
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 1000.f, 819.f));//Ǯ2 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 968.f, 819.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 936.f, 819.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 904.f, 819.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 1000.f, 788.f));//Ǯ3 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 968.f, 788.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 936.f, 788.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 904.f, 788.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 400.f, 350.f));//Ǯ4 source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 400.f, 319.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 650.f, 450.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 900.f, 1000.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(0, 900.f, 1031.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Source, CAbstractFactory<CGrass>::Create_Source(1, 868.f, 1031.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_Stone, CAbstractFactory<CStone>::Create_Source(0, 600.f, 600.f));//ū�� source.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Stone, CAbstractFactory<CStone>::Create_Source(0, 800.f, 270.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Stone, CAbstractFactory<CStone>::Create_Source(0, 1300.f, 500.f));

	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine2, CAbstractFactory<CMines>::Create_Source(1, 900.f, 300.f));//����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 932.f, 300.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine1, CAbstractFactory<CMines>::Create_Source(0, 900.f, 269.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Mine2, CAbstractFactory<CMines>::Create_Source(1, 932.f, 269.f));


	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/farm2.bmp", L"farm");

	//CTileMgr::Get_Instance()->Initialize();

	// NPC ���� + ��ȭ �߰�.
	CUIMgr::Get_Instance()->Add_UIFarmTalkvec(CUIFactory<CUI_TalkNPC>::Create_UIBAG(2, 100.f, 130.f));// ������ ����.
	CUIMgr::Get_Instance()->Add_UIFarmTalkvec(CUIFactory<CUI_FarmTalk>::Create_UIBAG(0, 500.f, 150.f));// ������ ��ȭ.

	// ȯ�濡 ���ƴٴϴ� �� �߰�.
	CObj* pObj = CObjMgr::Get_Instance()->Get_List(OBJ_Player).front(); // �÷��̾��� ��ǥ�� ����.

	//CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(0, 1, 1000.f, 300.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(0, 1, 1600.f, 250.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(1, 1, 1700.f, 950.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(3, 1, 740.f, 570.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(2, 1, 490.f, 720.f, pObj));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Birds, CAbstractFactory<CBirds>::Create_Birds(1, 1, 460.f, 310.f, pObj));

	//������� ��������Ʈ �뵵�� ��ü ����.
	CObjMgr::Get_Instance()->Add_Tool(CAbstractFactory<CTool>::Create_Tool(pObj, 0));//���
	CObjMgr::Get_Instance()->Add_Tool(CAbstractFactory<CTool>::Create_Tool(pObj, 1));//����
	CObjMgr::Get_Instance()->Add_Tool(CAbstractFactory<CTool>::Create_Tool(pObj, 2));//ȣ��.
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

	// ����ȯ �߰�.

	// ������ ���� ��.
	if ((m_ChangePoint.x > 1330.f) && (m_ChangePoint.x < 1380.f) && (m_ChangePoint.y < 260.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		POINT p = { LONG(360),LONG(400) };//Stage���� ������ ��ǥ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Stage ������ �ٲ� �÷��̾� ��ġ �ֱ�.
		CSceneMgr::Get_Instance()->Scene_Change(SC_Stage);
	}
	// ������ ���� ��.
	if ((m_ChangePoint.x > 470.f) && (m_ChangePoint.x < 520.f) && (m_ChangePoint.y < 140.f))
	{
		POINT p = { LONG(880),LONG(470) };
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Cave1);
	}
	// �������� ���� ��.
	if ((m_ChangePoint.x > 1420.f) && (m_ChangePoint.x < 1480.f) && (m_ChangePoint.y < 1000.f) && (m_ChangePoint.y > 950.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		POINT p = { LONG(880),LONG(870) };//�������� ������ ��ġ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Shop ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Shop);
	}
	// Ȧ¦ �̴ϰ��� ��/
	if ((m_ChangePoint.x > 1180.f) && (m_ChangePoint.x < 1250.f) && (m_ChangePoint.y < 970.f) && (m_ChangePoint.y > 920.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		POINT p = { LONG(888),LONG(770) };//�̴ϰ���(Ȧ¦)���� ������ ��ġ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//�̴ϰ���(Ȧ¦) ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_MinigameGamble);
	}
	// �̷α�ã��. �̴ϰ��� ��/
	if ((m_ChangePoint.x > 1800.f) && (m_ChangePoint.y < 550.f))
	{
		POINT p = { LONG(70),LONG(660) };//�̴ϰ���(Ȧ¦)���� ������ ��ġ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//�̴ϰ���(Ȧ¦) ������ �ٲ� �÷��̾� ��ġ �ֱ�.

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
