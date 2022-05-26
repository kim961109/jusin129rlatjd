#pragma once
#include "Include.h"
#include "UI.h"
#include "UI_Hp.h"
#include "UI_Gold.h"
#include "UI_Item.h"
#include "HP.h"
#include "UI_Icon.h"
#include "UI_Inven.h"
#include "UI_BagItem.h"
#include "UI_Talk.h"
#include "UI_TalkNPC.h"
#include "UI_Shop.h"
#include "UI_Imoji.h"
#include "UI_FarmTalk.h"
#include "UI_GambleTalk.h"
#include "UI_WallTalk.h"

template<typename T>
class CUIFactory
{
public:

	CUIFactory()
	{
	}

	~CUIFactory()
	{
	}

public:
	static CUI*& Create_UI(float _fX, float _fY)
	{
		CUI* pUI = new T(_fX, _fY);
		pUI->Initialize();

		return pUI;
	}

	static CUI*& Create_UIHP(CObj* _p)
	{
		CUI* pUI = new T(_p);
		pUI->Initialize();

		return pUI;
	}

	static CUI*& Create_UIICON(int _iX, int _iY, float _fX, float _fY)
	{
		CUI* pUI = new T(_iX, _iY, _fX, _fY);
		pUI->Initialize();

		return pUI;
	}

	static CUI*& Create_UIBAG(int _iA, float _fX, float _fY)
	{
		CUI* pUI = new T(_iA, _fX, _fY);
		pUI->Initialize();

		return pUI;
	}
};

