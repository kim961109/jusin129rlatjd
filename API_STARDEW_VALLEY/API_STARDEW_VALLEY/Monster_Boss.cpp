#include "stdafx.h"
#include "Monster_Boss.h"


CMonster_Boss::CMonster_Boss()
{
}


CMonster_Boss::~CMonster_Boss()
{
	Release();
}

void CMonster_Boss::Initialize(void)
{
	m_tInfo.fX = 1050.f;
	m_tInfo.fY = 550.f;   // �ӽ� �׽�Ʈ�� ������ġ.

	m_tInfo.fCX = 89.f;
	m_tInfo.fCY = 77.f;

	m_fruitX = 0.f;
	m_fruitY = 0.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/boss.bmp", L"boss");

	m_pFrameKey = L"boss";

	bAwaken = false;
	bSkill = false;
	bMove = false;
	bShake = false;

	m_iJumpUp = 0;
	m_iJumpDown = 0;
	m_fSpeed = 25.f;
	m_fSpeed2 = 5.f;

	m_iPreJump = 0;
	m_iCurJump = 10; //����ũ ����.
}

void CMonster_Boss::Update(void)
{
	Using_Skill();
	Move();
	Shake();
	Update_Rect();
}

void CMonster_Boss::Late_Update(void)
{
}

void CMonster_Boss::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScrollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScrollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

	GdiTransparentBlt(hDC, 					// ���� ����, ���������� �׸��� �׸� DC
		int(m_tRect.left + iScrollX),	// 2,3 ���� :  ������� ��ġ X, Y
		int(m_tRect.top + iScrollY),
		int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
		int(m_tInfo.fCY),
		hMemDC,							// ��Ʈ���� ������ �ִ� DC
		0,								// ��Ʈ�� ��� ���� ��ǥ, X,Y
		0,
		(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
		(int)m_tInfo.fCY,
		RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
}

void CMonster_Boss::Release(void)
{
}

void CMonster_Boss::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CMonster_Boss::Using_Skill(void)
{
	if (bSkill == true)
	{
		if (5 > m_iJumpUp)
		{
			m_tInfo.fY -= m_fSpeed;
			m_iJumpUp += 1;
		}
		if ((5 > m_iJumpDown)&& (5 == m_iJumpUp))
		{
			m_tInfo.fY += m_fSpeed;
			m_iJumpDown += 1;
		}

		if ((m_iJumpUp == 5) && (m_iJumpDown == 5))
		{
			m_iJumpUp = 0;
			m_iJumpDown = 0;
			bSkill = false;
			bShake = true;
		}
	}
}

void CMonster_Boss::Move(void)
{
	if (bMove == true)
	{
		float		fWidth = m_fruitX - m_tInfo.fX;
		float		fHeight = m_fruitY - m_tInfo.fY;

		float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		float       fRadian = acosf(fWidth / fDiagonal);	// acos������ ���� �� �ִ� ������ ������ 0~180�� ���� ���� �ش��Ѵ�.

												/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
												fRadian = (2 * PI) - fRadian;*/

												// ���� ���� ��׸��� ġȯ
		m_fAngle = (fRadian * 180.f) / PI;

		if (m_fruitY > m_tInfo.fY)
			m_fAngle *= -1.f;

		m_tInfo.fX += m_fSpeed2 * cosf((m_fAngle)* PI / 180.f);
		m_tInfo.fY -= m_fSpeed2 * sinf((m_fAngle)* PI / 180.f);
	}
}

void CMonster_Boss::Shake(void)
{
	if (bShake)
	{
		CSoundMgr::Get_Instance()->PlaySound(L"thunder.wav", SOUND_EARTHQUAKE, g_fSound);
		if (m_iPreJump < m_iCurJump)
		{
			float m_fShake = float(pow((-1), m_iPreJump) * 2 * m_fSpeed);
			CScrollMgr::Get_Instance()->Set_ScrollX(m_fShake);
			m_iPreJump += 1;
		}
		else
		{
			bShake = false;
			m_iPreJump = 0;
			CObjMgr::Get_Instance()->Get_List(OBJ_Player).front()->Set_Damage(50);
		}

	}
}
