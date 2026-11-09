#include "stdafx.h"
CEffect::CEffect()
{
	Init();
}
CEffect::~CEffect()
{
	Init();
}
void CEffect::Init()
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_fEffectTime[i] = 0.0f;
		m_fAlpha[i] = 1.0f;
		m_bDisappear[i] = false;
	}
}
void CEffect::CreateObj(CRootScene* pScene)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_pEffect[i] = new CEMAnimation(7);
		m_pEffect[i]->SetPos(-1000.0f, -1000.0f, 0.0f);
		m_pEffect[i]->SetSize(0.1f);
		m_pEffect[i]->SetTexture(pScene, 7, "Data/Image/Effect/0.png", "Data/Image/Effect/1.png", "Data/Image/Effect/2.png"
			, "Data/Image/Effect/3.png", "Data/Image/Effect/4.png", "Data/Image/Effect/5.png", "Data/Image/Effect/Blood.png");
		m_pEffect[i]->SetTime(0.1f);
		m_pEffect[i]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pEffect[i]->SetFrstumCullingFlag(false);
		m_pEffect[i]->SetBlend(true);
		m_pEffect[i]->SetBoundingBoxCalc(true);
		m_pEffect[i]->SetShow(false);

		stdEMString stTemp = "Effect" + IntToEMString(i);
		pScene->Commit(8,  stTemp, m_pEffect[i]);
	}
}
void CEffect::Update(float dt)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (m_pEffect[i]->GetShow() == true)
		{
			if (m_pEffect[i]->GetCurFrameNumber() == 6)
			{
				if (!m_bDisappear[i])
				{
					m_fEffectTime[i] += dt;
					if (m_fEffectTime[i] >= 3.0f)
					{
						m_fEffectTime[i] = 0.0f;
						m_bDisappear[i] = true;
					}
				}
				else
				{
					m_fAlpha[i] -= 0.01f;
					m_pEffect[i]->SetAlpha(m_fAlpha[i]);
					if (m_fAlpha[i] <= 0.0f)
					{
						Disable(i);
					}
				}
			}
		}
	}
}
void CEffect::Enable(stEMVec3 stPos, int nIndex)
{
	m_pEffect[nIndex]->SetPos(stPos);
	m_pEffect[nIndex]->SetLoopType(E_ANI_ONE, 0, 6, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pEffect[nIndex]->SetShow(true);
}
void CEffect::Disable(int nIndex)
{
	m_pEffect[nIndex]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pEffect[nIndex]->SetShow(false);
	m_fAlpha[nIndex] = 1.0f;
	m_pEffect[nIndex]->SetAlpha(1.0f);
	m_bDisappear[nIndex] = false;
}