#include "stdafx.h"
#include "UI_BagItem.h"


CUI_BagItem::CUI_BagItem()
{
}

CUI_BagItem::CUI_BagItem(int _Num, float _fX, float _fY)
	:m_iNum(_Num),m_iBat(0),m_iFlower(0),m_iGold(0),m_iGrass(0),m_iIridium(0),m_iSlime(0),m_iStone(0),m_iWood(0)
{
	m_tInfo.fX = _fX;
	m_tInfo.fY = _fY;
}


CUI_BagItem::~CUI_BagItem()
{
	Release();
}

void CUI_BagItem::Initialize(void)
{
	m_tInfo.fCX = 16.f;
	m_tInfo.fCY = 16.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/UI/icon.bmp", L"Icon");

	m_pFrameKey = L"Icon";
}

void CUI_BagItem::Update(void)
{
	Update_Rect();
}

void CUI_BagItem::Late_Update(void)
{
}

void CUI_BagItem::Render(HDC hDC)
{
	//Get_InvenBool
	for (auto& iter : CUIMgr::Get_Instance()->Get_UIInvenmap())
	{
		if (L"Inventory" == iter.first)
		{
			if ((static_cast<CUI_Inven*>(iter.second)->Get_InvenBool()) == true)
			{
				HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Image(m_pFrameKey);

				GdiTransparentBlt(hDC, 			    // ���� ����, ���������� �׸��� �׸� DC
					int(m_tRect.left),	            // 2,3 ���� :  ������� ��ġ X, Y
					int(m_tRect.top),
					int(m_tInfo.fCX),				// 4,5 ���� : ������� ����, ���� ����
					int(m_tInfo.fCY),
					hMemDC,							// ��Ʈ���� ������ �ִ� DC
					int(m_tInfo.fCX * m_iNum),			// ��Ʈ�� ��� ���� ��ǥ, X,Y
					0,
					(int)m_tInfo.fCX,				// ������ ��Ʈ���� ����, ���� ����
					(int)m_tInfo.fCY,
					RGB(255, 255, 255));			// �����ϰ��� �ϴ� ����
			}
		}
	}
}

void CUI_BagItem::Release(void)
{
}
