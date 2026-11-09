#include "stdafx.h"
CUI::CUI()
{
	Init();
}
CUI::~CUI()
{
	Init();
}
void CUI::Init()
{
	m_CHp.Init();
	m_nDate = 14;
	m_nMine = 3;
	m_nTime = 5;
	m_nSkill = 3;
	m_nSkillTime = 10;
	m_bStart = true;
	m_fTime = 0.0f;
	m_fAlpha = 0.0f;
	m_fSize = 0.2f;
	m_fXPos = 0.0f;
	m_bAlpha =  false;
}
void CUI::CreateObj(CRootScene* pScene)
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());

	m_pUIBar = new CEMPlane();
	m_pUIBar->SetTexture("Data/Image/ui/UI.png");
	m_pUIBar->SetBlend(true);
	m_pUIBar->SetPos(stPos.m_fX, stPos.m_fY - 133.0f, 0.0f);
	m_pUIBar->SetSize(0.4f, 0.35f);
	m_pUIBar->SetBoundingBoxCalc(true);

	pScene->Commit(-10, "A_UIBar", m_pUIBar);

	stEMVec3 stUIPos(m_pUIBar->GetPosVec3());

	m_pDate = new CEMNumber(11);
	m_pDate->SetTexture(pScene, 11, "Data/Image/ui/Num/0.png", "Data/Image/ui/Num/1.png"
		, "Data/Image/ui/Num/2.png", "Data/Image/ui/Num/3.png", "Data/Image/ui/Num/4.png"
		, "Data/Image/ui/Num/5.png", "Data/Image/ui/Num/6.png", "Data/Image/ui/Num/7.png"
		, "Data/Image/ui/Num/8.png", "Data/Image/ui/Num/9.png", "Data/Image/ui/Num/10.png");
	m_pDate->SetPos(stPos.m_fX + 30.0f, stPos.m_fY + 120.0f, 0.0f);
	m_pDate->SetBlend(true);
	m_pDate->SetAlpha(0.0f);
	m_pDate->SetShow(false);
	m_pDate->SetNumber(m_nDate);
	m_pDate->SetSize(0.2f, 0.2f);

	m_pMineNum = new CEMNumber(11);
	m_pMineNum->SetTexture(pScene, 11, "Data/Image/ui/Num/0.png", "Data/Image/ui/Num/1.png"
		, "Data/Image/ui/Num/2.png", "Data/Image/ui/Num/3.png", "Data/Image/ui/Num/4.png"
		, "Data/Image/ui/Num/5.png", "Data/Image/ui/Num/6.png", "Data/Image/ui/Num/7.png"
		, "Data/Image/ui/Num/8.png", "Data/Image/ui/Num/9.png", "Data/Image/ui/Num/10.png");
	m_pMineNum->SetPos(stUIPos.m_fX - 60.0f, stUIPos.m_fY - 8.0f, 0.0f);
	m_pMineNum->SetBlend(true);
	m_pMineNum->SetAlpha(1.0f);
	m_pMineNum->SetNumber(m_nMine);
	m_pMineNum->SetSize(0.14f);

	m_pDay = new CEMPlane();
	m_pDay->SetTexture("Data/Image/ui/Num/Day.png");
	m_pDay->SetBlend(true);
	m_pDay->SetAlpha(0.0f);
	m_pDay->SetBoundingBoxCalc(true);
	m_pDay->SetShow(false);
	m_pDay->SetPos(stPos.m_fX, stPos.m_fY + 120.0f, 0.0f);
	m_pDay->SetSize(0.23f, 0.23f);

	m_pClear = new CEMPlane();
	m_pClear->SetTexture("Data/Image/ui/Clear.png");
	m_pClear->SetAlpha(0.0f);
	m_pClear->SetBlend(true);
	m_pClear->SetPos(stPos.m_fX, stPos.m_fY,0.0f);
	m_pClear->SetShow(false);
	m_pClear->SetBoundingBoxCalc(true);
	m_pClear->SetFrstumCullingFlag(false);

	m_CHp.CreateObj(pScene);
	NumIcon(pScene);

	pScene->Commit(-10, "B_MineNum", m_pMineNum);
	pScene->Commit(-12, "Clear", m_pClear);
	pScene->Commit(-10, "Day", m_pDay);
	pScene->Commit(-10, "Date", m_pDate);
}
void CUI::NumIcon(CRootScene* pScene)
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());

	stEMVec3 stUIPos(m_pUIBar->GetPosVec3());

	m_pScore = new CEMPlane();
	m_pScore->SetTexture("Data/Image/ui/Score.png");
	m_pScore->SetPos(stPos.m_fX - 217.0f, stPos.m_fY + 130.0f, 0.0f);
	m_pScore->SetSize(0.18f);
	m_pScore->SetBlend(true);
	m_pScore->SetBoundingBoxCalc(true);

	m_pKill = new CEMPlane();
	m_pKill->SetTexture("Data/Image/ui/Kill.png");
	m_pKill->SetPos(stPos.m_fX - 217.0f, stPos.m_fY + 110.0f, 0.0f);
	m_pKill->SetSize(0.18f);
	m_pKill->SetBlend(true);
	m_pKill->SetBoundingBoxCalc(true);

	m_pSkillBlock = new CEMPlane();
	m_pSkillBlock->SetTexture("Data/Image/ui/SkillBlock.png");
	m_pSkillBlock->SetPos(stUIPos.m_fX + 45.0f, stUIPos.m_fY - 8.0f, 0.0f);
	m_pSkillBlock->SetBlend(true);
	m_pSkillBlock->SetShow(false);
	m_pSkillBlock->SetSize(0.28f, 0.4f);
	m_pSkillBlock->SetBoundingBoxCalc(true);

	m_pSkill = new CEMAnimation(5);
	m_pSkill->SetTexture(pScene, 5, "Data/Image/ui/Skill_3.png", "Data/Image/ui/Skill_2.png"
		, "Data/Image/ui/Skill_1.png", "Data/Image/ui/Skill.png", "Data/Image/ui/Skill.png");
	m_pSkill->SetPos(stUIPos.m_fX + 45.0f, stUIPos.m_fY - 8.0f, 0.0f);
	m_pSkill->SetLoopType(E_ANI_ONE, m_nSkill, m_nSkill, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pSkill->SetBlend(true);
	m_pSkill->SetSize(0.28f, 0.4f);
	m_pSkill->SetBoundingBoxCalc(true);

	m_pSkillTime = new CEMNumber(11);
	m_pSkillTime->SetTexture(pScene, 11, "Data/Image/ui/Num/0.png", "Data/Image/ui/Num/1.png"
		, "Data/Image/ui/Num/2.png", "Data/Image/ui/Num/3.png", "Data/Image/ui/Num/4.png"
		, "Data/Image/ui/Num/5.png", "Data/Image/ui/Num/6.png", "Data/Image/ui/Num/7.png"
		, "Data/Image/ui/Num/8.png", "Data/Image/ui/Num/9.png", "Data/Image/ui/Num/10.png");
	m_pSkillTime->SetPos(stUIPos.m_fX + 40.0f, stUIPos.m_fY - 8.0f, 0.0f);
	m_pSkillTime->SetBlend(true);
	m_pSkillTime->SetShow(false);
	m_pSkillTime->SetNumber(m_nSkillTime);
	m_pSkillTime->SetSize(0.16f);

	
	pScene->Commit(-11, "SkillBlock", m_pSkillBlock);
	pScene->Commit(-11, "Z_Amout", m_pSkillTime);
	pScene->Commit(-10, "SkillInfo", m_pSkill);
	pScene->Commit(-10, "ScoreIcon", m_pScore);
	pScene->Commit(-10, "KillIcon", m_pKill);
}
void CUI::Update()
{
	stEMVec2 stPos(D_CAMERA->GetPosVec2());
	
	m_pKill->SetPos(stPos.m_fX - 209.0f, stPos.m_fY + 110.0f, 0.0f);
	m_pScore->SetPos(stPos.m_fX - 200.0f, stPos.m_fY + 130.0f, 0.0f);
	m_pUIBar->SetPos(stPos.m_fX, stPos.m_fY - 133.0f, 0.0f);

	stEMVec3 stUIPos(m_pUIBar->GetPosVec3());

	m_pMineNum->SetPos(stUIPos.m_fX - 60.0f, stUIPos.m_fY - 8.0f, 0.0f);
	m_pMineNum->SetNumber(m_nMine);

	m_CHp.Update(D_WORLD->GetDeltaTime());
	m_pDate->SetNumber(m_nDate);
	m_pSkillTime->SetNumber(m_nSkillTime);

	m_pSkill->SetLoopType(E_ANI_ONE, m_nSkill, m_nSkill, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);

	if (m_nSkillTime >= 10)
	{
		if (!m_pSkillTime->GetShow())
		{
			m_pSkillTime->SetShow(true);
			m_pSkillBlock->SetShow(true);
		}
		m_pSkillTime->SetPos(stUIPos.m_fX + 40.0f, stUIPos.m_fY - 8.0f, 0.0f);
	}
	else
	{
		m_pSkillTime->SetPos(stUIPos.m_fX + 45.0f, stUIPos.m_fY - 8.0f, 0.0f);
		if (m_nSkillTime < 1.0f)
		{
			m_pSkillTime->SetShow(false);
		}
	}
	m_pSkill->SetPos(stUIPos.m_fX + 45.0f, stUIPos.m_fY - 8.0f, 0.0f);
	m_pSkillBlock->SetPos(stUIPos.m_fX + 45.0f, stUIPos.m_fY - 8.0f, 0.0f);

	m_pDate->SetPos(stPos.m_fX + 20.0f + m_fXPos, stPos.m_fY, 0.0f);
	m_pDay->SetPos(m_pDate->GetPosVec2().m_fX - 30.0f - m_fXPos, m_pDate->GetPosVec2().m_fY + 0.55f, 0.0f);
}

