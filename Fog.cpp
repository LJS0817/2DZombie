#include "stdafx.h"
CFog::CFog()
{
	//Init();
}
CFog::~CFog()
{
	//Init();
}
void CFog::Init()
{
	m_pAni = NULL;
	m_bUse = false;
	m_fTime = 0.0f;
	m_nIndex = 0;
	for (int i = 0; i < 67; i++)
	{
		m_pFog[i] = NULL;
	}
}
void CFog::CreateObj(CRootScene* pScene)
{
	//m_pAni = new CEMAnimation(67);
	//m_pAni->SetTexture(pScene, 67, "Data/Image/Effect/Fog_1/output-0.png", "Data/Image/Effect/Fog_1/output-1.png", "Data/Image/Effect/Fog_1/output-2.png"
	//	, "Data/Image/Effect/Fog_1/output-3.png", "Data/Image/Effect/Fog_1/output-4.png", "Data/Image/Effect/Fog_1/output-5.png"
	//	, "Data/Image/Effect/Fog_1/output-6.png", "Data/Image/Effect/Fog_1/output-7.png", "Data/Image/Effect/Fog_1/output-8.png"
	//	, "Data/Image/Effect/Fog_1/output-9.png", "Data/Image/Effect/Fog_1/output-10.png", "Data/Image/Effect/Fog_1/output-11.png"
	//	, "Data/Image/Effect/Fog_1/output-12.png", "Data/Image/Effect/Fog_1/output-13.png", "Data/Image/Effect/Fog_1/output-14.png"
	//	, "Data/Image/Effect/Fog_1/output-15.png", "Data/Image/Effect/Fog_1/output-16.png", "Data/Image/Effect/Fog_1/output-17.png"
	//	, "Data/Image/Effect/Fog_1/output-18.png", "Data/Image/Effect/Fog_1/output-19.png", "Data/Image/Effect/Fog_1/output-20.png"
	//	, "Data/Image/Effect/Fog_1/output-21.png", "Data/Image/Effect/Fog_1/output-22.png", "Data/Image/Effect/Fog_1/output-23.png"
	//	, "Data/Image/Effect/Fog_1/output-24.png", "Data/Image/Effect/Fog_1/output-25.png", "Data/Image/Effect/Fog_1/output-26.png"
	//	, "Data/Image/Effect/Fog_1/output-27.png", "Data/Image/Effect/Fog_1/output-28.png", "Data/Image/Effect/Fog_1/output-29.png"
	//	, "Data/Image/Effect/Fog_1/output-30.png", "Data/Image/Effect/Fog_1/output-31.png", "Data/Image/Effect/Fog_1/output-32.png"
	//	, "Data/Image/Effect/Fog_1/output-33.png", "Data/Image/Effect/Fog_1/output-34.png", "Data/Image/Effect/Fog_1/output-35.png"
	//	, "Data/Image/Effect/Fog_1/output-36.png", "Data/Image/Effect/Fog_1/output-37.png", "Data/Image/Effect/Fog_1/output-38.png"
	//	, "Data/Image/Effect/Fog_1/output-39.png", "Data/Image/Effect/Fog_1/output-40.png", "Data/Image/Effect/Fog_1/output-41.png"
	//	, "Data/Image/Effect/Fog_1/output-42.png", "Data/Image/Effect/Fog_1/output-43.png", "Data/Image/Effect/Fog_1/output-44.png"
	//	, "Data/Image/Effect/Fog_1/output-45.png", "Data/Image/Effect/Fog_1/output-46.png", "Data/Image/Effect/Fog_1/output-47.png"
	//	, "Data/Image/Effect/Fog_1/output-48.png", "Data/Image/Effect/Fog_1/output-49.png", "Data/Image/Effect/Fog_1/output-50.png"
	//	, "Data/Image/Effect/Fog_1/output-51.png", "Data/Image/Effect/Fog_1/output-52.png", "Data/Image/Effect/Fog_1/output-53.png"
	//	, "Data/Image/Effect/Fog_1/output-54.png", "Data/Image/Effect/Fog_1/output-55.png", "Data/Image/Effect/Fog_1/output-56.png"
	//	, "Data/Image/Effect/Fog_1/output-57.png", "Data/Image/Effect/Fog_1/output-58.png", "Data/Image/Effect/Fog_1/output-59.png"
	//	, "Data/Image/Effect/Fog_1/output-60.png", "Data/Image/Effect/Fog_1/output-61.png", "Data/Image/Effect/Fog_1/output-62.png"
	//	, "Data/Image/Effect/Fog_1/output-63.png", "Data/Image/Effect/Fog_1/output-64.png", "Data/Image/Effect/Fog_1/output-65.png", "Data/Image/Effect/Fog_1/output-66.png");
	//m_pAni->SetPos(270.0f, -135.0f, 0.0f);
	//m_pAni->SetTime(0.15f);
	//m_pAni->SetSize(1.3f);
	//m_pAni->SetBlend(true);
	//m_pAni->SetFrstumCullingFlag(false);
	//m_pAni->SetBlendFunc(GL_DST_COLOR, GL_ONE);
	//
	//pScene->Commit(1, "Fog", m_pAni);

	for (int i = 0; i < 67; i++)
	{
		m_pFog[i] = new CEMPlane();
		m_pFog[i]->SetTexture("Data/Image/Effect/Fog_1/output-" + IntToEMString(i) + ".png");
		m_pFog[i]->SetPos(270.0f, -135.0f, 0.0f);
		m_pFog[i]->SetShow(false);
		m_pFog[i]->SetBlend(true);
		m_pFog[i]->SetFrstumCullingFlag(false);
		m_pFog[i]->SetSize(1.3f);
		m_pFog[i]->SetAlpha(0.5f);
		m_pFog[i]->SetBlendFunc(GL_DST_COLOR, GL_ONE);

		stdEMString stTemp = "Fog" + IntToEMString(i);
		pScene->Commit(1, stTemp, m_pFog[i]);
	}
}
void CFog::Update(float dt)
{
	m_fTime += dt;
	if (m_fTime >= 0.15f)
	{
		m_fTime = 0.0f;
		if (m_bUse)
		{
			if (!m_pFog[m_nIndex]->GetShow())
			{
				m_pFog[m_nIndex]->SetShow(true);
			}
			if (m_nIndex == 66)
			{
				if (m_pFog[0]->GetShow())
				{
					m_pFog[0]->SetShow(false);
				}
			}
			else
			{
				if (m_pFog[m_nIndex + 1]->GetShow())
				{
					m_pFog[m_nIndex + 1]->SetShow(false);
				}
			}
			m_nIndex--;
		}
		else
		{
			if (!m_pFog[m_nIndex]->GetShow())
			{
				m_pFog[m_nIndex]->SetShow(true);
			}
			if (m_nIndex == 0)
			{
				if (m_pFog[66]->GetShow())
				{
					m_pFog[66]->SetShow(false);
				}
			}
			else
			{
				if (m_pFog[m_nIndex - 1]->GetShow())
				{
					m_pFog[m_nIndex - 1]->SetShow(false);
				}
			}
			m_nIndex++;
		}
		if (m_nIndex >= 66)
		{
			m_bUse = true;
			m_nIndex = 65;
		}
		if (m_nIndex <= 0)
		{
			m_nIndex = 1;
			m_bUse = false;
		}
	}
}