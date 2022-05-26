#include "stdafx.h"
#include "MainGame.h"
#include "ObjMgr.h"

int g_iDay = 0;
float	g_fSound = 1.f;
int g_iMoney = 0.f;

CMainGame::CMainGame()
	:m_dwTime(GetTickCount()), m_dwWorldTime(GetTickCount()), m_iHour(8), m_iMinute(0) //아침 시간 8시부터 하루 시작으로 침.
{
}


CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize(void)
{
	m_hDC = GetDC(g_hWnd);

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/stardewPanorama.bmp", L"stardewPanorama"); //Back 버퍼에 해당하는 그림을 추가를 해야한다.

	CSoundMgr::Get_Instance()->Initialize();

	CSceneMgr::Get_Instance()->Scene_Change(SC_Menu);
	//CSceneMgr::Get_Instance()->Scene_Change(SC_Shop);

#ifdef _DEBUG

	if (::AllocConsole() == TRUE)
	{
		FILE* nfp[3];
		freopen_s(nfp + 0, "CONOUT$", "rb", stdin);
		freopen_s(nfp + 1, "CONOUT$", "wb", stdout);
		freopen_s(nfp + 2, "CONOUT$", "wb", stderr);
		std::ios::sync_with_stdio();
	}

#endif // _DEBUG
}

void CMainGame::Update(void)
{
	CSceneMgr::Get_Instance()->Update();
	CScrollMgr::Get_Instance()->Scroll_Lock();// 스크롤 락.
	Cheat_Time();
	CSoundMgr::Get_Instance()->PlaySound(L"BGM.wav", SOUND_BGM, g_fSound);
}

void CMainGame::Late_Update(void)
{
	CSceneMgr::Get_Instance()->Late_Update();
}

void CMainGame::Render(void)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(L"stardewPanorama"); // Back 버퍼에 그릴 그림

	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

	CSceneMgr::Get_Instance()->Render(hMemDC); // 백 버퍼에다가 그림을 그린다


	                                                                                 //   여기서 타이머 시간 계산.
	if (!CObjMgr::Get_Instance()->Get_List(OBJ_Player).empty())
	{
		Count_Time(m_hDC);
	}
	
#ifdef _DEBUG
	++m_iFPS;

	if (m_dwTime + 1000 < GetTickCount())
	{
		swprintf_s(m_szFPS, L"FPS : %d", m_iFPS);
		SetWindowText(g_hWnd, m_szFPS);

		m_iFPS = 0;
		m_dwTime = GetTickCount();
	}

#endif // _DEBUG
}

void CMainGame::Release(void)
{
#ifdef _DEBUG

	FreeConsole();

#endif // _DEBUG

	CSoundMgr::Get_Instance()->Destroy_Instance();
	CObjMgr::Get_Instance()->Destroy_Instance();
	CSceneMgr::Get_Instance()->Destroy_Instance();
	CBmpMgr::Get_Instance()->Destroy_Instance();
	CScrollMgr::Get_Instance()->Destroy_Instance();
	CKeyMgr::Get_Instance()->Destroy_Instance();

	ReleaseDC(g_hWnd, m_hDC);
}

void CMainGame::Count_Time(HDC hDC)
{
	if (m_dwWorldTime + 50 < GetTickCount())
	{
		m_iMinute += 1;
		m_dwWorldTime = GetTickCount();
	}
	if (m_iMinute == 60)
	{
		m_iHour += 1;
		m_iMinute = 0;
	}
	if (m_iHour == 24)
	{
		m_iHour = 0;
		m_iMinute = 0;
		g_iDay += 1;
	}

	TCHAR Hour[32] = L"";
	TCHAR MINUTE[32] = L"";
	TCHAR DAY[32] = L"";
	TCHAR Money[32] = L"";
	swprintf_s(Hour, L"%02d", m_iHour);
	swprintf_s(MINUTE, L"%02d", m_iMinute);
	swprintf_s(DAY, L"%02d", g_iDay);
	swprintf_s(Money, L"%d", g_iMoney);

	SetBkMode(hDC, TRANSPARENT); // 폰트 출력시 배경을 지워주는 함수.뒤의 값이 1이면 투명, 2이면 하얀색.(TextOut 바로 앞줄에 씀.)
								 //TextOut(hDC, (int)0.5 * WINCX, (int)0.5*WINCY, (LPCWSTR)Hour, lstrlen((LPCWSTR)Hour));
	TextOut(hDC, (int)(0.5 * WINCX + 400), (int)(0.5 * WINCY - 285), Hour, lstrlen(Hour));
	TextOut(hDC, (int)(0.5 * WINCX + 420), (int)(0.5 * WINCY - 285), TEXT("  :  "), strlen("  :  "));
	TextOut(hDC, (int)(0.5 * WINCX + 440), (int)(0.5 * WINCY - 285), MINUTE, lstrlen(MINUTE));
	TextOut(hDC, (int)(0.5 * WINCX + 400), (int)(0.5 * WINCY - 355), TEXT(" DAY :  "), strlen(" DAY :  "));
	TextOut(hDC, (int)(0.5 * WINCX + 440), (int)(0.5 * WINCY - 355), DAY, lstrlen(DAY));
	TextOut(hDC, 900, 150, Money, lstrlen(Money));

}

void CMainGame::Cheat_Time(void)
{
	if (CKeyMgr::Get_Instance()->Key_Down(VK_F1))
	{
		g_iDay += 1;
		m_iHour = 0;
		m_iMinute = 0;
	}
}
