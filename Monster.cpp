#include "stdafx.h"
CMonster::CMonster()
{
	Init();
}
CMonster::~CMonster()
{
	Init();
}
void CMonster::Init()
{
	m_CNor_1.Init();
	m_CNor_2.Init();
	m_CNor_3.Init();
	m_CSpecial.Init();
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_fTime[i] = 0.0f;
		m_bHit[i] = false;
		m_stPos[i] = NULL;
		m_fSpeed[i] = 1.0f;
		m_nHp[i] = 100;
		m_nAttack[i] = 25;
	}
}
void CMonster::CreateObj(CRootScene* pScene)
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_pMonster[i] = new CEMAnimation();
		m_pMonster[i]->SetShow(false);
		m_CNor_1.CreateObj(pScene, i);
		m_CNor_2.CreateObj(pScene, i);
		m_CNor_3.CreateObj(pScene, i);
	}
	m_CSpecial.CreateObj(pScene);
	m_sndDead = D_SOUND->FileOpen("Data/Sound/Dead_Zombie.mp3");
	m_sndDead_2 = D_SOUND->FileOpen("Data/Sound/Hit_Zombie.mp3");
	m_sndDead_3 = D_SOUND->FileOpen("Data/Sound/Dead_2_Zombie.mp3");
	m_sndDead2 = D_SOUND->FileOpen("Data/Sound/Dead2_Zombie.mp3");
}
void CMonster::Update(float dt, stEMVec3 stHeroPos)
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		stEMVec3 stHeroDestPos(stEMVec3(stHeroPos.m_fX + m_stPos[i].m_fX, stHeroPos.m_fY + m_stPos[i].m_fY, 0.0f));
		switch (g_CInfo.m_eMonster[i])
		{
		case E_NORMAL_1:
			m_CNor_1.Update(dt, i, m_fSpeed[i], stHeroDestPos, m_bHit[i]);
			m_pMonster[i] = m_CNor_1.m_pMonster[i];
			m_CNor_1.m_nHp[i] = m_nHp[i];
			break;
		case E_NORMAL_2:
			m_CNor_2.Update(dt, i, m_fSpeed[i], stHeroDestPos, m_bHit[i]);
			m_pMonster[i] = m_CNor_2.m_pMonster[i];
			m_CNor_2.m_nHp[i] = m_nHp[i];
			break;
		case E_NORMAL_3:
			m_CNor_3.Update(dt, i, m_fSpeed[i], stHeroDestPos, m_bHit[i]);
			m_pMonster[i] = m_CNor_3.m_pMonster[i];
			m_CNor_3.m_nHp[i] = m_nHp[i];
			break;
		case E_SPITTER:
			m_CSpecial.Update(stHeroPos);
			m_pMonster[i] = m_CSpecial.m_pAni;
			m_CSpecial.m_nHp = m_nHp[i];
		}
	}
	CalcTime();
}

void CMonster::Enable(int nIndex, stEMVec3 stPos)
{
	m_stPos[nIndex].m_fX = CEMMath::RandomFloatInRange(-20.0f, 20.0f);
	m_stPos[nIndex].m_fY = CEMMath::RandomFloatInRange(-20.0f, 20.0f);
	switch (g_CInfo.m_eMonster[nIndex])
	{
	case E_NORMAL_1:
		m_CNor_1.Enable(nIndex, stPos);
		m_fSpeed[nIndex] = m_CNor_1.m_fSpeed;
		m_nHp[nIndex] = m_CNor_1.m_nHp[nIndex] + g_CInfo.m_nMonsterHp;
		break;
	case E_NORMAL_2:
		m_CNor_2.Enable(nIndex, stPos);
		m_fSpeed[nIndex] = m_CNor_2.m_fSpeed;
		m_nHp[nIndex] = m_CNor_2.m_nHp[nIndex] + g_CInfo.m_nMonsterHp;
		break;
	case E_NORMAL_3:
		m_CNor_3.Enable(nIndex, stPos);
		m_fSpeed[nIndex] = m_CNor_3.m_fSpeed;
		m_nHp[nIndex] = m_CNor_3.m_nHp[nIndex] + g_CInfo.m_nMonsterHp;
		break;
	case E_SPITTER:
		m_CSpecial.Enable(stPos);
		m_fSpeed[nIndex] = m_CSpecial.m_fSpeed;
		m_nHp[nIndex] = m_CSpecial.m_nHp+ g_CInfo.m_nMonsterHp;
		break;
	}
}

void CMonster::Disable(int nIndex)
{
	switch (g_CInfo.m_eMonster[nIndex])
	{
	case E_NORMAL_1:
		m_CNor_1.Disable(nIndex);
		break;
	case E_NORMAL_2:
		m_CNor_2.Disable(nIndex);
		break;
	case E_NORMAL_3:
		m_CNor_3.Disable(nIndex);
		break;
	case E_SPITTER:
		m_CSpecial.Disable();
		break;
	}
	m_bHit[nIndex] = false;
	m_nHp[nIndex] = 100;
	m_stPos[nIndex] = NULL;
}

void CMonster::CalcTime()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_pMonster[i]->GetShow())
		{
			if (m_bHit[i])
			{
				m_fTime[i] += D_WORLD->GetDeltaTime();
				if (m_fTime[i] >= 0.3f)
				{
					m_fTime[i] = 0.0f;
					m_bHit[i] = false;
				}
			}
		}
	}
}