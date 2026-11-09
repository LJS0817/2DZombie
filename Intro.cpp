#include "stdafx.h"
void CIntro::Init()
{
	m_stPos = stEMVec2(100.0f, -50.0f);
	m_bMove = false;
	m_bUse = true;
	m_bSkip = false;
	m_fAlpha = 1.0f;
}
void CIntro::CreateObj(CRootScene* pScene)
{
	if (g_CInfo.m_bMode)
	{
		m_pPlane = new CEMPlane();
		m_pPlane->SetTexture("Data/Image/ui/buttons/Skip.png");
		m_pPlane->SetBlend(true);
		m_pPlane->SetPos(130.0f, -250.0f, 0.0f);
		m_pPlane->SetSize(0.2f);

		m_pText = new CEMPlane();
		m_pText->SetTexture("Data/Image/ui/buttons/Last.png");
		m_pText->SetBlend(true);
		m_pText->SetPos(250.0f, -120.0f, 0.0f);
		m_pText->SetShow(false);
		m_pText->SetSize(0.5f);

		m_pAni = new CEMAnimation(11);
		m_pAni->SetTexture(pScene, 11, "Data/Image/helicopter/output-0.png", "Data/Image/helicopter/output-1.png", "Data/Image/helicopter/output-2.png"
			, "Data/Image/helicopter/output-3.png", "Data/Image/helicopter/output-4.png", "Data/Image/helicopter/output-5.png", "Data/Image/helicopter/output-6.png"
			, "Data/Image/helicopter/output-7.png", "Data/Image/helicopter/output-8.png", "Data/Image/helicopter/output-9.png", "Data/Image/helicopter/output-10.png");
		m_pAni->SetBlend(true);
		m_pAni->SetShow(false);
		m_pAni->SetTime(0.1f);
		m_pAni->SetFrstumCullingFlag(false);
		m_pAni->SetPos(m_stPos.m_fX, m_stPos.m_fY, 0.0f);

		m_pEffect = new CEMAnimation(10);
		m_pEffect->SetTexture(pScene, 10, "Data/Image/Effect/Fire/0.png", "Data/Image/Effect/Fire/1.png", "Data/Image/Effect/Fire/2.png"
			, "Data/Image/Effect/Fire/3.png", "Data/Image/Effect/Fire/4.png", "Data/Image/Effect/Fire/5.png", "Data/Image/Effect/Fire/6.png"
			, "Data/Image/Effect/Fire/7.png", "Data/Image/Effect/Fire/8.png", "Data/Image/Effect/Fire/9.png");
		m_pEffect->SetPos(m_stPos.m_fX, m_stPos.m_fY, 0.0f);
		m_pEffect->SetShow(false);
		m_pEffect->SetBlend(true);
		m_pEffect->SetBoundingBoxCalc(true);
		m_pEffect->SetFrstumCullingFlag(false);
		m_pEffect->SetTime(0.1f);
		m_pEffect->SetSize(0.15f);

		pScene->Commit(-16, "Explosion_3", m_pEffect);
		pScene->Commit(-15, "Helicopter", m_pAni);
		pScene->Commit(-12, "Text", m_pText);
		pScene->Commit(-12, "Skip", m_pPlane);
	}
	m_pMap = new CEMAnimation(4);
	m_pMap->SetTexture(pScene, 4, "Data/Image/Map/2.png", "Data/Image/Map/2_1.png", "Data/Image/Map/2_2.png", "Data/Image/Map/2_3.png");
	m_pMap->SetTime(0.15f);
	m_pMap->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pMap->SetBlend(true);
	m_pMap->SetFrstumCullingFlag(false);
	m_pMap->SetPos(260.0f, -150.0f, 0.0f);
	m_pMap->SetSize(0.5f);

	pScene->Commit(-11, "Intro", m_pMap);
	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Intro.mp3");
}
void CIntro::Update()
{
	if (!D_SOUND->IsPlaying(m_Soundsnd))
	{
		D_SOUND->Pause(D_MNG->m_BGMSnd, false);
		Disable();
	}
	else
	{
		D_SOUND->Pause(D_MNG->m_BGMSnd, true);
		Skip();
		SkipText();
		Enable();
	}
}

void CIntro::Disable()
{
	if (m_bUse)
	{
		m_fAlpha -= 0.05f;
		m_pMap->SetAlpha(m_fAlpha);
		m_pText->SetAlpha(m_fAlpha);
		if (m_fAlpha <= 0.1f)
		{
			m_fAlpha = 1.0f;
			m_bUse = false;
			m_pEffect->SetShow(false);
			m_pMap->SetShow(false);
			m_pText->SetShow(false);
			m_pAni->SetShow(false);
			m_pPlane->SetShow(false);
		}
	}
}

void CIntro::Enable()
{
	if (!m_bMove)
	{
		m_fSkillTime += D_WORLD->GetDeltaTime();
		if (m_fSkillTime >= 8.0f)
		{
			m_fSkillTime = 0.0f;
			m_pAni->SetShow(true);
			m_pEffect->SetShow(true);
			m_bMove = true;
		}
	}
	else
	{
		Move();
	}
}

void CIntro::Move()
{
	if (m_pMap->GetCurFrameNumber() == 0)
	{
		m_fSkillTime += D_WORLD->GetDeltaTime();
		if (m_fSkillTime >= 5.0f)
		{
			m_fSkillTime = 0.0f;
			m_pText->SetShow(true);
			m_pMap->SetLoopType(E_ANI_LOOP, 1, 3);
		}
	}
	m_stPos.m_fX += 150.0f * D_WORLD->GetDeltaTime();
	m_stPos.m_fY -= 100.0f * D_WORLD->GetDeltaTime();
	m_pAni->SetPos(m_stPos.m_fX, m_stPos.m_fY, 0.0f);
	m_pEffect->SetPos(m_stPos.m_fX, m_stPos.m_fY + 10.0f, 0.0f);
}

void CIntro::Skip()
{
	if (!m_bSkip)
	{
		if (D_INPUT->IsKeyUp(VK_F))
		{
			m_bSkip = true;
		}
	}
	else
	{
		D_SOUND->Pause(D_MNG->m_BGMSnd, false);
		D_SOUND->Pause(m_Soundsnd, true);
		m_bUse = false;
		m_pMap->SetShow(false);
		m_pEffect->SetShow(false);
		m_pText->SetShow(false);
		m_pAni->SetShow(false);
		m_pPlane->SetShow(false);
	}
}
void CIntro::SkipText()
{
	if (!m_bSkip)
	{
		m_fTime += D_WORLD->GetDeltaTime();
		float fTime = 0.8f;
		if (!m_pPlane->GetShow())
		{
			fTime = 0.5f;
		}
		if (m_fTime >= fTime)
		{
			m_fTime = 0.0f;
			m_pPlane->SetShow(!m_pPlane->GetShow());
		}
	}
}

void CIntro::MapUpdate()
{
	m_fTime += D_WORLD->GetDeltaTime();
	if (m_fTime >= 3.0f)
	{
		m_fTime = 0.0f;
		m_bUse = false;
		m_pMap->SetShow(false);
	}
}