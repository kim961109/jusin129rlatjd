#include "stdafx.h"
#include "CollisionMgr.h"


CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}

                                   // ����               // �Ѿ�
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
					//�Ѿ� ����.
					Sour = _Sour.erase(Sour);
					if (Sour == _Sour.end())
					{
						return; // ���������� �� ���Ҹ� ����� end()�� ����Ű�Ƿ� ++ ���� �ʰ� ���� ������.
					}
				}

			}
		}
	}
	
}

                                         //����                //����
void CCollisionMgr::Collision_Boss2(list<CObj*>& _Dest, list<CObj*>& _Sour)//���Ϳ� ����� �浹.
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

//����.           // �Ѿ�
void CCollisionMgr::Collision_Bullet(SCENEID m_curScene, list<CObj*>& _Dest, list<CObj*>& _Sour)// �Ѿ��� �ε�ġ�� �Ѿ�,���� ����.(������ �̰� ����).
{
	RECT		rc{};

	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin();Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//�Ѿ� ����.
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
					return; // ���������� �� ���Ҹ� ����� end()�� ����Ű�Ƿ� ++ ���� �ʰ� ���� ������.
				}
			}
		}
	}
}

                                            //�������� �ʴ� ��ü.         // �Ѿ�..
void CCollisionMgr::Collision_Bullet2(list<CObj*>& _Dest, list<CObj*>& _Sour)// �Ѿ��� �ε�ġ�� �Ѿ˸� ����.
{
	RECT		rc{};

	for (auto& Dest : _Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//�Ѿ� ����.
				Sour = _Sour.erase(Sour);
				if (Sour == _Sour.end())
				{
					return; // ���������� �� ���Ҹ� ����� end()�� ����Ű�Ƿ� ++ ���� �ʰ� ���� ������.
				}
			}
		}
	}
}

                                         //��                  //����.
void CCollisionMgr::Collision_Ball(list<CObj*>& _Dest, list<CObj*>& _Sour, list<CObj*>& _Player)// ���� �ε�ġ�� ���� �� �Ѵ� ����.
{
	RECT		rc{};

	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			if (IntersectRect(&rc, &((*Dest)->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//�Ѿ� ����.
				if (static_cast<CMonster_Boss*>(CObjMgr::Get_Instance()->Get_List(OBJ_Monster).front())->Get_Awaken() == true)
				{
					Sour = _Sour.erase(Sour);
					Dest = _Dest.erase(Dest);
					// �÷��̾ ���͸� ������� bool->true;
					static_cast<CPlayer*>(_Player.front())->Set_MonsterBool(true);
					if ((Sour == _Sour.end()) || (Dest == _Dest.end()))
					{
						return; // ���������� �� ���Ҹ� ����� end()�� ����Ű�Ƿ� ++ ���� �ʰ� ���� ������.
					}
				}
			}
		}
	}
}


// �÷��̾�               //�۹�.
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
				// �Ĺ��� ������ �� �������� +1;
				if (6 == static_cast<CCrop_Flower*>(*Sour)->Get_FlowerNum())//  �� �ڶ� �Ĺ��� �浹�� ������ �߰�.
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
						return; // ���������� �� ���Ҹ� ����� end()�� ����Ű�Ƿ� ++ ���� �ʰ� ���� ������.
					}
				}
				else if ((6 > static_cast<CCrop_Flower*>(*Sour)->Get_FlowerNum()) && (1 < static_cast<CCrop_Flower*>(*Sour)->Get_FlowerNum()))
				{
					Sour = _Sour.erase(Sour);
					if (Sour == _Sour.end())
					{
						return; // ���������� �� ���Ҹ� ����� end()�� ����Ű�Ƿ� ++ ���� �ʰ� ���� ������.
					}
				}
			
			}
		}
	}
}

                       // ����                     // �÷��̾�.
