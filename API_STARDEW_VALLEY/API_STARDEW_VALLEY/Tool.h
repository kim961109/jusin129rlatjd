#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "Player.h"

class CTool :
	public CObj
{
public:
	CTool();
	CTool(CObj* pObj, int _Tool);
	//CTool(float _fX, float _fY, int _Tool);
	virtual ~CTool();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Update_Pos(void);
	void Render_Cancel(void);
	void Use_Tool(void);

public:
	void Set_Render(bool _b) { m_bRender = _b; }

private:
	enum TOOLID{AXE, PICKAX, HOE, END};

	TOOLID TOOLTYPE;// 어떤 종류의 도구인지 판단.
	CObj* m_pTarget;

	bool m_bRender;
};

