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
	} // 플레이어가 없다면 생성.
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Houses/In_House3.bmp", L"In_House");
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX>>1),float(WINCY>>1) - 100.f,200.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 90.f, float(WINCY >> 1) - 50.f, YY, 80.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 90.f, float(WINCY >> 1) - 50.f, YY, 110.f));//TV오른쪽.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 150.f, float(WINCY >> 1) - 20.f, 100.f, YY));// 난로 밑의 충돌.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 190.f, float(WINCY >> 1) + 10.f, YY, 80.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 150.f, float(WINCY >> 1) + 30.f, 120.f, YY));//침대위 충돌.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 100.f, float(WINCY >> 1) + 100.f, YY, 130.f));//침대왼쪽.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) + 20.f, float(WINCY >> 1) + 150.f, 150.f, YY));//방 아래쪽.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 20.f, float(WINCY >> 1) + 120.f, YY, 50.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 80.f, float(WINCY >> 1) + 100.f, 90.f, YY));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 120.f, float(WINCY >> 1) + 150.f, YY, 80.f));
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 140.f, float(WINCY >> 1) , 80.f, YY));//TV아래.
	CObjMgr::Get_Instance()->Add_Object(OBJ_Collision, CAbstractFactory<CObjCollision>::Create_Wall(float(WINCX >> 1) - 170.f, float(WINCY >> 1) + 100, YY, 160.f));//집 왼쪽.

	//집안의 티비에서 볼수 있는 영화 생성.
	CObjMgr::Get_Instance()->Add_Object(OBJ_TV, CAbstractFactory<CTV>::Create_TV(float(WINCX >> 1), float(WINCY >> 1)));

	//여기서 UI를 생성하고 게임 종료시에 삭제.
	if (CUIMgr::Get_Instance()->Get_UIList().empty())
	{
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Hp>::Create_UI(float(WINCX - 35), float(WINCY - 140)));//HP_Bar생성.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Gold>::Create_UI(float(WINCX - 185), 40.f));// Gold,날씨등등 생성.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Item>::Create_UI(float((WINCX >> 1) - 220), float(WINCY - 100)));//아이템 슬롯.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CHP>::Create_UIHP(pPlayer));//녹색 HP.

		//도구 아이콘
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 200.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 255.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 310.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 363.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 417.f, 677.f));  //무기 빨간표시.?
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 470.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 525.f, 677.f));
		CUIMgr::Get_Instance()->Add_UI2(CUIFactory<CUI_Icon>::Create_UIICON(2, 4, 578.f, 677.f));//몬스터 볼. 빨간표시.

		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 1, 200.f, 677.f));//곡괭이
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 2, 255.f, 677.f));//도끼
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 3, 310.f, 677.f));//호미
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(0, 4, 363.f, 677.f));//물주는거....

		//CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(1, 4, 417.f, 677.f));// 무기 좌표.-------> 구매하는 순간에 추가.


		//종자 아이콘
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(10, 0, 470.f, 677.f));// 꽃종자.
		CUIMgr::Get_Instance()->Add_UI(CUIFactory<CUI_Icon>::Create_UIICON(3, 0, 525.f, 677.f));// 멜론종자.....>얘네는 벡터가나을듯???

		//인벤토리 UI
		CUIMgr::Get_Instance()->Add_UIInven(L"Inventory", CUIFactory<CUI_Inven>::Create_UI(float(WINCX >> 1), float(WINCY >> 1)));
		
	}

	// 집안의 고양이 생성.
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

	//farm씬으로 체인지.
	if ((m_ChangePoint.x < (float(WINCX >> 1) - 120.f)) && (m_ChangePoint.y > (float(WINCY >> 1) + 100.f)))
	{
		CSoundMgr::Get_Instance()->PlaySound(L"doorOpen.wav", SOUND_DoorOpen, g_fSound);
		CScrollMgr::Get_Instance()->Make_ScrollX(-896.f);
		CScrollMgr::Get_Instance()->Make_ScrollY(0.f);

		POINT p = { LONG(1370),LONG(265) };//farm씬중 집문앞 좌표.
		//std::cout << CScrollMgr::Get_Instance()->Get_ScrollX() << "," << CScrollMgr::Get_Instance()->Get_ScrollY() << std::endl;
		
		//std::cout << CScrollMgr::Get_Instance()->Get_ScrollX() << "," << CScrollMgr::Get_Instance()->Get_ScrollY() << std::endl;
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Set_PlayerPos(p);
		static_cast<CPlayer*>(CObjMgr::Get_Instance()->Get_List(OBJ_Player).front())->Change_PlayerPos();//farm 씬으로 바뀔때 플레이어 위치 주기.
		CSceneMgr::Get_Instance()->Scene_Change(SC_Farm);
	}
}

void CStage::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"In_House");
	BitBlt(hDC, iScrollX, iScrollY, 1920, 1280, hGroundMemDC, 0, 0, SRCCOPY);// 스크롤이 되는 집안.
	CObjMgr::Get_Instance()->RenderEx(hDC, OBJ_Crops, OBJ_Land);
	CUIMgr::Get_Instance()->Render(hDC);
}

void CStage::Release(void)
{
	// 플레이어 제외한 객체만 삭제.
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Collision);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_Cat);
	CObjMgr::Get_Instance()->Delete_ID(OBJ_TV);
}

