#pragma once
#include "UI.h"
class CUI_Inven :
	public CUI
{
public:
	CUI_Inven();
	CUI_Inven(float _fX, float _fY);
	virtual ~CUI_Inven();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_InvenBool(void) { return m_bOn; }
	void Set_InvenBool(bool _b) { m_bOn = _b; }


private:
	bool m_bOn;// 인벤토리가 켜져 있냐 꺼져있냐.

public:
	const int& Get_GrassNum(void) { return m_iGrass; }
	const int& Get_StoneNum(void) { return m_iStone; }
	const int& Get_GoldNum(void) { return m_iGold; }
	const int& Get_IridiumNum(void) { return m_iIridium; }
	const int& Get_WoodNum(void) { return m_iWood; }
	const int& Get_FlowerNum(void) { return m_iFlower; }
	const int& Get_SlimeNum(void) { return m_iSlime; }
	const int& Get_BatNum(void) { return m_iBat; }

	void Set_GrassNum(void) { m_iGrass += 1; }
	void Set_StoneNum(void) { m_iStone += 1; }
	void Set_GoldNum(void) { m_iGold += 1; }
	void Set_IridiumNum(void) { m_iIridium += 1; }
	void Set_WoodNum(void) { m_iWood += 1; }
	void Set_FlowerNum(void) { m_iFlower += 1; }
	void Set_SlimeNum(void) { m_iSlime += 1; }
	void Set_BatNum(void) { m_iBat += 1; }

private:
	int m_iGrass;//아이템의 소지개수.
	int m_iStone;
	int m_iGold;
	int m_iIridium;
	int m_iWood;
	int m_iFlower;
	int m_iSlime;
	int m_iBat;
};

