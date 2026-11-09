#include "stdafx.h"
CHero::CHero()
{
	Init();
}
CHero::~CHero()
{
	Init();
}
void CHero::Init()
{
	m_bUse = false;
	m_fHitCtrlTime = 0.0f;
	m_fShowCtrlTime = 0.0f;
	m_bShow = false;
	m_CMan.Init();
	m_CSoldier.Init();
	m_CDoctor.Init();
	m_nAttack = 0;
}
void CHero::CreateObj(CRootScene* pScene, eCharacter eChar)
{
	switch (eChar)
	{
	case E_BUSINESSMAN:
		m_CMan.CreateObj(pScene);
		m_nSkill = m_CMan.m_nAmount;
		m_pAni = m_CMan.m_pAni;
		m_nAttack = m_CMan.m_nAttack;
		break;
	case E_DOCTOR:
		m_CDoctor.CreateObj(pScene);
		m_nSkill = m_CDoctor.m_nAmount;
		m_pAni = m_CDoctor.m_pAni;
		m_nAttack = m_CDoctor.m_nAttack;
		break;
	case E_SOLDIER:
		m_CSoldier.CreateObj(pScene);
		m_nSkill = m_CSoldier.m_nAmount;
		m_pAni = m_CSoldier.m_pAni;
		m_nAttack = m_CSoldier.m_nAttack;
		break;
	}
}
void CHero::Update(float dt, eCharacter eChar)
{
	Hit();
	switch (eChar)
	{
	case E_BUSINESSMAN:
		m_CMan.Update(dt);
		HeroInfoUpdate(m_CMan);
		m_nAttack = m_CMan.m_nAttack;
		break;
	case E_DOCTOR:
		m_CDoctor.Update(dt);
		HeroInfoUpdate(m_CDoctor);
		break;
	case E_SOLDIER:
		m_CSoldier.Update(dt);
		HeroInfoUpdate(m_CSoldier);
		break;
	}
}
void CHero::See(stMouseInfo stPos, eCharacter eChar)
{
	switch (eChar)
	{
	case E_BUSINESSMAN:
		m_CMan.See(stPos);
		break;
	case E_DOCTOR:
		m_CDoctor.See(stPos);
		break;
	case E_SOLDIER:
		m_CSoldier.See(stPos);
		break;
	}
}

void CHero::Hit()
{
	if (m_bShow)
	{
		m_fHitCtrlTime += D_WORLD->GetDeltaTime();
		m_fShowCtrlTime += D_WORLD->GetDeltaTime();
		if (m_fHitCtrlTime >= 0.2f)
		{
			m_pAni->SetShow(!m_pAni->GetShow());
			m_fHitCtrlTime = 0.0f;
		}
		if (m_fShowCtrlTime >= 0.6f)
		{
			m_fShowCtrlTime = 0.0f;
			m_pAni->SetShow(true);
			m_bShow = false;
		}
	}
}