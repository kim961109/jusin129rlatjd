#pragma once
#include "Scene.h"
#include "ObjMgr.h"
#include "AbstractFactory.h"
#include "BmpMgr.h"
#include "CollisionMgr.h"

class CGamble :
	public CScene
{
public:
	CGamble();
	virtual ~CGamble();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	void key_Input(void);
	void Warning(void);
	void Transport(void);

public:
	const bool& Get_GambleBool(void) { return m_bGamble; }

private:
	POINT m_ChangePoint;

	int m_iWin;// �¸� ���� ���.
	int m_iLose;// ���� ���� ���.
	bool m_bGamble; // Ȧ¦ ������ �Ҽ� �ִ���.
};

