#include "stdafx.h"
CGrenade::CGrenade()
{
	Init();
}
CGrenade::~CGrenade()
{
	Init();
}
void CGrenade::Init()
{
	m_stClickDestPos = NULL;

	m_fSpeed = 100.0f;
	m_Soundsnd = NULL;
	m_Explosionsnd = NULL;
}
void CGrenade::CreateObj(CRootScene* pScene)
{
	//수류탄
	m_pMissile = new CEMAnimation(10);
	m_pMissile->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pMissile->SetTexture(pScene, 10,"Data/Image/Hero/Soldier/Grenade/0.png", "Data/Image/Hero/Soldier/Grenade/1.png", "Data/Image/Hero/Soldier/Grenade/2.png"
		, "Data/Image/Hero/Soldier/Grenade/3.png", "Data/Image/Hero/Soldier/Grenade/4.png", "Data/Image/Hero/Soldier/Grenade/5.png", "Data/Image/Hero/Soldier/Grenade/6.png"
		, "Data/Image/Hero/Soldier/Grenade/7.png", "Data/Image/Hero/Soldier/Grenade/8.png", "Data/Image/Hero/Soldier/Grenade/9.png");
	m_pMissile->SetSize(0.05f);
	m_pMissile->SetTime(0.1f);
	m_pMissile->SetBlend(true);
	m_pMissile->SetBackFaceCulling(true);
	m_pMissile->SetShow(false);
	m_pMissile->SetFrstumCullingFlag(false);
	m_pMissile->SetZRot(-90.0f);

	pScene->Commit(5, "Greanade", m_pMissile);

	//이펙트
	m_pAni = new CEMAnimation(20);
	m_pAni->SetTexture(pScene, 20, "Data/Image/Effect/Explosion/Target.png", "Data/Image/Effect/Explosion/0.png", "Data/Image/Effect/Explosion/1.png", "Data/Image/Effect/Explosion/2.png"
		, "Data/Image/Effect/Explosion/3.png", "Data/Image/Effect/Explosion/4.png", "Data/Image/Effect/Explosion/5.png", "Data/Image/Effect/Explosion/6.png"
		, "Data/Image/Effect/Explosion/7.png", "Data/Image/Effect/Explosion/8.png", "Data/Image/Effect/Explosion/9.png", "Data/Image/Effect/Explosion/10.png"
		, "Data/Image/Effect/Explosion/11.png", "Data/Image/Effect/Explosion/12.png", "Data/Image/Effect/Explosion/13.png", "Data/Image/Effect/Explosion/14.png"
		, "Data/Image/Effect/Explosion/15.png", "Data/Image/Effect/Explosion/16.png", "Data/Image/Effect/Explosion/17.png", "Data/Image/Effect/Explosion/18.png");
	m_pAni->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pAni->SetShow(false);
	m_pAni->SetBlend(true);
	m_pAni->SetBlendFunc(GL_ONE, GL_ONE);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);
	m_pAni->SetTime(0.1f);
	m_pAni->SetSize(0.4f);
	m_pAni->SetBoundingSphereRadius(-10.0f);
	m_pAni->SetBoundingSphereOffset(0.0f, - 1.0f);
	pScene->Commit(6, "Explosion", m_pAni);

	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Throw_2.mp3");
	m_Explosionsnd = D_SOUND->FileOpen("Data/Sound/Explosion.mp3");
}
void CGrenade::Update(float dt)
{
	Move(dt);
	Clipping();
}
void CGrenade::Move(float dt)
{
	if (m_pMissile->GetShow() == true)
	{
		// 목직지 방향으로 총알 이동
		stEMVec3 stCalsPos = m_pMissile->GetPosVec3();
		stCalsPos = CEMMath::Lerp(stCalsPos, m_stClickDestPos, dt * 5.0f);
		m_pMissile->SetPos(stCalsPos);
	}
}
void CGrenade::Clipping()
{
	/*오차 범위 ±30.0f
		---------------------
		l							l
		l							l	
		l							l
		---------------------
	*/
	if (m_pMissile->GetShow() == true)
	{
		if (m_pMissile->GetPosVec3().m_fX <= m_stClickDestPos.m_fX + 30.0f && m_pMissile->GetPosVec3().m_fX	>=m_stClickDestPos.m_fX - 30.0f)
		{
			if (m_pMissile->GetPosVec3().m_fY <= m_stClickDestPos.m_fY + 30.0f && m_pMissile->GetPosVec3().m_fY >= m_stClickDestPos.m_fY -30.0f)
			{
				Disable();
			}
		}
	}
}

void CGrenade::Enable(stEMVec3 stPos, stEMVec3 stClickPos)
{
	D_SOUND->Play(m_Soundsnd, D_MNG->GetSoundVolume());
	m_stClickDestPos = stClickPos;
	m_pMissile->SetShow(true);
	m_pMissile->SetPos(50.0f, 50.0f, 0.0f);
}

void CGrenade::Disable()
{
	m_stClickDestPos = NULL;
	m_pMissile->SetShow(false);
	m_pMissile->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pAni->SetLoopType(E_ANI_ONE, 1,E_ANI_ENDING_TYPE_SHOW_FALSE);
	D_SOUND->Play(m_Explosionsnd, D_MNG->GetSoundVolume());
}