void CCollisionMgr::Collision_Rect(list<CObj*> _Dest, list<CObj*> _Sour)// �÷��̾��� �Ǹ� ��� �ϴ� �뵵.
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
                        // �����Ǿ� �ִ� ��ü  // �����̴� ��ü		
void CCollisionMgr::Collision_RectEx(list<CObj*> _Dest, list<CObj*> _Sour)// ������ ��ü�� �����̴� ��ü�� �о�� �뵵.
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour : _Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect(Dest, Sour, &fX, &fY))
			{
				// ���� �浹
				if (fX > fY)
				{
					// �� �浹
					if (Dest->Get_Info().fY > Sour->Get_Info().fY)
						Sour->Set_PosY(-fY);

					else // �� �浹
						Sour->Set_PosY(fY);
				}
				// �¿� �浹
				else
				{
					// �� �浹
					if (Dest->Get_Info().fX > Sour->Get_Info().fX)
						Sour->Set_PosX(-fX);

					// �� �浹
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
	// abs : ���밪�� �����ִ� �Լ�
	float	fWidth = fabs(pDest->Get_Info().fX - pSour->Get_Info().fX);
	float	fHeight = fabs(pDest->Get_Info().fY - pSour->Get_Info().fY);

	// sqrt : ��Ʈ�� �����ִ� �Լ�
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
				// HP ���ҷ� ����.
				//Dest->Set_Dead();
				//Sour->Set_Dead();
			}
		}
	}
}

                                      // �÷��̾�          //ȭ��.
void CCollisionMgr::Collision_Arrow(list<CObj*> _Dest, list<CObj*> _Sour)
{
	for (auto& Dest : _Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end();++Sour)
		{
			RECT rc = {};

			if (IntersectRect(&rc, &(Dest->Get_Rect()), &((*Sour)->Get_Rect())))
			{
				//�÷��̾��� ��ġ�� ����.
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

                                        // ����           // �÷��̾�.
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

                                               // Ű             //�÷��̾�.
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

                                           // �浹ü.           // �����.
void CCollisionMgr::Collision_Cat(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	for (auto& Dest = _Dest.begin();Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect((*Dest), (*Sour), &fX, &fY))
			{
				// ���� �浹
				if (fX > fY)
				{
					// �� �浹
					if ((*Dest)->Get_Info().fY > (*Sour)->Get_Info().fY)
					{
						(*Sour)->Set_PosY(-fY);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
					else // �� �浹
					{
						(*Sour)->Set_PosY(fY);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
				}
				// �¿� �浹
				else
				{
					// �� �浹
					if ((*Dest)->Get_Info().fX > (*Sour)->Get_Info().fX)
					{
						(*Sour)->Set_PosX(-fX);
						static_cast<CCat*>(*Sour)->Set_CatState(0);
					}
					// �� �浹
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

                                     //�����              // �÷��̾�
void CCollisionMgr::Collision_Cat2(list<CObj*>& _Dest, list<CObj*>& _Sour)
{
	for (auto& Dest = _Dest.begin(); Dest != _Dest.end(); ++Dest)
	{
		for (auto& Sour = _Sour.begin(); Sour != _Sour.end(); ++Sour)
		{
			float	fX = 0.f, fY = 0.f;

			if (Check_Rect((*Dest), (*Sour), &fX, &fY))
			{
				// ���� �浹
				if (fX > fY)
				{
					// �� �浹
					if ((*Dest)->Get_Info().fY > (*Sour)->Get_Info().fY)
						(*Sour)->Set_PosY(-fY);

					else // �� �浹
						(*Sour)->Set_PosY(fY);

					static_cast<CCat*>(*Dest)->Set_CatState(1);
				}
				// �¿� �浹
				else
				{
					// �� �浹
					if ((*Dest)->Get_Info().fX > (*Sour)->Get_Info().fX)
						(*Sour)->Set_PosX(-fX);

					// �� �浹
					else
						(*Sour)->Set_PosX(fX);

					static_cast<CCat*>(*Dest)->Set_CatState(1);
				}

			}
		}
	}
}
