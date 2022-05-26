#include "stdafx.h"
#include "Shop.h"


CShop::CShop()
{
}


CShop::~CShop()
{
	Release();
}

void CShop::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(-494.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(-410.f);    //��ũ�� ����.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/In_Shop.bmp", L"In_Shop");

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button1.bmp", L"Shop_Button1");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button2.bmp", L"Shop_Button2");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button3.bmp", L"Shop_Button3");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button4.bmp", L"Shop_Button4");

	// Shop�� ���� ����� ���ϰ��ϴ� �浹ü.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(900.f, 480.f, 400.f, YY));//��ȭ�� ��.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1080.f, 700.f, YY, 500.f));//��
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(700.f, 550.f, YY, 100.f));//��1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(740.f, 560.f, 100.f, YY));//��2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(800.f, 760.f, YY, 400.f));//��3
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(920.f, 690.f, 100.f, YY));//����
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(920.f, 590.f, 100.f, YY));//�߻�
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(870.f, 640.f, YY, 100.f));//����
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(970.f, 640.f, YY, 100.f));//�߿�
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(840.f, 780.f, 50.f, YY));//
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(870.f, 830.f, YY, 100.f));//
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(960.f, 830.f, YY, 100.f));//
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1030.f, 780.f, 130.f, YY));//

	//��ȭUI
	CUIMgr::Get_Instance()->Add_UITalk(CUIFactory<CUI_Shop>::Create_UI(500.f, 400.f));// ���Ź�ư�� ���� UI.
	CUIMgr::Get_Instance()->Add_UITalk(CUIFactory<CUI_TalkNPC>::Create_UIBAG(0, 100.f, 130.f));//NPC
	CUIMgr::Get_Instance()->Add_UITalk(CUIFactory<CUI_Talk>::Create_UIBAG(0, 500.f, 150.f));//��ȭâ.
}

void CShop::Update(void)
{
	//��ȭ�� �ʿ��� ��ư ����
	if (static_cast<CUI_Shop*>(CUIMgr::Get_Instance()->Get_UITalkvec()[0])->Get_TalkState() == true)
	{
		if (CObjMgr::Get_Instance()->Get_List(OBJ_MyButton).empty())
		{
			CObj*		pButton = CAbstractFactory<CShopButton>::Create_ShopButton(500.f, 315.f);
			pButton->Set_FrameKey(L"Shop_Button1");
			CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);

			pButton = CAbstractFactory<CShopButton>::Create_ShopButton(500.f, 371.f);
			pButton->Set_FrameKey(L"Shop_Button2");
			CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);

			pButton = CAbstractFactory<CShopButton>::Create_ShopButton(500.f, 427.f);
			pButton->Set_FrameKey(L"Shop_Button3");
			CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);

			pButton = CAbstractFactory<CShopButton>::Create_ShopButton(500.f, 483.f);
			pButton->Set_FrameKey(L"Shop_Button4");
			CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);
		}
	}
	else
	{
		CObjMgr::Get_Instance()->Delete_ID(OBJ_MyButton);
	}
	CObjMgr::Get_Instance()->Update();
	m_ChangePoint = static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Get_PlayerPos();
	CUIMgr::Get_Instance()->Update();
}

void CShop::Late_Update(void)
{
	CCollisionMgr::Collision_RectEx(CObjMgr::Get_Instance()->Get_List(OBJ_Collision), CObjMgr::Get_Instance()->Get_List(OBJ_Player));
	CObjMgr::Get_Instance()->Late_Update();

	//���������� ����ȯ.
	if ((m_ChangePoint.x > 850.f) && (m_ChangePoint.x < 960.f) && (m_ChangePoint.y > 870.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		CScrollMgr::Get_Instance()->Make_ScrollX(-816.f); // ��������� ������ ��ũ�� ��ȭ.
		CScrollMgr::Get_Instance()->Make_ScrollY(-516.f);

		POINT p = { LONG(1450),LONG(1005) };//�������� �������� ��ġ.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 ������ �ٲ� �÷��̾� ��ġ �ֱ�.

		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}
}

void CShop::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"In_Shop");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);


	CObjMgr::Get_Instance()->RenderEx2(hDC, OBJ_Crops, OBJ_Land, OBJ_MyButton);

	CUIMgr::Get_Instance()->Render(hDC);

	
	for (auto& iter : CObjMgr::Get_Instance()->Get_List(OBJ_MyButton))
	{
		iter->Render(hDC);
	}// ��ư�� UI���� ���� ��Ű�� ����.
	
}

void CShop::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
}
