#pragma once
typedef struct tagInfo
{
	int m_iHp;
	int m_iAttack;
	//플레이어만 에너지 가지는게 좋을것 같다.
	//int m_iEnergy;

	float fX;
	float fY;

	float fCX;
	float fCY;

}INFO;

typedef struct tagFrame
{
	int		iFrameStart;		// 원하는 지점부터 스프라이트 이미지 구동 시작
	int		iFrameEnd;			// 스프라이트가 끝나는 지점을 지정
	int		iMotion;			// 모션 인덱스

	DWORD	dwSpeed;			// 스프라이트가 돌아가는 속도
	DWORD	dwTime;				// 스프라이트 위치가 변경되는 시간 

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