#pragma once
#include "UI.h"
#include "UI_Icon.h"

class CUIMgr
{
public:
	CUIMgr();
	~CUIMgr();

public:
	void Add_UI(CUI* pUI);
	void Add_UI2(CUI* pUI);//벡터 저장.
	void Add_UIInven(const TCHAR*, CUI* pUI);
	void Add_UITalk(CUI* pUI);
	void Add_UIFarmTalkvec(CUI* pUI);
	void Add_UIGambleTalkvec(CUI* pUI);
	void Add_UIWallTalkvec(CUI* pUI);
	void Add_UIImoji(CUI* pUI);
	void Update(void);
	void Render(HDC hDC);

	vector<CUI*>& Get_UIvec(void) { return m_UIvec; }
	list<CUI*>& Get_UIList(void) { return m_UIList; }
	map<const TCHAR*,CUI*>& Get_UIInvenmap(void) { return m_UIInvenmap; }
	vector<CUI*>& Get_UITalkvec(void) { return m_UITalkvec; }
	vector<CUI*>& Get_UIImoji(void) { return m_UIImoji; }
	vector<CUI*>& Get_UIFarmTalkvec(void) { return m_UIFarmTalkvec; }
	vector<CUI*>& Get_UIGambleTalkvec(void) { return m_UIGambleTalkvec; }
	vector<CUI*>& Get_UIWallTalkvec(void) { return m_UIWallTalkvec; }

private:
	std::list<CUI*> m_UIList;
	std::vector<CUI*> m_UIvec;//아이템 슬롯의 아이콘 표시.
	std::map<const TCHAR*, CUI*>m_UIInvenmap;//인벤토리 + 가방내의 아이콘들.
	std::vector<CUI*> m_UITalkvec;//대화 내용을 저장.
	std::vector<CUI*> m_UIImoji;
	std::vector<CUI*> m_UIFarmTalkvec;//Farm씬에서 NPC의 프사[0] + 대화 내용[1]
	std::vector<CUI*> m_UIGambleTalkvec;//Gamble씬에서 NPC의 프사[0] + 대화 내용[1]
	std::vector<CUI*> m_UIWallTalkvec;//Wall씬에서 대화내용[0]

public:
	static CUIMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CUIMgr;
		}
		return m_pInstance;
	}
	static void Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CUIMgr* m_pInstance;
};

