#include "stdafx.h"
#include "MyMenu.h"


CMyMenu::CMyMenu()
{
}


CMyMenu::~CMyMenu()
{
	Release();
}

void CMyMenu::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/stardewPanorama.bmp", L"stardewPanorama");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Start.bmp", L"Start");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Load.bmp", L"Load");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Button/Exit.bmp", L"Exit");

	//CObjMgr::Get_Instance()->Add_Object(OBJ_Mouse, CAbstractFactory<CMouse>::Create_Mouse());//마우스 생성.

	CObj*		pButton = CAbstractFactory<CMyButton>::Create_Button(230.f, 550.f);
	pButton->Set_FrameKey(L"Start");
	CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);

	pButton = CAbstractFactory<CMyButton>::Create_Button(500.f, 550.f);
	pButton->Set_FrameKey(L"Load");
	CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);

	pButton = CAbstractFactory<CMyButton>::Create_Button(770.f, 550.f);
	pButton->Set_FrameKey(L"Exit");
	CObjMgr::Get_Instance()->Add_Object(OBJ_MyButton, pButton);

}

void CMyMenu::Update(void)
{
	CObjMgr::Get_Instance()->Update();
}

void CMyMenu::Late_Update(void)
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CMyMenu::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"stardewPanorama");  //게임 시작시 버튼 뒤의 화면.
	BitBlt(hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);
}

void CMyMenu::Release(void)
{
	CObjMgr::Get_Instance()->Delete_ID(OBJ_MyButton);// 신이 바뀔때 그 신의 객체 모두 삭제.(여기서는 버튼)
}
