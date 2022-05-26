#include "stdafx.h"
#include "UI.h"


CUI::CUI()
{
	ZeroMemory(&m_tInfo, sizeof(UIINFO));
	ZeroMemory(&m_tRect, sizeof(RECT));
	ZeroMemory(&m_tIcon, sizeof(ICON));
}


CUI::~CUI()
{
}

void CUI::Update_Rect(void)
{
	m_tRect.left = LONG(m_tInfo.fX - 0.5f * m_tInfo.fCX);
	m_tRect.top = LONG(m_tInfo.fY - 0.5f * m_tInfo.fCY);
	m_tRect.right = LONG(m_tInfo.fX + 0.5f * m_tInfo.fCX);
	m_tRect.bottom = LONG(m_tInfo.fY + 0.5f * m_tInfo.fCY);
}
