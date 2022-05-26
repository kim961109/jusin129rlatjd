#include "stdafx.h"
#include "Ending.h"


CEnding::CEnding()
{
	hGroundMemDC = nullptr;
	iNum = 0;
}


CEnding::~CEnding()
{
	Release();
}

void CEnding::Initialize(void)
{
	CScrollMgr::Get_Instance()->Make_ScrollX(0.f);
	CScrollMgr::Get_Instance()->Make_ScrollY(0.f);

	//CObjMgr::Get_Instance()->Delete_ID(OBJ_Player);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ending/Ending1.bmp", L"Ending1");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ending/Ending2.bmp", L"Ending2");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ending/Ending3.bmp", L"Ending3");
}

void CEnding::Update(void)
{
	key_Input();
}

void CEnding::Late_Update(void)
{
}

void CEnding::Render(HDC hDC)
{
	if (iNum == 0)
	{
		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ending1");
	}
	else if (iNum == 1)
	{
		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ending2");
	}
	else if (iNum == 2)
	{
		hGroundMemDC = CBmpMgr::Get_Instance()->Find_Image(L"Ending3");
	}
	BitBlt(hDC, 0, 0, WINCX, WINCY, hGroundMemDC, 0, 0, SRCCOPY);
}

void CEnding::Release(void)
{
}

void CEnding::key_Input(void)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_SPACE))
	{
		if (2 >= iNum)
		{
			iNum += 1;
		}
	}
}
