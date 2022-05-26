#pragma once
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "SceneMgr.h"
#include "ScrollMgr.h"
#include "KeyMgr.h"
#include "SoundMgr.h"

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	void Initialize(void);
	void Update(void);
	void Late_Update(void);
	void Render(void);
	void Release(void);

public:
	void Count_Time(HDC hDC);

public:
	void Cheat_Time(void);

private:
	HDC m_hDC;
	DWORD m_dwTime;
	TCHAR m_szFPS[64];
	int	 m_iFPS;

	DWORD m_dwWorldTime;
	int m_iHour;
	int m_iMinute;
};

