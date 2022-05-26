#pragma once
#include "UI.h"
#include "KeyMgr.h"
#include "Player.h"

class CUI_Icon : // 화면에 나오는 도구 씨앗 등등 아이콘.
	public CUI
{
public:
	CUI_Icon();
	CUI_Icon(int _iX, int _iY, float _fX, float _fY);
	virtual ~CUI_Icon();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	const bool& Get_AxeBool(void) { return bAxe; }
	const bool& Get_HoeBool(void) { return bHoe; }
	const bool& Get_PickaxBool(void) { return bPickax; }
	const bool& Get_WaterBool(void) { return bWater; }
	const bool& Get_FlowerBool(void) { return bFlower; }
	const bool& Get_PepperBool(void) { return bPepper; }
	const bool& Get_WeaponBool(void) { return bWeapon; }
	const bool& Get_BallBool(void) { return bBall; }

	const void Set_AxeBool(bool _b) { bAxe = _b; }
	const void Set_HoeBool(bool _b) { bHoe = _b; }
	const void Set_PickaxBool(bool _b) { bPickax = _b; }
	const void Set_WaterBool(bool _b) { bWater = _b; }
	const void Set_FlowerBool(bool _b) { bFlower = _b; }
	const void Set_PepperBool(bool _b) { bPepper = _b; }
	const void Set_WeaponBool(bool _b) { bWeapon = _b; }
	const void Set_BallBool(bool _b) { bBall = _b; }

	void Set_False(void)
	{
		bAxe = false;
		bHoe = false;
		bPickax = false;
		bWater = false;
		bFlower = false;
		bPepper = false;
		bWeapon = false;
		bBall = false;
	}

private:
	int iXNum;
	int iYNum;

	bool bAxe;//도끼---1번............시실상 순서 뒤바뀜. 
	bool bHoe;//호미---2번
	bool bPickax;//곡괭이---3번
	bool bWater;
	bool bFlower;
	bool bPepper;
	bool bWeapon;
	bool bBall;
};

