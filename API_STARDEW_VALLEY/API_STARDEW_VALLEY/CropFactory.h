#pragma once
#include "Obj.h"
#include "Crops.h"
#include "Crop_Flower.h"
#include "Crop_Pepper.h"

class CCropFactory
{
public:

	CCropFactory()
	{
	}

	~CCropFactory()
	{
	}

public:
	static CObj*& Create_Flower(float _fX, float _fY)
	{
		CObj* pObj = new CCrop_Flower(_fX, _fY);
		pObj->Initialize();

		return pObj;
	}
};

