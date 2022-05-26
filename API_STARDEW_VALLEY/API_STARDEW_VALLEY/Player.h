#pragma once
#include "Obj.h"
#include "ScrollMgr.h"
#include "BmpMgr.h"
#include "KeyMgr.h"
#include "Land.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "SceneMgr.h"
#include "CropFactory.h"
#include "Mouse.h"
#include "Stone.h"
#include "Mines.h"
#include "SoundMgr.h"

class CPlayer :
	public CObj
{
public:
	CPlayer();
	CPlayer(const POINT & _Pos);
	virtual ~CPlayer();

public:
	const POINT& Get_PlayerPos(void) { return m_Pos; }
	const CObj* Get_Target(void) { return this; }
	const DirID& Get_Direction(void) { return m_Dir; }
	const int& Get_Hp(void) { return m_tInfo.m_iHp; }
	void Set_Hp(const int& _iHp) { m_tInfo.m_iHp = _iHp; }
	void Set_PlayerPos(const POINT& _p) { m_Pos = _p; }//���� �ٲ� �÷��̾��� ��ǥ�� �Ѱ���.
	void Change_PlayerPos(void) 
	{ 
		m_tInfo.fX = (float)m_Pos.x;
		m_tInfo.fY = (float)m_Pos.y;
	}

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Key_Input(void);
	void OffSet(void);
	void Motion_Change(void);

public:
	void Set_UseToolBool(bool _b) { m_bUseTool = _b; }
	void Set_MonsterBool(bool _b) { m_bMonster = _b; }
	const bool& Get_Watered(void) { return m_bWatered; }
	void Set_Money(const int& _Money) { m_iMoney = _Money; }
	const int& Get_Money(void) { return m_iMoney; }
	void Use_Money(const int& _Money) { m_iMoney -= _Money; }
	void Earn_money(const int& _Money) { m_iMoney += _Money; }

public:
	enum STATE { IDLE, WALK_UP, WALK_DOWN, WALK_LEFT, WALK_RIGHT, TOOL_LEFT, TOOL_RIGHT, END };

private:
	float m_fSpeed;
	POINT m_Pos;

	STATE m_ePreState;
	STATE m_eCurState;
	DirID m_Dir;

	SCENEID m_curScene;

	bool m_bFruit;//���ο� ���� �ɾ���?
	bool m_bMonster;//���͸� ��ҳ�?
	bool m_bTalkOver;//������ ��ȭ������?
	bool m_bWatered;//���� ���� �ᳪ?
	bool m_bUseTool;//���� ������ΰ�?

	int m_iMoney;//�����ݾ�.
};

