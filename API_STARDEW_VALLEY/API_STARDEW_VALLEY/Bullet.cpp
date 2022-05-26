#include "stdafx.h"
#include "Bullet.h"


CBullet::CBullet()
{
}

CBullet::CBullet(float _fX, float _fY, float _TX, float _TY)
	:m_TargetX(_TX), m_TargetY(_TY)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CBullet::~CBullet()
{
	Release();
}

void CBullet::Initialize(void)
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Bullet/bullet1.bmp", L"bullet1");

	m_pFrameKey = L"bullet1";

	m_tInfo.fCX = 8;
	m_tInfo.fCY = 8;
	m_fSpeed = 3.f;

	float		fWidth = m_TargetX - m_tInfo.fX;
	float		fHeight = m_TargetY - m_tInfo.fY;

	float		fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

	fRadian = acosf(fWidth / fDiagonal);	// acos������ ���� �� �ִ� ������ ������ 0~180�� ���� ���� �ش��Ѵ�.

														/*if (m_pTarget->Get_Info().fY > m_tInfo.fY)
														fRadian = (2 * PI) - fRadian;*/

														// ���� ���� ��׸��� ġȯ
	m_fAngle = (fRadian * 180.f) / PI;

	if (m_TargetY > m_tInfo.fY)
		m_fAngle *= -1.f;
}

void CBullet::Update(void)
{
	// �Ѿ��� �����̴� �Լ�.
	Move_Bullet();
	Update_Rect();
}

void CBullet::Late_Update(void)
{
}

void CBullet::Render(HDC hDC)
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

void CBullet::Release(void)
{
}

void CBullet::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}

void CBullet::Move_Bullet(void)
{
	m_tInfo.fX += m_fSpeed * cosf((m_fAngle)* PI / 180.f);
	m_tInfo.fY -= m_fSpeed * sinf((m_fAngle)* PI / 180.f);
}
