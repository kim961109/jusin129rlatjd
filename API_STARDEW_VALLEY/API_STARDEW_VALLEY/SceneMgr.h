#pragma once
#include "Include.h"
#include "Scene.h"
#include "MyMenu.h"
#include "Stage.h"
#include "Cave.h"
#include "Cave2.h"
#include "Cave3.h"
#include "Farm.h"
#include "Gamble.h"
#include "Wall.h"
#include "MyEdit.h"
#include "Ending.h"

class CSceneMgr
{
public:
	CSceneMgr();
	~CSceneMgr();

public:
	void		Scene_Change(SCENEID eID);
	void		Update(void);
	void		Late_Update(void);
	void		Render(HDC hDC);
	void		Release(void);

public:
	static		CSceneMgr*		Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CSceneMgr;
		}

		return m_pInstance;
	}

	static	void	Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	SCENEID Get_SceneID(void) { return m_eCurScene; }

	const CScene* Get_Farm(void) { return m_pFarmSave; }
	void Set_Farm(CScene* _Scene) { m_pFarmSave = _Scene; }

private:
	static CSceneMgr*		m_pInstance;
	CScene*					m_pScene;
	CScene*                 m_pFarmSave;

	SCENEID					m_eCurScene;
	SCENEID					m_ePreScene;
};

