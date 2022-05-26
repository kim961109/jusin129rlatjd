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
	void Check_Distance(void);//�÷��̾���� �Ÿ�����.
	void Moving_Birds(void);//��ϴ� ��Ģ.
	void Move_Change(void);//����¸� ����.
	void ChangePos(void);
	void ComeBack(void);//������ġ�� ����.
	void Set_CatState(const int& _State) { m_Cur = (STATEID)_State; }

private:
	CObj* m_pTarget;//�÷��̾��� ��ġ�� ����.
	enum STATEID { SLEEP, WALK, END };

	STATEID m_Pre;//���� ����
	STATEID m_Cur;//�Լ��� �޾ƿ� ����.
	float m_fSpeed;
	int m_iKind;//��� ������ ���ΰ�.
	int m_iDir;//��𼭺��� ���� ���ΰ�. 0==���ʺ��� ������  1==�����ʺ��� ����.

	float m_fFirstX;
	float m_fFirstY;
};

