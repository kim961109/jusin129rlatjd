#include "stdafx.h"
#include "Stage.h"

#include "Mouse.h"

CStage::CStage()
{
}


CStage::~CStage()
{
	Release();
}

void CStage::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(0.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(0.f);
	//CObjMgr::Get_Instance()->Add_Object(OBJ_Mouse, CAbstractFactory<CMouse>::Create_Mouse());

	POINT p = { LONG(0.5*WINCX),LONG(0.5*WINCY) };
	CObj* pPlayer = CAbstractFactory<CPlayer>::Create_Player(p);
	if (CObjMgr::Get_Instance()->Get_List(OBJ_Player).empty())
	{
		CObjMgr::Get_Instance()->Add_Object(OBJ_Player, pPlayer);
	} // �÷��̾ ���ٸ� ����.
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/In_House3.bmp", L"In_House");
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX>>1),float(WINCY>>1) - 100.f,200.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 90.f, float(WINCY >> 1) - 50.f, YY, 80.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 90.f, float(WINCY >> 1) - 50.f, YY, 110.f));//TV������.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 150.f, float(WINCY >> 1) - 20.f, 100.f, YY));// ���� ���� �浹.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 190.f, float(WINCY >> 1) + 10.f, YY, 80.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 150.f, float(WINCY >> 1) + 30.f, 120.f, YY));//ħ���� �浹.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 100.f, float(WINCY >> 1) + 100.f, YY, 130.f));//ħ�����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 20.f, float(WINCY >> 1) + 150.f, 150.f, YY));//�� �Ʒ���.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 20.f, float(WINCY >> 1) + 120.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 80.f, float(WINCY >> 1) + 100.f, 90.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 120.f, float(WINCY >> 1) + 150.f, YY, 80.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 140.f, float(WINCY >> 1) , 80.f, YY));//TV�Ʒ�.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 170.f, float(WINCY >> 1) + 100, YY, 160.f));//�� ����.

	//������ Ƽ�񿡼� ���� �ִ� ��ȭ ����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_TV, CAbstractFactory<CTV>::Create_TV(float(WINCX >> 1), float(WINCY >> 1)));

	//���⼭ UI�� �����ϰ� ���� ����ÿ� ����.
	if (CUIMgr::Get_Instance()->Get_UIList().empty())
	{
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Hp>::Create_UI(float(WINCX - 35), float(WINCY - 140)));//HP_Bar����.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Gold>::Create_UI(float(WINCX - 185), 40.f));// Gold,������� ����.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Item>::Create_UI(float((WINCX >> 1) - 220), float(WINCY - 100)));//������ ����.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CHP>::Create_UIHP(pPlayer));//��� HP.

		//���� ������
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 200.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 255.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 310.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 363.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 417.f, 677.f));  //���� ����ǥ��.?
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 470.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 525.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 578.f, 677.f));//���� ��. ����ǥ��.

		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 1, 200.f, 677.f));//���
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 2, 255.f, 677.f));//����
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 3, 310.f, 677.f));//ȣ��
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 4, 363.f, 677.f));//���ִ°�....

		//CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(1, 4, 417.f, 677.f));// ���� ��ǥ.-------> �����ϴ� ������ �߰�.


		//���� ������
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(10, 0, 470.f, 677.f));// ������.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(3, 0, 525.f, 677.f));// �������.....>��״� ���Ͱ�������???

		//�κ��丮 UI
		CUIMgr::Get_Instance()->Add_UIInven(L"Inventory", CUIFactory<CUI_Inven>::Create_UI(float(WINCX >> 1), float(WINCY >> 1)));
		
	}

	// ������ ����� ����.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Cat, CAbstractFactory<CCat>::Create_Cat(550.f, 350.f));

}

void CStage::Update(void)
{
	static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_Hp(100);
	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();
}

void CStage::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CCollisionMgr::Collision_Cat(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Cat));
	CCollisionMgr::Collision_Cat2(CObjMgr::Get_Instance()->Get_List(OBJ_Cat), CObjMgr::Get_Instance()->Get_List(OBJ_Player));

	//farm������ ü����.
	if ((m_ChangePoint.x < (float(WINCX >> 1) - 120.f)) && (m_ChangePoint.y > (float(WINCY >> 1) + 100.f)))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		CScrollMgr::Get_Instance()->Make_ScrollX(-896.f);
		CScrollMgr::Get_Instance()->Make_ScrollY(0.f);

		POINT p = { LONG(1370),LONG(265) };//farm���� ������ ��ǥ.
		//std::cout << CScrollMgr::Get_Instance()->Get_ScrollX() << "," << CScrollMgr::Get_Instance()->Get_ScrollY() << std::endl;
		
		//std::cout << CScrollMgr::Get_Instance()->Get_ScrollX() << "," << CScrollMgr::Get_Instance()->Get_ScrollY() << std::endl;
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//farm ������ �ٲ� �÷��̾� ��ġ �ֱ�.
		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}
}

void CStage::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"In_House");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);// ��ũ���� �Ǵ� ����.
	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);
	CUIMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	// �÷��̾� ������ ��ü�� ����.
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Cat);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_TV);
}

