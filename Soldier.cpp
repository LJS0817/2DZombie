#include "stdafx.h"
CSoldier::CSoldier()
{
	//Init();
}
CSoldier::~CSoldier()
{
	//Init();
}
void CSoldier::Init()
{
	m_bUse = false;
	m_bHit = false;
	m_Soundsnd = NULL;
	m_fSpeed = 75.0f;
	m_nAmount = D_SKILL_MAX;
	m_nAttack = 40;
	m_CGrenade.Init();
}
void CSoldier::CreateObj(CRootScene* pScene)
{	
	m_pAni = new CEMAnimation(12);
	m_pAni->SetPos(260.0f, -150.0f, 0.0f);
	m_pAni->SetTexture(pScene, 12, "Data/Image/Hero/Soldier/0.png", "Data/Image/Hero/Soldier/0_1.png", "Data/Image/Hero/Soldier/0.png", "Data/Image/Hero/Soldier/0_2.png"
		, "Data/Image/Hero/Soldier/1.png", "Data/Image/Hero/Soldier/1_1.png", "Data/Image/Hero/Soldier/1.png", "Data/Image/Hero/Soldier/1_2.png"
		, "Data/Image/Hero/Soldier/2.png", "Data/Image/Hero/Soldier/2_1.png", "Data/Image/Hero/Soldier/2.png", "Data/Image/Hero/Soldier/2_2.png"
		, "Data/Image/Hero/Soldier/3.png");
	m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni->SetTime(0.15f);
	m_pAni->SetSize(0.2f, 0.2f);
	m_pAni->SetBlend(true);
	m_pAni->SetBackFaceCulling(true);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);
	m_pAni->SetShow(true);

	pScene->Commit(0, "A_Hero",  m_pAni);

	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Call.mp3");
	m_CGrenade.CreateObj(pScene);
}
void CSoldier::Update(float dt)
{
	Move(dt);
	MoveAnimation();
	Clipping();
	Ability();
	m_CGrenade.Update(dt);
}
void CSoldier::Move(float dt)
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

void CSoldier::Clipping()
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

void CSoldier::Ability()
{
	if (m_fSkillTime >= 1.0f)
	{
		m_fSkillTime -= D_WORLD->GetDeltaTime();
	}
	else
	{
		if (m_nAmount <= 0)
		{
			m_nAmount = D_SKILL_MAX;
		}
		if (!D_SOUND->IsPlaying(m_CGrenade.m_Explosionsnd))
		{
			if (D_INPUT->IsKeyDown(VK_Q))
			{
				if (m_bUse == false)
				{
					if (m_nAmount > 0)
					{
						if (m_CGrenade.m_pMissile->GetShow() == false && m_CGrenade.m_pAni->GetShow() == false)
						{
							D_SOUND->Play(m_Soundsnd, D_MNG->GetSoundVolume());
							stMouseInfo stPos(D_INPUT->GetMouseMovePos());

							stEMVec2 stDesPos(0.0f, 0.0f);

							// 마우스 좌표를 월드 좌표로 변환합니다.^^
							stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

							m_stClickDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

							m_CGrenade.m_pAni->SetPos(m_stClickDestPos);
							m_CGrenade.m_pAni->SetShow(true);
							m_CGrenade.m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);

							m_bUse = true;
						}
					}
				}
			}
		}
	}
	if (m_bUse == true)
	{
		if (!D_SOUND->IsPlaying(m_Soundsnd))
		{
			m_CGrenade.Enable(m_pAni->GetPosVec3(), m_stClickDestPos);
			m_nAmount -= 1;
			m_bUse = false;
			if (m_nAmount <= 0)
			{
				m_fSkillTime = 46.0f;
			}
		}
	}
}