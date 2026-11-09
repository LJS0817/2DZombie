#include "stdafx.h"
CMan::CMan()
{
	Init();
}
CMan::~CMan()
{
	Init();
}
void CMan::Init()
{
	m_nHp = 3;
	m_nAmount = D_SKILL_MAX;
	m_bHit = false;
	m_bUse = false;
	m_fDuration = 3.0f;
	m_fSkillTime = 0.0f;
	m_fSpeed = 100.0f;
	m_nAttack = 30;
	m_Soundsnd = NULL;
}
void CMan::CreateObj(CRootScene* pScene)
{
	m_pAni = new CEMAnimation(12);
	m_pAni->SetPos(260.0f, -150.0f, 0.0f);
	m_pAni->SetTexture(pScene, 12,"Data/Image/Hero/Man/0.png", "Data/Image/Hero/Man/0_1.png", "Data/Image/Hero/Man/0.png", "Data/Image/Hero/Man/0_2.png"
		, "Data/Image/Hero/Man/1.png", "Data/Image/Hero/Man/1_1.png", "Data/Image/Hero/Man/1.png", "Data/Image/Hero/Man/1_2.png"
		, "Data/Image/Hero/Man/2.png", "Data/Image/Hero/Man/2_1.png", "Data/Image/Hero/Man/2.png", "Data/Image/Hero/Man/2_2.png"
		, "Data/Image/Hero/Man/3.png");
	m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni->SetTime(0.135f);
	m_pAni->SetSize(0.2f, 0.2f);
	m_pAni->SetShow(true);
	m_pAni->SetBlend(true);
	m_pAni->SetBackFaceCulling(true);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);

	m_pRange = new CEMAnimation(5);
	m_pRange->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pRange->SetTexture(pScene, 5, "Data/Image/Effect/Power/0.png", "Data/Image/Effect/Power/1.png", "Data/Image/Effect/Power/2.png"
		, "Data/Image/Effect/Power/3.png", "Data/Image/Effect/Power/4.png");
	m_pRange->SetSize(0.35f);
	m_pRange->SetTime(0.10f);
	m_pRange->SetBlend(true);
	m_pRange->SetBlendFunc(GL_ONE, GL_ONE);
	m_pRange->SetFrstumCullingFlag(false);
	m_pRange->SetShow(false);


	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Charge.mp3");

	pScene->Commit(0, "RageEffect", m_pRange);
	pScene->Commit(0, "A_Hero",  m_pAni);
}
void CMan::Update(float dt)
{
	Move(dt);
	MoveAnimation();
	Clipping();
	Ability();
}
void CMan::Move(float dt)
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

void CMan::Clipping()
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

void CMan::Ability()
{
	if (m_fSkillTime >= 1.0f)
	{
		m_fSkillTime -= D_WORLD->GetDeltaTime();
	}
	else
	{
		if (D_INPUT->IsKeyDown(VK_Q))
		{
			if (m_bUse == false)
			{
				m_pRange->SetPos(m_pAni->GetPosVec2().m_fX, m_pAni->GetPosVec2().m_fY, 0.0f);	
				m_pRange->SetLoopType(E_ANI_ONE, 0, 4, E_ANI_ENDING_TYPE_SHOW_FALSE);
				m_bUse = true;
				m_nHp = g_CInfo.m_nHp;
				if (m_nHp < 5)
				{
					g_CInfo.m_nHp += 1;
				}
				m_nAttack = 60;
				m_pRange->SetShow(true);
				D_SOUND->Play(m_Soundsnd);
			}
		}
		if (m_nAmount <= 0)
		{
			m_nAmount = 3;
		}
	}
	if (m_bUse == true)
	{
		m_pRange->SetPos(m_pAni->GetPosVec2().m_fX, m_pAni->GetPosVec2().m_fY, 0.0f);
		m_fDuration -= D_WORLD->GetDeltaTime();
		if (m_fDuration <= 0.0f)
		{
			if (m_pRange->GetCurFrameNumber() == 4)
			{
				if (g_CInfo.m_nHp > 1 && m_nHp < g_CInfo.m_nHp && g_CInfo.m_nHp < 5)
				{
					g_CInfo.m_nHp -= 1;
				}
				m_fDuration = 5.0f;
				m_bUse = false;
				m_nAttack = 32;
				m_nAmount -= 1;
				m_pRange->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
				m_pRange->SetPos(-1000.0f, -1000.0f, 0.0f);
				m_pRange->SetShow(false);
				if (m_nAmount <= 0)
				{
					m_fSkillTime = 36.0f;
				}
			}
		}
	}
}