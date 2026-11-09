#include "stdafx.h"
void CBlood::Init()
{
	m_stDestPos = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
	m_stHeroPosToDestPosDir = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroRightVec3 = stEMVec3(0.0f, 1.0f, 0.0f);

	m_fDegree = 0.0f;
	m_fDot = 0.0f;
	m_fRadian = 0.0f;
}
void CBlood::CreateObj(CRootScene* pScene)
{
	for (int i = 0; i < D_BLOOD_MAX; i++)
	{
		m_pAni[i] = new CEMAnimation(6);
		m_pAni[i]->SetTexture(pScene, 6, "Data/Image/Effect/blood/output-0.png", "Data/Image/Effect/blood/output-1.png"
			, "Data/Image/Effect/blood/output-2.png", "Data/Image/Effect/blood/output-3.png", "Data/Image/Effect/blood/output-4.png", "Data/Image/Effect/blood/output-5.png");
		m_pAni[i]->SetBlend(true);
		m_pAni[i]->SetTime(0.07f);
		m_pAni[i]->SetSize(0.5f);
		m_pAni[i]->SetBlendFunc(GL_SRC_ALPHA, GL_ONE);
		m_pAni[i]->SetPos(-1000.0f, -1000.0f, 0.0f);
		m_pAni[i]->SetShow(false);
		m_pAni[i]->SetBoundingBoxCalc(true);

		stdEMString stTemp = "Effect_Blood" + IntToEMString(i);
		pScene->Commit(-2, stTemp, m_pAni[i]);
	}
}

void CBlood::Update(stEMVec3 stPos)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (m_pAni[i]->GetShow() == true)
		{
			m_pAni[i]->SetPos(stPos);
			if (m_pAni[i]->GetCurFrameNumber() >= 4)
			{
				Disable(i);
			}
		}
	}
}

void CBlood::Enable(stEMVec3 stPos, int nIndex)
{
	See(stPos);
	m_pAni[nIndex]->SetPos(stPos);
	m_pAni[nIndex]->SetLoopType(E_ANI_ONE, 0, 5, E_ANI_ENDING_TYPE_SHOW_FALSE);
	m_pAni[nIndex]->SetZRot(m_fDegree);
	m_pAni[nIndex]->SetShow(true);
}
void CBlood::Disable(int nIndex)
{
	m_pAni[nIndex]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pAni[nIndex]->SetShow(false);
}

void CBlood::See(stEMVec3 stPos)
{
	// 방향벡터 = 목적지 벡터 - 주인공 벡터
	m_stHeroPosToDestPosDir = m_stDestPos - stPos;

	// 단위벡터로 변경
	m_stHeroPosToDestPosDir.Normalize();
	m_stHeroDirVec3.Normalize();

	// 내적 계산
	m_fDot = stEMVec3::Dot(m_stHeroDirVec3, m_stHeroPosToDestPosDir);

	// 각도 구하기^^
	m_fRadian = (float)acos(m_fDot);

	// 업벡터 구하기
	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));

	if (stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir) > 0.0f)
	{
		m_fDegree = CEMMath::ToDegrees(m_fRadian);
	}
	else
	{
		m_fDegree = CEMMath::ToDegrees(-m_fRadian);
	}
}