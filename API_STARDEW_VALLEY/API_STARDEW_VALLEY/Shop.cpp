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
	CScrollMgr::Get_Instance()->Make_ScrollY(-410.f);    //스크롤 개변.

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/In_Shop.bmp", L"In_Shop");

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button1.bmp", L"Shop_Button1");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button2.bmp", L"Shop_Button2");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button3.bmp", L"Shop_Button3");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Shop_Button4.bmp", L"Shop_Button4");

	// Shop의 밖을 벗어나지 못하게하는 충돌체.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(900.f, 480.f, 400.f, YY));//잡화점 상.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1080.f, 700.f, YY, 500.f));//우
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(700.f, 550.f, YY, 100.f));//좌1
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(740.f, 560.f, 100.f, YY));//좌2
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(800.f, 760.f, YY, 400.f));//좌3
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(920.f, 690.f, 100.f, YY));//중하
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(920.f, 590.f, 100.f, YY));//중상
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(870.f, 640.f, YY, 100.f));//중좌
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(970.f, 640.f, YY, 100.f));//중우
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(840.f, 780.f, 50.f, YY));//
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(870.f, 830.f, YY, 100.f));//
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(960.f, 830.f, YY, 100.f));//
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(1030.f, 780.f, 130.f, YY));//

	//대화UI
	CUIMgr::Get_Instance()->Add_UITalk(CUIFactory<CUI_Shop>::Create_UI(500.f, 400.f));// 구매버튼을 담을 UI.
	CUIMgr::Get_Instance()->Add_UITalk(CUIFactory<CUI_TalkNPC>::Create_UIBAG(0, 100.f, 130.f));//NPC
	CUIMgr::Get_Instance()->Add_UITalk(CUIFactory<CUI_Talk>::Create_UIBAG(0, 500.f, 150.f));//대화창.
}

void CShop::Update(void)
{
	//대화에 필요한 버튼 생성
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

	//농장으로의 씬전환.
	if ((m_ChangePoint.x > 850.f) && (m_ChangePoint.x < 960.f) && (m_ChangePoint.y > 870.f))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		CScrollMgr::Get_Instance()->Make_ScrollX(-816.f); // 농장신으로 갈때의 스크롤 변화.
		CScrollMgr::Get_Instance()->Make_ScrollY(-516.f);

		POINT p = { LONG(1450),LONG(1005) };//농장으로 갔을때의 위치.
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//Cave2 씬으로 바뀔때 플레이어 위치 주기.

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
	}// 버튼을 UI위에 렌더 시키기 위해.
	
}

void CShop::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
}
