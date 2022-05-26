#pragma once
#include "Scene.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"
#include "Mines.h"

class CCave :
	public CScene
{
public:
	CCave();
	virtual ~CCave();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	POINT m_ChangePoint;
};

