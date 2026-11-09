#include "stdafx.h"
CDoctor::CDoctor()
{
	Init();
}
CDoctor::~CDoctor()
{
	Init();
}
void CDoctor::Init()
{
	m_Soundsnd = NULL;

	m_nAmount = D_SKILL_MAX;
	m_nAttack = 20;

	m_fHpCtrlTime = 0.0f;
	m_bHit = false;
	m_fSkillTime = 0.0f;
	m_fSpeed = 75.0f;
}
void CDoctor::CreateObj(CRootScene* pScene)
{
	m_pAni = new CEMAnimation(12);
	m_pAni->SetPos(260.0f, -150.0f, 0.0f);
	m_pAni->SetTexture(pScene, 12,"Data/Image/Hero/Doctor/0.png", "Data/Image/Hero/Doctor/0_1.png", "Data/Image/Hero/Doctor/0.png", "Data/Image/Hero/Doctor/0_2.png"
		, "Data/Image/Hero/Doctor/1.png", "Data/Image/Hero/Doctor/1_1.png", "Data/Image/Hero/Doctor/1.png", "Data/Image/Hero/Doctor/1_2.png"
		, "Data/Image/Hero/Doctor/2.png", "Data/Image/Hero/Doctor/2_1.png", "Data/Image/Hero/Doctor/2.png", "Data/Image/Hero/Doctor/2_2.png"
		, "Data/Image/Hero/Doctor/3.png");
	m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni->SetTime(0.15f);
	m_pAni->SetSize(0.2f, 0.2f);
	m_pAni->SetBlend(true);
	m_pAni->SetShow(true);
	m_pAni->SetBackFaceCulling(true);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);

	m_pHeal= new CEMAnimation(25);
	m_pHeal->SetTexture(pScene, 25, "Data/Image/Effect/Heal/output-0.png", "Data/Image/Effect/Heal/output-1.png", "Data/Image/Effect/Heal/output-2.png"
		, "Data/Image/Effect/Heal/output-3.png", "Data/Image/Effect/Heal/output-4.png", "Data/Image/Effect/Heal/output-5.png", "Data/Image/Effect/Heal/output-6.png"
		, "Data/Image/Effect/Heal/output-7.png", "Data/Image/Effect/Heal/output-8.png", "Data/Image/Effect/Heal/output-9.png", "Data/Image/Effect/Heal/output-10.png"
		, "Data/Image/Effect/Heal/output-11.png", "Data/Image/Effect/Heal/output-12.png", "Data/Image/Effect/Heal/output-13.png", "Data/Image/Effect/Heal/output-14.png"
		, "Data/Image/Effect/Heal/output-15.png", "Data/Image/Effect/Heal/output-16.png", "Data/Image/Effect/Heal/output-17.png", "Data/Image/Effect/Heal/output-18.png"
		, "Data/Image/Effect/Heal/output-19.png", "Data/Image/Effect/Heal/output-20.png", "Data/Image/Effect/Heal/output-21.png", "Data/Image/Effect/Heal/output-22.png"
		, "Data/Image/Effect/Heal/output-23.png", "Data/Image/Effect/Heal/output-24.png");
	m_pHeal->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pHeal->SetTime(0.05f);
	m_pHeal->SetSize(0.3f);
	m_pHeal->SetBlend(true);
	m_pHeal->SetBlendFunc(GL_ONE, GL_ONE);
	m_pHeal->SetFrstumCullingFlag(false);
	m_pHeal->SetBoundingBoxCalc(true);
	m_pHeal->SetShow(false);

	pScene->Commit(-5, "HealEffect", m_pHeal);
	pScene->Commit(0, "A_Hero",  m_pAni);

	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Stimgun.mp3");
}
void CDoctor::Update(float dt)
{
	Move(dt);
	MoveAnimation();
	Clipping();
	Ability();
	CalcTime();
}
void CDoctor::Move(float dt)
{
	if (D_INPUT->IsKeyDown(VK_W))
	{
		m_pAni->MoveY(m_fSpeed * D_WORLD->GetDeltaTime());
	}
	if (D_INPUT->IsKeyDown(VK_A))
	{
		m_pAni->MoveX(-m_fSpeed * D_WORLD->GetDeltaTime());
	}
	if (D_INPUT->IsKeyDown(VK_S))
	{
		m_pAni->MoveY(-m_fSpeed * D_WORLD->GetDeltaTime());
	}
	if (D_INPUT->IsKeyDown(VK_D))
	{
		m_pAni->MoveX(m_fSpeed * D_WORLD->GetDeltaTime());
	}
}

void CDoctor::Clipping()
{
	stEMVec2 stPos = m_pAni->GetPosVec2();
	if (stPos.m_fX <= 30.0f)
	{
		m_pAni->SetPos(30.0f, stPos.m_fY, 0.0f);
	}
	if (stPos.m_fX >= 490.0f)
	{
		m_pAni->SetPos(490.0f, stPos.m_fY, 0.0f);
	}
	if (stPos.m_fY >= 19.5f)
	{
		m_pAni->SetPos(stPos.m_fX, 19.5f, 0.0f);
	}
	if (stPos.m_fY <= -300.0f)
	{
		m_pAni->SetPos(stPos.m_fX, -300.0f, 0.0f);
	}
}

void CDoctor::Ability()
{
	if (m_fSkillTime >= 1.0f)
	{
		m_fSkillTime -= D_WORLD->GetDeltaTime();
	}
	else
	{
		if (m_nAmount <= 0)
		{
			m_nAmount = 3;
		}
		if (D_INPUT->IsKeyDown(VK_Q))
		{
			if (m_bUse == false)
			{
				if (m_nAmount > 0)
				{
					m_pHeal->SetLoopType(E_ANI_ONE, 0, 25, E_ANI_ENDING_TYPE_SHOW_FALSE);
					D_SOUND->Play(m_Soundsnd);
					if (g_CInfo.m_nHp < 5)
					{
						g_CInfo.m_nHp += 1;
					}
					m_nAmount -= 1;
					m_bUse = true;
					m_pHeal->SetPos(m_pAni->GetPosVec2().m_fX, m_pAni->GetPosVec2().m_fY, 0.0f);
					m_pHeal->SetShow(true);
				}
			}
		}
	}
	if (m_bUse == true)
	{
		m_pHeal->SetPos(m_pAni->GetPosVec2().m_fX, m_pAni->GetPosVec2().m_fY, 0.0f);
		if (m_pHeal->GetCurFrameNumber() >= 24)
		{
			m_pHeal->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
			m_pHeal->SetPos(-1000.0f, -1000.0f, 0.0f);
			m_pHeal->SetShow(false);
			m_bUse = false;
		}
		if (m_nAmount <= 0)
		{
			m_fSkillTime = 90.8f;
		}
	}
}

void CDoctor::CalcTime()
{
	if (g_CInfo.m_nHp > 3)
	{
		m_fHpCtrlTime += D_WORLD->GetDeltaTime();
		if (m_fHpCtrlTime >= 10.0f)
		{
			m_fHpCtrlTime = 0.0f;
			g_CInfo.m_nHp = 3;
		}
	}
}