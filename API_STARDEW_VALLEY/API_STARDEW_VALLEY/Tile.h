#pragma once
#include "Obj.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CTile :
	public CObj
{
public:
	CTile();
	virtual ~CTile();

public:
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

	virtual void Update_Rect(void) override;

public:
	const int& Get_DrawID(void) { return m_iDrawID; }
	const int& Get_Option(void) { return m_iOption; }
public:
	void		Set_DrawID(int _iDrawID) { m_iDrawID = _iDrawID; }
	void		Set_Option(int _iOption) { m_iOption = _iOption; }

private:
	int			m_iDrawID;
	int			m_iOption;
};

