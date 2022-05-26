#include "stdafx.h"
#include "CollisionMgr.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

                                   // 보스               // 총알
void CCollisionMgr::Collision_Boss(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	auto& Dest = _Dest.front();

	for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
	{
		RECT		rc{};

		if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
		{
			if ((static_cast<CMonster_Boss*>(Dest)->Get_Awaken() == true) && (static_cast<CMonster_Boss*>(Dest)->Get_Skill() == false))
			{
				bool b = true;
				static_cast<CMonster_Boss*>(Dest)->Set_Skill(b);

				if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
				{
					//총알 삭제.
					Sour = _Sour.erase(Sour);
					if (Sour == _Sour.end())
					{
						return; // 마지막으로 들어간 원소를 지우면 end()를 가리키므로 ++ 하지 않게 리턴 시켜줌.
					}
				}

			}
		}
	}
	
}

                                         //과일                //몬스터
void CCollisionMgr::Collision_Boss2(list<CObj*>& _Dest, list<CObj*>& _Sour)//몬스터와 멜론의 충돌.
{
	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			RECT		rc{};

			if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				static_cast<CMonster_Boss*>(*Sour)->Set_Move(false);
				CSoundMgr::Get_Instance()->PlaySound(L"eat.wav", SOUND_Eat, g_fSound);
				Dest = _Dest.erase(Dest);
				if (Dest == _Dest.end())
				{
					return;
				}
			}
		}
	}

}

//몬스터.           // 총알
void CCollisionMgr::Collision_Bullet(SCENEID m_curScene, list<CObj*>& _Dest, list<CObj*>& _Sour)// 총알이 부딛치고 총알,몬스터 삭제.(보스는 이거 제외).
{
	RECT		rc{};

	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin();Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//총알 삭제.
				Dest = _Dest.erase(Dest);
				Sour = _Sour.erase(Sour);

				if (m_curScene == SC_Cave1)
				{
					for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
					{
						if (L"Inventory" == dest.first)
						{
							static_cast<CUI_Inven*>(dest.second)->Set_BatNum();
						}
					}
				}
				else if (m_curScene == SC_Cave2)
				{
					for (auto& dest : CUIMgr::Get_Instance()->Get_UIInvenmap())
					{
						if (L"Inventory" == dest.first)
						{
							static_cast<CUI_Inven*>(dest.second)->Set_SlimeNum();
						}
					}
				}

				if ((Sour == _Sour.end())||(Dest == _Dest.end()))
				{
					return; // 마지막으로 들어간 원소를 지우면 end()를 가리키므로 ++ 하지 않게 리턴 시켜줌.
				}
			}
		}
	}
}

                                            //움직이지 않는 물체.         // 총알..
void CCollisionMgr::Collision_Bullet2(list<CObj*>& _Dest, list<CObj*>& _Sour)// 총알이 부딛치고 총알만 삭제.
{
	RECT		rc{};

	for (auto& Dest : _Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//총알 삭제.
				Sour = _Sour.erase(Sour);
				if (Sour == _Sour.end())
				{
					return; // 마지막으로 들어간 원소를 지우면 end()를 가리키므로 ++ 하지 않게 리턴 시켜줌.
				}
			}
		}
	}
}

                                         //볼                  //몬스터.
void CCollisionMgr::Collision_Ball(list<CObj*>& _Dest, list<CObj*>& _Sour, list<CObj*>& _Player)// 볼이 부딛치고 몬스터 볼 둘다 삭제.
{
	RECT		rc{};

	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//총알 삭제.
				if (static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Get_Awaken() == true)
				{
					Sour = _Sour.erase(Sour);
					Dest = _Dest.erase(Dest);
					// 플레이어가 몬스터를 잡았을때 bool->true;
					static_cast<CPlayer*>(_Player.front())->Set_MonsterBool(true);
					if ((Sour == _Sour.end()) || (Dest == _Dest.end()))
					{
						return; // 마지막으로 들어간 원소를 지우면 end()를 가리키므로 ++ 하지 않게 리턴 시켜줌.
					}
				}
			}
		}
	}
}


