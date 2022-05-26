#include "stdafx.h"
#include "UIMgr.h"

CUIMgr* CUIMgr::m_pInstance = nullptr;
CUIMgr::CUIMgr()
{
}


CUIMgr::~CUIMgr()
{
}

void CUIMgr::Add_UI(CUI * pUI)
{
	m_UIList.push_back(pUI);
}

void CUIMgr::Add_UI2(CUI * pUI)
{
	m_UIvec.push_back(pUI);
}

void CUIMgr::Add_UIInven(const TCHAR* p, CUI * pUI)
{
	m_UIInvenmap.emplace(p, pUI);
}

void CUIMgr::Add_UITalk(CUI * pUI)
{
	m_UITalkvec.push_back(pUI);
}

void CUIMgr::Add_UIFarmTalkvec(CUI * pUI)
{
	m_UIFarmTalkvec.push_back(pUI);
}

void CUIMgr::Add_UIGambleTalkvec(CUI * pUI)
{
	m_UIGambleTalkvec.push_back(pUI);
}

void CUIMgr::Add_UIWallTalkvec(CUI * pUI)
{
	m_UIWallTalkvec.push_back(pUI);
}

void CUIMgr::Add_UIImoji(CUI * pUI)
{
	m_UIImoji.push_back(pUI);
}

void CUIMgr::Update(void)
{
	for (auto& iter : m_UIList)
	{
		iter->Update();
	}
	for (auto& iter : m_UIvec)
	{
		iter->Update();
	}
	for (auto& iter : m_UIInvenmap)
	{
		iter.second->Update();
	}
	for (auto& iter : m_UITalkvec)
	{
		iter->Update();
	}
	for (auto& iter : m_UIImoji)
	{
		iter->Update();
	}
	for (auto& iter : m_UIFarmTalkvec)
	{
		iter->Update();
	}
	for (auto& iter : m_UIGambleTalkvec)
	{
		iter->Update();
	}
	for (auto& iter : m_UIWallTalkvec)
	{
		iter->Update();
	}
}

void CUIMgr::Render(HDC hDC)
{
	for (auto& iter : m_UIList)
	{
		iter->Render(hDC);
	}
	for (auto& iter : m_UIvec)
	{
		if (static_cast<CUI_Icon*>(iter)->Get_AxeBool() == true)
		{
			m_UIvec[0]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_HoeBool() == true)
		{
			m_UIvec[1]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_PickaxBool() == true)
		{
			m_UIvec[2]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_WaterBool() == true)
		{
			m_UIvec[3]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_WeaponBool() == true)
		{
			m_UIvec[4]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_FlowerBool() == true)
		{
			m_UIvec[5]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_PepperBool() == true)
		{
			m_UIvec[6]->Render(hDC);
		}
		else if (static_cast<CUI_Icon*>(iter)->Get_BallBool() == true)
		{
			m_UIvec[7]->Render(hDC);
		}
		
	}
	for (auto& iter : m_UIInvenmap)
	{
		if (L"Inventory" == iter.first)
		{
			iter.second->Render(hDC);
		}
		// 획득 아이콘들은 스태틱 캐스팅하여 특정위치를 주는 함수로 렌더링.
		else
		{

			iter.second->Render(hDC); // ----->  굳이 나눠야 함????????

		}
		
	}
	
	for (auto& iter : m_UITalkvec)
	{
		iter->Render(hDC);
	}

	for (auto& iter : m_UIImoji)
	{
		iter->Render(hDC);
	}

	for (auto& iter : m_UIFarmTalkvec)
	{
		iter->Render(hDC);
	}
	for (auto& iter : m_UIGambleTalkvec)
	{
		iter->Render(hDC);
	}
	for (auto& iter : m_UIWallTalkvec)
	{
		iter->Render(hDC);
	}
}