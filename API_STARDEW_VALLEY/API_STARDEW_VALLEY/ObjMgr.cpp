#include "stdafx.h"
#include "ObjMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;
CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
}

void CObjMgr::Add_Object(OBJID eID, CObj * pObj)
{
	if ((eID >= OBJ_End) || (pObj == nullptr))
	{
		return;
	}
	m_ObjList[eID].push_back(pObj);
}

void CObjMgr::Add_Tool(CObj * pObj)
{
	m_Toolvec.push_back(pObj);
}

void CObjMgr::Render(HDC hDC)
{
	for (int i = 0; i < OBJ_End; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hDC);
		}
	}
	for (auto& iter : m_Toolvec)
	{
		iter->Render(hDC);
	}
}

void CObjMgr::RenderEx(HDC hDC, OBJID eID, OBJID eID2)
{
	for (int i = 0; i < OBJ_End; ++i)
	{
		if ((i == eID)||(i == eID2))
		{
			continue;
		}
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hDC);
		}
	}
}

void CObjMgr::RenderEx2(HDC hDC, OBJID eID, OBJID eID2, OBJID eID3)
{
	for (int i = 0; i < OBJ_End; ++i)
	{
		if ((i == eID3)||(i == eID) || (i == eID2))
		{
			continue;
		}
		for (auto& iter : m_ObjList[i])
		{
			iter->Render(hDC);
		}
	}
}

void CObjMgr::Update(void)
{
	for (int i = 0; i < OBJ_End; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Update();
		}
	}
	for (auto& iter : m_Toolvec)
	{
		iter->Update();
	}
}

void CObjMgr::Late_Update(void)
{
	for (int i = 0; i < OBJ_End; ++i)
	{
		for (auto& iter : m_ObjList[i])
		{
			iter->Late_Update();

			if (m_ObjList[i].empty()) // 신이 바뀔때 오브젝트를 전부 삭제하여 Late_Update에서 런타임에러가 나는걸 방지.
			{
				return;
			}
		}
	}
	for (auto& iter : m_Toolvec)
	{
		iter->Late_Update();
	}
}

void CObjMgr::Delete_ID(OBJID eID)
{
	for (auto& iter : m_ObjList[eID])
		Safe_Delete(iter);

	m_ObjList[eID].clear();
}