// 플레이어               //작물.
void CCollisionMgr::Collision_Crops(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	RECT		rc{};

	for (auto& Dest : _Dest)
	{
		//for (auto& Sour : _Sour)
		for (auto& Sour = _Sour.begin();Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				// 식물이 밟히면 다 컸을때만 +1;
				if (6 == static_cast<CCrop_Flower*>(*Sour)->Get_FlowerNum())//  다 자란 식물만 충돌시 아이템 추가.
				{
					for (auto& iter : CUIMgr::Get_Instance()->Get_UIInvenmap())
					{
						if (L"Inventory" == iter.first)
						{
							static_cast<CUI_Inven*>(iter.second)->Set_FlowerNum();
						}
					}
					Sour = _Sour.erase(Sour);
					if (Sour == _Sour.end())
					{
						return; // 마지막으로 들어간 원소를 지우면 end()를 가리키므로 ++ 하지 않게 리턴 시켜줌.
					}
				}
				else if ((6 > static_cast<CCrop_Flower*>(*Sour)->Get_FlowerNum()) && (1 < static_cast<CCrop_Flower*>(*Sour)->Get_FlowerNum()))
				{
					Sour = _Sour.erase(Sour);
					if (Sour == _Sour.end())
					{
						return; // 마지막으로 들어간 원소를 지우면 end()를 가리키므로 ++ 하지 않게 리턴 시켜줌.
					}
				}
			
			}
		}
	}
}

                       // 몬스터                     // 플레이어.
void CCollisionMgr::Collision_Rect(list<CObj*> _Dest, list<CObj*> _Sour)// 플레이어의 피를 닳게 하는 용도.
{
	RECT		rc{};

	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			if (IntersectRect(&rc, &(Dest->Get_Rect()), &(Sour->Get_Rect())))
			{
				Sour->Set_Damage(Dest->Get_Damage());
			}
		}
	}
}
                        // 고정되어 있는 물체  // 움직이는 물체		
void CCollisionMgr::Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour)// 고정된 물체가 움직이는 물체를 밀어내는 용도.
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect(Dest, Sour, &fX, &fY))
			{
				// 상하 충돌
				if (fX > fY)
				{
					// 상 충돌
					if (Dest->Get_Info().fY > Sour->Get_Info().fY)
						Sour->Set_PosY(-fY);

					else // 하 충돌
						Sour->Set_PosY(fY);
				}
				// 좌우 충돌
				else
				{
					// 좌 충돌
					if (Dest->Get_Info().fX > Sour->Get_Info().fX)
						Sour->Set_PosX(-fX);

					// 우 충돌
					else
						Sour->Set_PosX(fX);
				}

			}
		}
	}
}

bool CCollisionMgr::Check_Rect(CObj* pDest, CObj* pSour, float *pX, float* pY)
{
	float		fWidth = abs(pDest->Get_Info().fX - pSour->Get_Info().fX);
	float		fHeight = abs(pDest->Get_Info().fY - pSour->Get_Info().fY);

	float		fCX = (pDest->Get_Info().fCX + pSour->Get_Info().fCX) * 0.5f;
	float		fCY = (pDest->Get_Info().fCY + pSour->Get_Info().fCY) * 0.5f;

	if ((fCX > fWidth) && (fCY > fHeight))
	{
		*pX = fCX - fWidth;
		*pY = fCY - fHeight;

		return true;
	}

	return false;
}

bool CCollisionMgr::Check_Sphere(CObj* pDest, CObj* pSour)
{
	// abs : 절대값을 구해주는 함수
	float	fWidth = fabs(pDest->Get_Info().fX - pSour->Get_Info().fX);
	float	fHeight = fabs(pDest->Get_Info().fY - pSour->Get_Info().fY);

	// sqrt : 루트를 씌워주는 함수
	float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	float	fRadius = (pDest->Get_Info().fCX + pSour->Get_Info().fCX) * 0.5f;

	return fRadius > fDiagonal;
}

