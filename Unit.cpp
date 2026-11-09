#include "stdafx.h"
CUnit::CUnit()
{
	Init();
}
CUnit::~CUnit()
{
	Init();
}
void CUnit::Init()
{
	m_bHit = false;
	m_bUse = false;
	m_fDuration = 0.0f;
	m_fSkillTime = 0.0f;
	m_nAmount = 5;
	m_nAttack = 100;
	m_fSpeed = 150.0f;
	m_Soundsnd = NULL;
	m_pAni = NULL;
	m_pPlane = NULL;

	m_stDestPos = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
	m_stHeroPosToDestPosDir = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroRightVec3 = stEMVec3(0.0f, 1.0f, 0.0f);

	m_fDegree = 0.0f;
	m_fDot = 0.0f;
	m_fRadian = 0.0f;
}
void CUnit::CreateObj(CRootScene* pScene)
{

}
void CUnit::Update(float dt)
{

}
void CUnit::Clipping()
{

}
void CUnit::Enable(stEMVec3 stPos, int nIndex)
{
	
}
void CUnit::Disable(int nIndex)
{
	
}
void CUnit::Move(float dt)
{

}

void CUnit::See(stMouseInfo stPos)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	// 마우스 좌표를 월드 좌표로 변환합니다.^^
	stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

	m_stDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

	// 방향벡터 = 목적지 벡터 - 주인공 벡터
	m_stHeroPosToDestPosDir = m_stDestPos - m_pAni->GetPosVec3();

	// 단위벡터로 변경
	m_stHeroPosToDestPosDir.Normalize();
	m_stHeroDirVec3.Normalize();

	// 주인공의 우향? 벡터 구하기
	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));
	float fDotProduct  = stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir);			//양 옆 구분 내적

	stEMVec3 stCross = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));			//외적 
	stEMVec3 stTemp(stCross.m_fY, stCross.m_fX, stCross.m_fZ);		//X축 Y축 바꿈
	float fUpDot = stEMVec3::Dot(stTemp, m_stHeroPosToDestPosDir);		//위 아래 구분 내적

	if (m_bMoveAni)
	{
		if (fDotProduct > 0.5f)		//오른쪽
		{
			if (m_pAni->GetCurFrameNumber() < 4 || m_pAni->GetCurFrameNumber() > 7 || m_pAni->GetMirrorType() == E_LEFT_MIRROR)
			{
				m_pAni->SetLoopType(E_ANI_LOOP, 4, 7);
				m_pAni->SetMirrorType(E_RIGHT_MIRROR);
			}
		}
		else
		{
			if (fDotProduct < -0.5f)		//왼쪽
			{
				if (m_pAni->GetCurFrameNumber() < 4 || m_pAni->GetCurFrameNumber() > 7 || m_pAni->GetMirrorType() == E_RIGHT_MIRROR)
				{
					m_pAni->SetLoopType(E_ANI_LOOP, 4, 7);
					m_pAni->SetMirrorType(E_LEFT_MIRROR);
				}
			}
			else
			{
				if (fUpDot < -0.5f)		//위
				{
					if (m_pAni->GetCurFrameNumber() < 8 || m_pAni->GetCurFrameNumber() > 11)
					{
						m_pAni->SetLoopType(E_ANI_LOOP, 8, 11);
					}
				}
				else
				{
					if (fUpDot > 0.5f)			//아래
					{
						if (m_pAni->GetCurFrameNumber() > 3)
						{
							m_pAni->SetLoopType(E_ANI_LOOP, 0, 3);
						}
					}
				}
			}
		}
	}
	else
	{
		if (fDotProduct > 0.5f)		//오른쪽
		{
			if (m_pAni->GetCurFrameNumber() < 4 || m_pAni->GetCurFrameNumber() > 4 || m_pAni->GetMirrorType() == E_LEFT_MIRROR)
			{
				m_pAni->SetLoopType(E_ANI_LOOP, 4, 4);
				m_pAni->SetMirrorType(E_RIGHT_MIRROR);
			}
		}
		else
		{
			if (fDotProduct < -0.5f)		//왼쪽
			{
				if (m_pAni->GetCurFrameNumber() < 4 || m_pAni->GetCurFrameNumber() > 4 || m_pAni->GetMirrorType() == E_RIGHT_MIRROR)
				{
					m_pAni->SetLoopType(E_ANI_LOOP, 4, 4);
					m_pAni->SetMirrorType(E_LEFT_MIRROR);
				}
			}
			else
			{
				if (fUpDot < -0.5f)		//위
				{
					if (m_pAni->GetCurFrameNumber() < 8 || m_pAni->GetCurFrameNumber() > 8)
					{
						m_pAni->SetLoopType(E_ANI_LOOP, 8, 8);
					}
				}
				else
				{
					if (fUpDot > 0.5f)			//아래
					{
						if (m_pAni->GetCurFrameNumber() > 0)
						{
							m_pAni->SetLoopType(E_ANI_LOOP, 0, 0);
						}
					}
				}
			}
		}
	}
}

