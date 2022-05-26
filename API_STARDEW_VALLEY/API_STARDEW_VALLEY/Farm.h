#pragma once
#include "Scene.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "TileMgr.h"
#include "CollisionMgr.h"
#include "UIMgr.h"
#include "CropFactory.h"
#include "Crops.h"
#include "Shop.h"

class CFarm :
	public CScene
{
public:
	CFarm();
	virtual ~CFarm();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	POINT m_ChangePoint;
};