void CCollisionMgr::Collision_Sphere(list<CObj*> _Dest, list<CObj*> _Sour)
{

	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			if (Check_Sphere(Dest, Sour))
			{
				// HP 감소로 변경.
				//Dest->Set_Dead();
				//Sour->Set_Dead();
			}
		}
	}
}

                                      // 플레이어          //화살.
void CCollisionMgr::Collision_Arrow(list<CObj*> _Dest, list<CObj*> _Sour)
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end();++Sour)
		{
			RECT rc = {};

			if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//플레이어의 위치를 조정.
				Sour = _Sour.erase(Sour);
				Dest->Set_Pos(250.f, 680.f);
				if (Sour == _Sour.end())
				{
					return;
				}
			}
		}
	}
}

                                        // 상자           // 플레이어.
void CCollisionMgr::Collision_Box(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	{
		for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
		{
			for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
			{
				RECT		rc{};

				if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
				{
					static_cast<CPlayer*>(*Sour)->Set_Money(20000);
					//static_cast<CMonster_Boss*>(*Sour)->Set_Move(false);
					CSoundMgr::Get_Instance()->PlaySound(L"reward.wav", SOUND_MINIGAME_REWARD, g_fSound);
					Dest = _Dest.erase(Dest);
					if (Dest == _Dest.end())
					{
						return;
					}
				}
			}
		}
	}
}

                                               // 키             //플레이어.
void CCollisionMgr::Collision_Key(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	{
		for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
		{
			for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
			{
				RECT		rc{};

				if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
				{
					//static_cast<CPlayer*>(*Sour)->Set_Money(20000);
					//static_cast<CMonster_Boss*>(*Sour)->Set_Move(false);
					CSoundMgr::Get_Instance()->PlaySound(L"reward.wav", SOUND_MINIGAME_REWARD, g_fSound);
					Dest = _Dest.erase(Dest);
					if (Dest == _Dest.end())
					{
						return;
					}
				}
			}
		}
	}
}

                                           // 충돌체.           // 고양이.
void CCollisionMgr::Collision_Cat(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	for (auto& Dest = _Dest.begin();Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect((*Dest), (*Sour), &fX, &fY))
			{
				// 상하 충돌
				if (fX > fY)
				{
					// 상 충돌
					if ((*Dest)->Get_Info().fY > (*Sour)->Get_Info().fY)
					{
						(*Sour)->Set_PosY(-fY);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
					else // 하 충돌
					{
						(*Sour)->Set_PosY(fY);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
				}
				// 좌우 충돌
				else
				{
					// 좌 충돌
					if ((*Dest)->Get_Info().fX > (*Sour)->Get_Info().fX)
					{
						(*Sour)->Set_PosX(-fX);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
					// 우 충돌
					else
					{
						(*Sour)->Set_PosX(fX);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
				}

			}
		}
	}
}

                                     //고양이              // 플레이어
void CCollisionMgr::Collision_Cat2(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect((*Dest), (*Sour), &fX, &fY))
			{
				// 상하 충돌
				if (fX > fY)
				{
					// 상 충돌
					if ((*Dest)->Get_Info().fY > (*Sour)->Get_Info().fY)
						(*Sour)->Set_PosY(-fY);

					else // 하 충돌
						(*Sour)->Set_PosY(fY);

					static_cast<CCat*>(*Dest)->Set_CatState(1);
				}
				// 좌우 충돌
				else
				{
					// 좌 충돌
					if ((*Dest)->Get_Info().fX > (*Sour)->Get_Info().fX)
						(*Sour)->Set_PosX(-fX);

					// 우 충돌
					else
						(*Sour)->Set_PosX(fX);

					static_cast<CCat*>(*Dest)->Set_CatState(1);
				}

			}
		}
	}
}
