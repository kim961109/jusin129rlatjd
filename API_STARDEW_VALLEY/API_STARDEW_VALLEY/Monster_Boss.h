#pragma once
#include "Monster.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "ObjMgr.h"
#include "Player.h"

class CMonster_Boss :
	public CMonster
{
public:
	CMonster_Boss();
	virtual ~CMonster_Boss();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Using_Skill(void);
	void Move(void);
	void Shake(void);

public:
	const bool& Get_Awaken(void) { return bAwaken; }
	const bool& Get_Skill(void) { return bSkill; }
	const bool& Get_Move(void) { return bMove; }

	const void Set_Awaken(bool _b) { bAwaken = _b; }
	const void Set_Skill(bool _b) { bSkill = _b; }
	const void Set_Move(bool _b) { bMove = _b; }

	const void Set_FruitPos(float _fX, float _fY) 
	{
		m_fruitX = _fX;
		m_fruitY = _fY;
	}

private:
	bool bAwaken;
	bool bSkill;
	bool bMove;
	bool bShake;

	float m_fSpeed;
	int m_iJumpUp;
	int m_iJumpDown;

	float m_fruitX;
	float m_fruitY;
	float m_fAngle;
	float m_fSpeed2;

	int m_iPreJump;
	int m_iCurJump;
};

