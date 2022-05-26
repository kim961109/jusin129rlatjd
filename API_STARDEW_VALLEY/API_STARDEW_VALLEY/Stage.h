#pragma once
#include "Scene.h"
#include "BmpMgr.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "CollisionMgr.h"
#include "Player.h"
#include "SceneMgr.h"
#include "UIMgr.h"
#include "UIFactory.h"

class CStage :
	public CScene
{
public:
	CStage();
	virtual ~CStage();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	POINT m_ChangePoint;
};

