#pragma once
#include "Include.h"
#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	void Add_Object(OBJID eID, CObj* pObj);
	void Add_Tool(CObj* pObj);
	void Render(HDC hDC);
	void RenderEx(HDC hDC, OBJID eID, OBJID eID2);
	void RenderEx2(HDC hDC, OBJID eID, OBJID eID2, OBJID eID3);
	void Update(void);
	void Late_Update(void);

	void Delete_ID(OBJID eID);
	list<CObj*>& Get_List(OBJID eID) { return m_ObjList[eID]; } // ���ﶧ ���۷����� ������ ���纻�� ����� ������ ������ �������� ����.
	vector<CObj*>& Get_Toolvec(void) { return m_Toolvec; }

private:
	std::list<CObj*> m_ObjList[OBJ_End];
	std::vector<CObj*> m_Toolvec;

public:
	static CObjMgr* Get_Instance(void)
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgr;
		}
		return m_pInstance;
	}
	static void Destroy_Instance(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CObjMgr* m_pInstance;
};

