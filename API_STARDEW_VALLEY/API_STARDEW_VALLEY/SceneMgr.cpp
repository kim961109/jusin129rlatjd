#include "stdafx.h"
#include "SceneMgr.h"

CSceneMgr* CSceneMgr::m_pInstance = nullptr;
CSceneMgr::CSceneMgr()
	: m_pScene(nullptr), m_eCurScene(SC_End), m_ePreScene(SC_End)
{
}


CSceneMgr::~CSceneMgr()
{
}

void CSceneMgr::Scene_Change(SCENEID eID)    // 추후 SceneExchange함수 만들어 기존 씬:farm만 저장 시킴.멤버변수로.
{
	m_eCurScene = eID;

	if (m_ePreScene != m_eCurScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eCurScene)
		{
		case SC_Menu:
			m_pScene = new CMyMenu;
			break;

		case SC_Stage:
			m_pScene = new CStage;
			break;

		case SC_Farm:
			if (m_pScene == nullptr)
			{
				m_pScene = new CFarm;
			}
			else
			{
				m_pScene = m_pFarmSave;
			}
			break;

		case SC_Cave1:
			m_pScene = new CCave;
			break;

		case SC_Cave2:
			m_pScene = new CCave2;
			break;

		case SC_Cave3:
			m_pScene = new CCave3;
			break;

		case SC_Shop:
			m_pScene = new CShop;
			break;

		case SC_MinigameGamble:
			m_pScene = new CGamble;
			break;

		case SC_MinigameWall:
			m_pScene = new CWall;
			break;

		case SC_MyEdit:
			m_pScene = new CMyEdit;
			break;

		case SC_Ending:
			m_pScene = new CEnding;
			break;

		}

		m_pScene->Initialize();
		m_ePreScene = m_eCurScene;
	}

}

void CSceneMgr::Update(void)
{
	m_pScene->Update();
}

void CSceneMgr::Late_Update(void)
{
	m_pScene->Late_Update();
}

void CSceneMgr::Render(HDC hDC)
{
	m_pScene->Render(hDC);
}

void CSceneMgr::Release(void)
{
	Safe_Delete(m_pScene);
}