void CUI::DayAlphaUpdate()
{
	m_fTime += D_WORLD->GetDeltaTime();
	if (m_fTime >= 0.09f)
	{
		m_fTime = 0.0f;
		if (!m_bAlpha)
		{
			m_fXPos += 1.0f;
			m_fAlpha += 0.08f;
			m_fSize += 0.009f;
			m_pDate->SetAlpha(m_fAlpha);
			m_pDate->SetSize(m_fSize);
			m_pDay->SetAlpha(m_fAlpha);
			m_pDay->SetSize(m_fSize);
			if (m_fAlpha >= 1.5f)
			{
				m_bAlpha = true;
			}
		}
		else
		{
			m_fXPos -= 0.2f;
			m_fAlpha -= 0.1f;
			m_fSize -= 0.005f;
			m_pDay->SetAlpha(m_fAlpha);
			m_pDay->SetSize(m_fSize);
			m_pDate->SetAlpha(m_fAlpha);
			m_pDate->SetSize(m_fSize);
			if (m_fAlpha <= 0.0f)
			{
				m_fAlpha = 0.0f;
				m_fSize = 0.2f;
				m_fXPos = 0.0f;
				m_bAlpha = false;
				m_bStart = true;
				m_pDate->SetShow(false);
				m_pDay->SetShow(false);
			}
		}
	}
}

void CUI::ClearImageUpdate()
{
	m_pClear->SetShow(true);
	m_pClear->SetPos(D_CAMERA->GetPosVec2().m_fX, D_CAMERA->GetPosVec2().m_fY, 0.0f);
	m_CHp.m_fSkillTime += D_WORLD->GetDeltaTime();
	if (m_CHp.m_fSkillTime >= 0.1f)
	{
		m_CHp.m_fSkillTime = 0.0f;
		m_CHp.m_fAlpha += 0.1f;
	}
	m_pClear->SetAlpha(m_CHp.m_fAlpha);
}