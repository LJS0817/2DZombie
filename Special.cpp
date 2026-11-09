#include "stdafx.h"
void CSpecial::Init()
{
	m_fSkillTime = 0.0f;

	m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
	m_stHeroPosToDestPosDir = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroRightVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
	m_stDestination = stEMVec3(0.0f, 0.0f, 0.0f);

	m_fDegree = 0.0f;
	m_fDot = 0.0f;
	m_fRadian = 0.0f;

	m_fSpeed = 1.5f;
	m_fTime = 4.0f;

	m_nHp = 100;
}
void CSpecial::CreateObj(CRootScene* pScene)
{
	m_pAni = new CEMAnimation(9);
	m_pAni->SetTexture(pScene, 9, "Data/Image/Monster/Black/0.png", "Data/Image/Monster/Black/1.png", "Data/Image/Monster/Black/2.png"
		, "Data/Image/Monster/Black/3.png", "Data/Image/Monster/Black/4.png", "Data/Image/Monster/Black/5.png", "Data/Image/Monster/Black/6.png"
		, "Data/Image/Monster/Black/7.png", "Data/Image/Monster/Black/0.png");
	m_pAni->SetBlend(true);
	m_pAni->SetPos(150.0f, -100.0f, 0.0f);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);
	m_pAni->SetShow(false);
	m_pAni->SetTime(0.12f);
	m_pAni->SetSize(0.3f);
	m_pAni->SetBoundingSphereRadius(-25.0f);
	m_pAni->SetBoundingBox_LTLB_Size(25.0f);
	m_pAni->SetBoundingBox_RTRB_Size(-15.0f);
	m_pAni->SetBoundingBox_LTRT_Size(-6.0f);
	m_pAni->SetBoundingBox_LBRB_Size(6.0f);
	//m_pAni->SetLoopType(E_ANI_ONE, 0, 8, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);

	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture("Data/Image/Monster/Spit.png");
	m_pPlane->SetBlend(true);
	m_pPlane->SetShow(false);
	m_pPlane->SetSize(0.3f);
	m_pPlane->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pPlane->SetBoundingBoxCalc(true);
	m_pPlane->SetBoundingBox_LTLB_Size(-5.0f);
	m_pPlane->SetBoundingBox_RTRB_Size(5.0f);
	m_pPlane->SetBoundingBox_LTRT_Size(-10.0f);
	m_pPlane->SetBoundingBox_LBRB_Size(10.0f);

	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Spit.mp3");

	pScene->Commit(1, "Black_Zombie", m_pAni);
	pScene->Commit(1, "Black_ZombieBullet", m_pPlane);
}
void CSpecial::Update(stEMVec3 stPos)
{
	if (m_pAni->GetShow())
	{
		if (!m_pPlane->GetShow())
			CreateBullet(stPos);
		else
		{
			m_pPlane->Move(m_fSpeed, m_stDestination);
			if (!D_FRUSTUM->PointInFrustum(m_pPlane->GetPosVec3(), -50.0f))
			{
				BulletDisable();
			}
		}
	}
}
void CSpecial::Enable(stEMVec3 stPos)
{
	m_pAni->SetPos(stPos);
	m_pAni->SetShow(true);
	m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
}
void CSpecial::Disable()
{
	m_pAni->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pAni->SetShow(false);
	BulletDisable();
}
void CSpecial::CreateBullet(stEMVec3 stPos)
{
	m_fSkillTime += D_WORLD->GetDeltaTime();
	if (m_fSkillTime >= m_fTime)
	{
		m_fSkillTime = 0.0f;
		m_pAni->SetLoopType(E_ANI_ONE, 1, 7, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	}
	if (m_pAni->GetCurFrameNumber() == 5)
	{
		m_pPlane->SetShow(true);
		m_pPlane->SetPos(m_pAni->GetPosVec3());

		m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);

		if (!D_SOUND->IsPlaying(m_Soundsnd))
			D_SOUND->Play(m_Soundsnd, D_MNG->GetSoundVolume());
		See(stPos);
	}
}

void CSpecial::See(stEMVec3 stPos)
{
	// 방향벡터 = 목적지 벡터 - 주인공 벡터
	m_stHeroPosToDestPosDir = stPos - m_pPlane->GetPosVec3();

	m_stDestination = m_stHeroPosToDestPosDir;

	// 단위벡터로 변경
	m_stHeroPosToDestPosDir.Normalize();
	m_stHeroDirVec3.Normalize();

	// 내적 계산
	m_fDot = stEMVec3::Dot(m_stHeroDirVec3, m_stHeroPosToDestPosDir);

	// 각도 구하기^^
	m_fRadian = (float)acos(m_fDot);

	// 업벡터 구하기
	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));

	if (stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir) > 0.0f)
	{
		m_fDegree = CEMMath::ToDegrees(m_fRadian);
	}
	else
	{
		m_fDegree = CEMMath::ToDegrees(-m_fRadian);
	}
	m_pPlane->SetZRot(m_fDegree);
}

void CSpecial::BulletDisable()
{
	m_pPlane->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pPlane->SetShow(false);
}