#include "stdafx.h"
CHp::CHp()
{
	Init();
}
CHp::~CHp()
{
	Init();
}
void CHp::Init()
{
	m_fAlpha = 0.0f;
	m_fSkillTime = 0.0f;
}
void CHp::CreateObj(CRootScene* pScene)
{
	m_pAni = new CEMAnimation(6);
	m_pAni->SetTexture(pScene, 6,  "Data/Image/ui/Hp/3.png", "Data/Image/ui/Hp/2.png",
		"Data/Image/ui/Hp/1.png", "Data/Image/ui/Hp/0.png", "Data/Image/ui/Hp/0.png", "Data/Image/ui/Hp/0.png");
	m_pAni->SetPos(D_CAMERA->GetPosVec2().m_fX, D_CAMERA->GetPosVec2().m_fY, 0.0f);
	m_pAni->SetLoopType(E_ANI_ONE, 3, 3, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni->SetBlend(true);
	m_pAni->SetBlendFunc(GL_ONE, GL_ONE);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);

	m_pIcon = new CEMAnimation(7);
	m_pIcon->SetTexture(pScene, 7, "Data/Image/ui/Hp/-3.png", "Data/Image/ui/Hp/-2.png", "Data/Image/ui/Hp/-1.png"
		, "Data/Image/ui/Hp/+0.png", "Data/Image/ui/Hp/+1.png", "Data/Image/ui/Hp/+2.png", "Data/Image/ui/Hp/+2.png");
	m_pIcon->SetPos(D_CAMERA->GetPosVec2().m_fX + 45.0f, D_CAMERA->GetPosVec2().m_fY - 125.0f, 0.0f);
	m_pIcon->SetLoopType(E_ANI_ONE, 2, 2, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pIcon->SetBlend(true);
	m_pIcon->SetSize(0.3f);
	m_pIcon->SetBoundingBoxCalc(true);
	m_pIcon->SetFrstumCullingFlag(false);

	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture("Data/Image/ui/Hp/4.png");
	m_pPlane->SetBlend(true);
	m_pPlane->SetFrstumCullingFlag(false);
	m_pPlane->SetBoundingBoxCalc(true);
	m_pPlane->SetPos(D_CAMERA->GetPosVec2().m_fX, D_CAMERA->GetPosVec2().m_fY, 0.0f);
	m_pPlane->SetShow(false);
	
	pScene->Commit(-11, "HealthIcon", m_pIcon);
	pScene->Commit(-12, "Dead", m_pPlane);
	pScene->Commit(-11, "Hp", m_pAni);
}
void CHp::Update(float dt)
{
	m_pIcon->SetPos(D_CAMERA->GetPosVec2().m_fX + 45.0f, D_CAMERA->GetPosVec2().m_fY - 125.0f, 0.0f);
	m_pAni->SetPos(D_CAMERA->GetPosVec2().m_fX, D_CAMERA->GetPosVec2().m_fY, 0.0f);
	m_pPlane->SetPos(D_CAMERA->GetPosVec2().m_fX, D_CAMERA->GetPosVec2().m_fY, 0.0f);
	m_pIcon->SetLoopType(E_ANI_ONE, g_CInfo.m_nHp, g_CInfo.m_nHp, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	if (g_CInfo.m_nHp < 5)
	{
		m_pAni->SetLoopType(E_ANI_ONE, g_CInfo.m_nHp, g_CInfo.m_nHp, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	}
	if (g_CInfo.m_nHp <= 0)
	{
		m_pPlane->SetShow(true);
		m_fSkillTime += dt;
		if (m_fSkillTime >= 0.1f)
		{
			m_fSkillTime = 0.0f;
			m_fAlpha += 0.1f;
		}
		m_pPlane->SetAlpha(m_fAlpha);
	}
}