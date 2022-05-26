#pragma once
#include "Include.h"

class CScrollMgr
{
private:
	CScrollMgr();
	~CScrollMgr();

public:
	float Get_ScrollX(void) { return m_fScrollX; }
	float Get_ScrollY(void) { return m_fScrollY; }

	void Set_ScrollX(float _fX) { m_fScrollX += _fX; }
	void Set_ScrollY(float _fY) { m_fScrollY += _fY; }

	void Make_ScrollX(float _fX) { m_fScrollX = _fX; }//............................Make이전에 왜 Get_Scroll이 플레이어에서 작용해서 Make가 잘먹지 않음.
	void Make_ScrollY(float _fY) { m_fScrollY = _fY; }

	void		Scroll_Lock(void);

	//  여기에 씬이 바뀔때 m_fScrollX를 설정시켜주는 함수를 추가...................**************

public:
	static CScrollMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CScrollMgr;
		}

		return m_pInstance;
	}
	static void Destroy_Instance(void)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

private:
	static CScrollMgr* m_pInstance;
	float m_fScrollX = 0.f;
	float m_fScrollY = 0.f;
};

