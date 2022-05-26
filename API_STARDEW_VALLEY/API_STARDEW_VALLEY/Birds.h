#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"

class CBirds :
	public CObj
{
public:
	CBirds();
	CBirds(int _iNum, int _iDir, float _fX, float _fY, CObj* pObj);
	virtual ~CBirds();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Check_Distance(void);//플레이어와의 거리판정.
	void Moving_Birds(void);//운동하는 규칙.
	void Move_Change(void);//운동상태를 개변.
	void ChangePos(void);
	void ComeBack(void);//원래위치에 안착.
	void Set_CatState(const int& _State) { m_Cur = (STATEID)_State; }

private:
	CObj* m_pTarget;//플레이어의 위치를 받음.
	enum STATEID { SLEEP, WALK, END };

	STATEID m_Pre;//이전 상태
	STATEID m_Cur;//함수로 받아올 상태.
	float m_fSpeed;
	int m_iKind;//어느 종류의 새인가.
	int m_iDir;//어디서부터 나는 새인가. 0==왼쪽부터 오른쪽  1==오른쪽부터 왼쪽.

	float m_fFirstX;
	float m_fFirstY;
};

