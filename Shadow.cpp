#include "stdafx.h"
void CShadow::Init()
{

}
void CShadow::CreateObj(CRootScene* pScene)
{
	for (int i = 0; i < D_SHADOW_MAX; i++)
	{
		m_pShadow[i] = new CEMPlane();
		m_pShadow[i]->SetTexture("Data/Image/Effect/Shadow.png");
		m_pShadow[i]->SetBlend(true);
		m_pShadow[i]->SetBoundingBoxCalc(true);
		m_pShadow[i]->SetPos(-100.0f, 100.0f, 0.0f);
		m_pShadow[i]->SetSize(0.3f);

		stdEMString stTemp = "Shadow" + IntToEMString(i);
		pScene->Commit(4, stTemp, m_pShadow[i]);
	}
}

void CShadow::Update(CEMAnimation* pAni, int nIndex)
{
	Move(pAni, nIndex);
}

void CShadow::Move(CEMAnimation* pAni, int nIndex)
{
	if (m_pShadow[nIndex]->GetShow() == true)
	{
		if (g_CInfo.m_eMonster[nIndex] == E_SPITTER)
			m_pShadow[nIndex]->SetPos(pAni->GetPosVec3().m_fX, pAni->GetPosVec3().m_fY - 32.0f, 0.0f);
		else
			m_pShadow[nIndex]->SetPos(pAni->GetPosVec3().m_fX, pAni->GetPosVec3().m_fY - 16.0f, 0.0f);
	}
}

void CShadow::Enable(stEMVec3 stPos, int nIndex)
{
	m_pShadow[nIndex]->SetShow(true);
	if (g_CInfo.m_eMonster[nIndex] == E_SPITTER)
	{
		m_pShadow[nIndex]->SetPos(stPos.m_fX, stPos.m_fY - 32.0f, 0.0f);
		m_pShadow[nIndex]->SetSize(0.5f);
	}
	else
	{
		m_pShadow[nIndex]->SetPos(stPos.m_fX, stPos.m_fY - 16.0f, 0.0f);
		if (m_pShadow[nIndex]->GetSize() == 0.5f)
			m_pShadow[nIndex]->SetSize(0.3f);
	}
}

void CShadow::Disable(int nIndex)
{
	m_pShadow[nIndex]->SetPos(-100.0f, 100.0f, 0.0f);
	m_pShadow[nIndex]->SetShow(false);
}