#pragma once
typedef struct tagInfo
{
	int m_iHp;
	int m_iAttack;
	//�÷��̾ ������ �����°� ������ ����.
	//int m_iEnergy;

	float fX;
	float fY;

	float fCX;
	float fCY;

}INFO;

typedef struct tagFrame
{
	int		iFrameStart;		// ���ϴ� �������� ��������Ʈ �̹��� ���� ����
	int		iFrameEnd;			// ��������Ʈ�� ������ ������ ����
	int		iMotion;			// ��� �ε���

	DWORD	dwSpeed;			// ��������Ʈ�� ���ư��� �ӵ�
	DWORD	dwTime;				// ��������Ʈ ��ġ�� ����Ǵ� �ð� 

}FRAME;

typedef struct tagUIInfo
{
	float fX;
	float fY;

	float fCX;
	float fCY;

}UIINFO;

typedef struct tagIcon
{
	int iMoney;
	int iFlower;
	int iPepper;
	int iFlower_Seed;
	int iPepper_Seed;
}ICON;