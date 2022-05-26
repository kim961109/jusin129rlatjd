#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"
#include "SoundMgr.h"

class CCat :
	public CObj
{
public:
	CCat();
	CCat(float _fX, float _fY);
	virtual ~CCat();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	void Moving_Cat(void);
	void Move_Change(void);
	void Set_CatState(const int& _State) { m_Cur = (STATEID)_State; }

private:
	enum STATEID{SLEEP, WALK, END};

	STATEID m_Pre;//이전 상태
	STATEID m_Cur;//함수로 받아올 상태.
	float m_fSpeed;
};

