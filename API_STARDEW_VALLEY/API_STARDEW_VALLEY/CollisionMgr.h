#pragma once
#include "Obj.h"
#include "Crop_Flower.h"
#include "UIMgr.h"
#include "UI_Inven.h"
#include "Cat.h"

class CCollisionMgr
{
public:
	CCollisionMgr();
	~CCollisionMgr();

public:
	static void     Collision_Boss(list<CObj*>& _Dest, list<CObj*>& _Sour);
	static void     Collision_Boss2(list<CObj*>& _Dest, list<CObj*>& _Sour);
	static void     Collision_Bullet(SCENEID m_curScene, list<CObj*>& _Dest, list<CObj*>& _Sour);
	static void     Collision_Bullet2(list<CObj*>& _Dest, list<CObj*>& _Sour);
	static void     Collision_Ball(list<CObj*>& _Dest, list<CObj*>& _Sour, list<CObj*>& _Player);
	static void     Collision_Crops(list<CObj*>& _Dest, list<CObj*>& _Sour);
	static bool		Check_Sphere(CObj* pDest, CObj* pSour);
	static bool		Check_Rect(CObj* pDest, CObj* pSour, float *pX, float* pY);
	static void		Collision_Rect(list<CObj*> _Dest, list<CObj*> _Sour);
	static void		Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour);
	static void		Collision_Sphere(list<CObj*> _Dest, list<CObj*> _Sour);
	static void		Collision_Arrow(list<CObj*> _Dest, list<CObj*> _Sour);
	static void     Collision_Box(list<CObj*>& _Dest, list<CObj*>& _Sour);
	static void     Collision_Key(list<CObj*>& _Dest, list<CObj*>& _Sour);
	static void     Collision_Cat(list<CObj*>& _Dest, list<CObj*>& _Sour);//고양이와 벽 충돌
	static void     Collision_Cat2(list<CObj*>& _Dest, list<CObj*>& _Sour);//고양이와 플레이어 충돌.
};