void CUnit::Ability()
{

}

void CUnit::MoveAnimation()
{
	if (D_INPUT->IsKeyDown(VK_W) || D_INPUT->IsKeyDown(VK_A) || D_INPUT->IsKeyDown(VK_S) || D_INPUT->IsKeyDown(VK_D))
	{
		if(!m_bMoveAni)
		{
			m_bMoveAni = true;
			HeroAnimation();
		}
	}
	if ((D_INPUT->GetKeyState(VK_W) == E_KEY_DONTTOUCH || D_INPUT->GetKeyState(VK_W) == E_KEY_UP )&&
		(D_INPUT->GetKeyState(VK_A) == E_KEY_DONTTOUCH || D_INPUT->GetKeyState(VK_A) == E_KEY_UP) &&
		(D_INPUT->GetKeyState(VK_S) == E_KEY_DONTTOUCH || D_INPUT->GetKeyState(VK_S) == E_KEY_UP) &&
		(D_INPUT->GetKeyState(VK_D) == E_KEY_DONTTOUCH || D_INPUT->GetKeyState(VK_D) == E_KEY_UP))
	{
		if (m_bMoveAni)
		{
			m_bMoveAni = false;
		}
		StopHeroAnimation();
	}
}

void CUnit::HeroAnimation()
{
	if (m_pAni->GetCurFrameNumber() == 4 && m_pAni->GetMirrorType() == E_RIGHT_MIRROR)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 4, 7);
		m_pAni->SetMirrorType(E_RIGHT_MIRROR);
	}
	if (m_pAni->GetCurFrameNumber() == 4 && m_pAni->GetMirrorType() == E_LEFT_MIRROR)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 4, 7);
		m_pAni->SetMirrorType(E_LEFT_MIRROR);
	}
	if (m_pAni->GetCurFrameNumber() == 8)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 8, 11);
	}
	if (m_pAni->GetCurFrameNumber() == 0)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 0, 3);
	}
}

void CUnit::StopHeroAnimation()
{
	if (m_pAni->GetCurFrameNumber() > 4 && m_pAni->GetCurFrameNumber() <= 7 && m_pAni->GetMirrorType() == E_RIGHT_MIRROR)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 4, 4);
		m_pAni->SetMirrorType(E_RIGHT_MIRROR);
	}
	if (m_pAni->GetCurFrameNumber() > 4 && m_pAni->GetCurFrameNumber() <= 7 && m_pAni->GetMirrorType() == E_LEFT_MIRROR)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 4, 4);
		m_pAni->SetMirrorType(E_LEFT_MIRROR);
	}
	if (m_pAni->GetCurFrameNumber() > 8 && m_pAni->GetCurFrameNumber() <= 11)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 8, 8);
	}
	if (m_pAni->GetCurFrameNumber() > 0 && m_pAni->GetCurFrameNumber() <= 3)
	{
		m_pAni->SetLoopType(E_ANI_LOOP, 0, 0);
	}
}