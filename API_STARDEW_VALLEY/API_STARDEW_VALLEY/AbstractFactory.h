#pragma once
#include "Include.h"
#include "Obj.h"
#include "Player.h"
#include "Mouse.h"
#include "Monster.h"
#include "Monster_Bat.h"
#include "Monster_Slime.h"
#include "Monster_Boss.h"
#include "ObjCollision.h"
#include "Wood.h"
#include "Grass.h"
#include "Stone.h"
#include "ShopButton.h"
#include "Imoji.h"
#include "Bullet.h"
#include "Ball.h"
#include "Arrow.h"
#include "Treasure.h"
#include "Key.h"
#include "Cat.h"
#include "Birds.h"
#include "Tool.h"
#include "TV.h"

template<typename T>
class CAbstractFactory
{
public:

	CAbstractFactory()
	{
	}

	~CAbstractFactory()
	{
	}

public:
	static CObj*& Create_Player(POINT p)
	{
		CObj* pObj = new T(p);
		static_cast<CPlayer*>(pObj)->Initialize();

		return pObj;
	}

	static CObj*& Create_Wall(float _fA,float _fB,float _fXsize,float _fYsize)
	{
		CObj* pObj = new T(_fA,_fB, _fXsize, _fYsize);
		pObj->Initialize();

		return pObj;
	}

	static CObj*& Create_Mouse()
	{
		CObj* pObj = new CMouse;
		(pObj)->Initialize();

		return pObj;
	}

	static CObj*	Create_Button(float _fX, float _fY)
	{
		CObj*	pObj = new T;

		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}

	static CObj*	Create_ShopButton(float _fX, float _fY)
	{
		CObj*	pObj = new T(_fX, _fY);

		pObj->Initialize();

		return pObj;
	}

	static CObj*& Create_Monster(CObj* _pPlayer)
	{
		CObj* pObj = new T;
		static_cast<CMonster*>(pObj)->Initialize();
		static_cast<CMonster*>(pObj)->m_pTarget = _pPlayer; // 생성시에 Monster_Bat라서 혹시 버그 생길 가능성 있음.

		return pObj;
	}

	static CObj*	Create_Tile(float _fX, float _fY)
	{
		CObj*	pObj = new T;

		pObj->Initialize();
		pObj->Set_Pos(_fX, _fY);

		return pObj;
	}

	static CObj*& Create_Source(const int& Num,float _fX,float _fY)// 도구로 캘수 있는 나무, 풀, 돌, 광석등.
	{
		CObj* pObj = new T(Num,_fX,_fY);
		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Land(float _fX, float _fY, int iA)
	{
		CObj*	pObj = new T(_fX, _fY, iA);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Imoji(int iA, float _fX, float _fY)
	{
		CObj*	pObj = new T(iA, _fX, _fY);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Bullet(float _fX, float _fY, float _TX, float _TY)
	{
		CObj*	pObj = new T(_fX, _fY, _TX, _TY);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_HugeCrop(int iA, float _fX, float _fY)
	{
		CObj*	pObj = new T(iA, _fX, _fY);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Arrow(float _fX, float _fY)
	{
		CObj*	pObj = new T(_fX, _fY);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Cat(float _fX, float _fY)
	{
		CObj*	pObj = new T(_fX, _fY);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Birds(int iA, int iB, float _fX, float _fY, CObj* _pObj)
	{
		CObj*	pObj = new T(iA, iB, _fX, _fY, _pObj);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_Tool(CObj* _pObj, int _Tool)
	{
		CObj*	pObj = new T(_pObj, _Tool);

		pObj->Initialize();

		return pObj;
	}

	static CObj*	Create_TV(float _fX, float _fY)
	{
		CObj*	pObj = new T(_fX, _fY);

		pObj->Initialize();

		return pObj;
	}
};

