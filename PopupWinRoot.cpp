#include "stdafx.h"

void CBtn::SetPos(stEMVec3 stPos)
{
	for (int i = 0; i < 2; i++)
	{
		if (pUI[i])
			pUI[i]->SetPos(stPos);
	}
}

void CBtn::SetRadioOnOff(bool bFlag)
{
	m_bRadioOnOff = bFlag;

	if (m_bRadioOnOff)
	{
		//true ON
		pUI[0]->SetShow(true);
		pUI[1]->SetShow(false);
	}
	else
	{
		//false OFF
		pUI[0]->SetShow(false);
		pUI[1]->SetShow(true);
	}
}

void CBtn::SetType(E_BTN_TYPE eType)
{
	m_eType = eType;

	//if (eType == E_RADIO_BTN)
	//	SetShow(true);
}

void CBtn::SetShow(bool bFlag)
{
	if (bFlag)
	{
		// 라디오 버튼일때 처리^^
		if (m_eType == E_RADIO_BTN)
		{
			if (m_bRadioOnOff)
			{
				pUI[0]->SetShow(true);
				pUI[1]->SetShow(false);
			}
			else
			{
				pUI[1]->SetShow(true);
				pUI[0]->SetShow(false);
			}
			return;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (pUI[i])
			pUI[i]->SetShow(bFlag);
	}
}

void CBtn::SetColor(CEMColor color)
{
	for (int i = 0; i < 2; i++)
	{
		if (pUI[i])
			pUI[i]->SetColor(color);
	}
}

//========================================

void CPopupWinRoot::SetPos(stEMVec3 stPos)
{
	if (m_pBg)
		m_pBg->SetPos(stPos);

	for (int i = 0; i < D_BTN_MAX; i++)
	{
		m_Btns[i].SetPos(stPos);
	}

	for (int j = 0; j < D_BTN_MAX; j++)
	{
		if (m_pEtcs[j])
			m_pEtcs[j]->SetPos(stPos);
	}
}

void CPopupWinRoot::SetShow(bool bFlag)
{
	SetCollisionFlag(bFlag);

	if (m_pBg)
		m_pBg->SetShow(bFlag);

	for (int i = 0; i < D_BTN_MAX; i++)
	{
		m_Btns[i].SetShow(bFlag);
	}

	for (int j = 0; j < D_BTN_MAX; j++)
	{
		if (m_pEtcs[j])
			m_pEtcs[j]->SetShow(bFlag);
	}
}

void CPopupWinRoot::SetColor(CEMColor color)
{
	//for (int i = 0; i < D_BTN_MAX; i++)
	//{
	//	m_Btns[i].SetColor(color);
	//}

	////for (int j = 0; j < D_BTN_MAX; j++)
	////{
	////	if (m_pEtcs[j])
	////		m_pEtcs[j]->SetColor(color);
	////}
}

void CPopupWinRoot::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	m_ClickSnd = ClickSnd;

	m_pScene = pScene;
	m_nLayer = nLayer;

	if (bShow)
	{
		for (int i = 0; i < D_BTN_MAX; i++)
		{
			if (m_Btns[i].GetType() == E_RADIO_BTN)
			{
				if (m_Btns[i].GetRadioOnOff())
				{
					m_Btns[i].pUI[0]->SetShow(true);
					m_Btns[i].pUI[1]->SetShow(false);
				}
				else
				{
					m_Btns[i].pUI[1]->SetShow(true);
					m_Btns[i].pUI[0]->SetShow(false);
				}
			}
		}
	}
	else
	{
		SetShow(bShow);
	}
}