#include "stdafx.h"
CNormal_3::CNormal_3()
{
	Init();
}
CNormal_3::~CNormal_3()
{
	Init();
}
void CNormal_3::Init()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_nHp[i] = 50;
		m_nAttack[i] = 25;
	}
	m_fSpeed = 1.3f;
}
void CNormal_3::CreateObj(CRootScene* pScene, int nIndex)
{
	m_pMonster[nIndex] = new CEMAnimation(17);
	m_pMonster[nIndex]->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pMonster[nIndex]->SetBoundingSphereRadius(-5.0f);
	m_pMonster[nIndex]->SetBoundingSphereOffset(0.0f, -7.0f);
	m_pMonster[nIndex]->SetTexture(pScene, 17, "Data/Image/Monster/Gray/0_0.png", "Data/Image/Monster/Gray/0_1.png", "Data/Image/Monster/Gray/0_0.png", "Data/Image/Monster/Gray/0_2.png"
		, "Data/Image/Monster/Gray/1_0.png", "Data/Image/Monster/Gray/1_1.png", "Data/Image/Monster/Gray/1_0.png", "Data/Image/Monster/Gray/1_2.png"
		, "Data/Image/Monster/Gray/2_0.png", "Data/Image/Monster/Gray/2_1.png", "Data/Image/Monster/Gray/2_0.png", "Data/Image/Monster/Gray/2_2.png"
		, "Data/Image/Monster/Gray/3_0.png", "Data/Image/Monster/Gray/3_1.png", "Data/Image/Monster/Gray/3_0.png", "Data/Image/Monster/Gray/3_2.png"
		, "Data/Image/Monster/Gray/1_0.png");
	m_pMonster[nIndex]->SetLoopType(E_ANI_LOOP, 0, 3);
	m_pMonster[nIndex]->SetBoundingSphereOffset(0.0f, 15.0f);
	m_pMonster[nIndex]->SetBoundingBox_LTLB_Size(10.0f);
	m_pMonster[nIndex]->SetBoundingBox_RTRB_Size(-10.0f);
	m_pMonster[nIndex]->SetBoundingBox_LTRT_Size(-20.0f);
	m_pMonster[nIndex]->SetSize(0.2f, 0.2f);
	m_pMonster[nIndex]->SetTime(0.15f);
	m_pMonster[nIndex]->SetBlend(true);
	m_pMonster[nIndex]->SetShow(false);
	m_pMonster[nIndex]->SetBoundingBoxCalc(true);
	m_pMonster[nIndex]->SetMirrorType(E_RIGHT_MIRROR);

	stdEMString stTemp = "Monster3" + IntToEMString(nIndex);
	pScene->Commit(1, stTemp, m_pMonster[nIndex]);
}
void CNormal_3::Update(float dt, int nIndex, float fSpeed, stEMVec3 stHeroPos, bool bHit)
{
	Move(dt, nIndex, fSpeed, stHeroPos, bHit);
}
void CNormal_3::Move(float dt, int nIndex, float fSpeed, stEMVec3 stHeroPos, bool bHit)
{
	if (m_pMonster[nIndex]->GetShow() == true)
	{
		//히어로따라 움직임
		stEMVec3 stCalsPos = m_pMonster[nIndex]->GetPosVec3();
		if (bHit)
		{
			if (m_pMonster[nIndex]->GetColor() == CEMColor(255, 255, 255))
			{
				m_pMonster[nIndex]->SetColor(255, 0, 0);
			}
			stEMVec3 stPos =  stHeroPos - stCalsPos;
			stPos = -stPos;
			stPos.Normalize();
			stPos = stPos * 3.0;
			stCalsPos = CEMMath::Lerp(stCalsPos + stPos, stHeroPos, dt * fSpeed);
		}
		else
		{
			if (m_pMonster[nIndex]->GetColor() == CEMColor(255, 0, 0))
			{
				m_pMonster[nIndex]->SetColor(255, 255, 255, 1);
			}
			stCalsPos = CEMMath::Lerp(stCalsPos, stHeroPos, dt * fSpeed);
		}
		m_pMonster[nIndex]->SetPos(stCalsPos);
		See(stHeroPos, nIndex);
	}
}

void CNormal_3::Enable(int nIndex, stEMVec3 stPos)
{
	if (m_pMonster[nIndex]->GetShow() == false)
	{
		m_pMonster[nIndex]->SetShow(true);
		m_pMonster[nIndex]->SetPos(stPos);
	}
}

void CNormal_3::Disable(int nIndex)
{
	if (m_pMonster[nIndex]->GetShow() == true)
	{
		m_pMonster[nIndex]->SetShow(false);
		m_pMonster[nIndex]->SetPos(-1000.0f, -1000.0f, 0.0f);
	}
}

void CNormal_3::See(stEMVec3 stPos, int nIndex)
{
	m_stDestPos = stEMVec3(stPos.m_fX, stPos.m_fY, 0.0f);

	// 방향벡터 = 목적지 벡터 - 주인공 벡터
	m_stHeroPosToDestPosDir = m_stDestPos - m_pMonster[nIndex]->GetPosVec3();

	// 단위벡터로 변경
	m_stHeroPosToDestPosDir.Normalize();
	m_stHeroDirVec3.Normalize();

	// 주인공의 우향? 벡터 구하기
	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));
	float fDotProduct = stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir);			//양 옆 구분 내적

	stEMVec3 stCross = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));			//외적 
	stEMVec3 stTemp(stCross.m_fY, stCross.m_fX, stCross.m_fZ);		//X축 Y축 바꿈
	float fUpDot = stEMVec3::Dot(stTemp, m_stHeroPosToDestPosDir);		//위 아래 구분 내적
	//Dprintf("Down : %f    UP : %f\n", fDotProduct, fUpDot);

	if (fDotProduct > 0.5f)		//오른쪽
	{
		if (m_pMonster[nIndex]->GetCurFrameNumber() < 4 || m_pMonster[nIndex]->GetCurFrameNumber() > 7)
		{
			m_pMonster[nIndex]->SetLoopType(E_ANI_LOOP, 4, 7);
		}
	}
	else
	{
		if (fDotProduct < -0.5f)		//왼쪽
		{
			if (m_pMonster[nIndex]->GetCurFrameNumber() < 8 || m_pMonster[nIndex]->GetCurFrameNumber() > 11)
			{
				m_pMonster[nIndex]->SetLoopType(E_ANI_LOOP, 8, 11);
			}
		}
		else
		{
			if (fUpDot < -0.5f)		//위
			{
				if (m_pMonster[nIndex]->GetCurFrameNumber() < 12 || m_pMonster[nIndex]->GetCurFrameNumber() > 15)
				{
					m_pMonster[nIndex]->SetLoopType(E_ANI_LOOP, 12, 15);
				}
			}
			else
			{
				if (fUpDot > 0.5f)			//아래
				{
					if (m_pMonster[nIndex]->GetCurFrameNumber() > 3)
					{
						m_pMonster[nIndex]->SetLoopType(E_ANI_LOOP, 0, 3);
					}
				}
			}
		}
	}
}