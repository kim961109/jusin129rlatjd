#include "stdafx.h"
#include "TileMgr.h"

CTileMgr*	CTileMgr::m_pInstance = nullptr;
CTileMgr::CTileMgr()
{
}


CTileMgr::~CTileMgr()
{
	Release();
}

void CTileMgr::Initialize()
{
	/*for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			float		fX =  (TILECX >> 1) + float(TILECX * j);
			float		fY = (TILECY >> 1) + float(TILECY * i);

			CObj*	pTile = CAbstractFactory<CTile>::Create_Tile(fX, fY);
			m_vecTile.push_back(pTile);
		}
	}*/
}

void CTileMgr::Update()
{
	for (auto& iter : m_vecTile)
		iter->Update();
}

void CTileMgr::Late_Update()
{
	for (auto& iter : m_vecTile)
		iter->Late_Update();
}

void CTileMgr::Render(HDC hDC)
{
	for (auto& iter : m_vecTile)
		iter->Render(hDC);
}

void CTileMgr::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), CDeleteObj());
	m_vecTile.clear();
}

void CTileMgr::Save_Tile(void)
{
	HANDLE		hFile = CreateFile(L"../Data/MyTile.dat", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	int		iDrawID = 0, iOption = 0;
	DWORD	dwByte = 0;

	for (auto& iter : m_vecTile)
	{
		iDrawID = dynamic_cast<CTile*>(iter)->Get_DrawID();
		iOption = dynamic_cast<CTile*>(iter)->Get_Option();

		WriteFile(hFile, &iter->Get_Info(), sizeof(INFO), &dwByte, NULL);
		WriteFile(hFile, &iDrawID, sizeof(int), &dwByte, NULL);
		WriteFile(hFile, &iOption, sizeof(int), &dwByte, NULL);
	}

	CloseHandle(hFile);
}

void CTileMgr::Picking_Tile(POINT _pt, const int& _iDrawID, const int& _iOption)
{
	int		x = _pt.x / TILECX;
	int		y = _pt.y / TILECY;

	int	iIndex = y * TILEX + x;

	if (0 > iIndex || m_vecTile.size() <= (size_t)iIndex) // 마우스가 화면내부에 존재하지 않음.
		return;

	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_DrawID(_iDrawID);
	dynamic_cast<CTile*>(m_vecTile[iIndex])->Set_Option(_iOption);
}