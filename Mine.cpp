#include "stdafx.h"
void CMine::Init()
{
	m_Explosionsnd = NULL;
	m_Soundsnd = NULL;
}
void CMine::CreateObj(CRootScene* pScene)
{
	m_pAni = new CEMAnimation(8);
	m_pAni->SetTexture(pScene, 8, "Data/Image/Effect/Effect/Mine.png", "Data/Image/Effect/Effect/Mine_2.png", "Data/Image/Effect/Effect/0.png", "Data/Image/Effect/Effect/1.png"
		, "Data/Image/Effect/Effect/2.png", "Data/Image/Effect/Effect/3.png", "Data/Image/Effect/Effect/4.png", "Data/Image/Effect/Effect/5.png");
	m_pAni->SetSize(0.2f);
	m_pAni->SetLoopType(E_ANI_LOOP, 0, 1);
	m_pAni->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pAni->SetShow(false);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetBlend(true);
	m_pAni->SetTime(0.2f);
	m_pAni->SetBoundingSphereRadius(-13.0f);

	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Mine_Throw.mp3");
	m_Explosionsnd = D_SOUND->FileOpen("Data/Sound/Mine_Explosion.mp3");

	pScene->Commit(3, "Mine", m_pAni);
}
void CMine::Update()
{
	if (m_pAni->GetShow())
	{
		if (m_pAni->GetCurFrameNumber() >= 6)
		{
			Disable();
		}
	}
}
void CMine::Enable(stEMVec3 stPos)
{
	m_pAni->SetPos(stPos);
	m_pAni->SetShow(true);
	m_pAni->SetLoopType(E_ANI_LOOP, 0, 1);
	m_pAni->SetBoundingSphereRadius(-13.0f);
	m_pAni->SetTime(0.2f);
	D_SOUND->Play(m_Soundsnd, D_MNG->GetSoundVolume());
}
void CMine::Disable()
{
	m_pAni->SetPos(-1000.0f, -1000.0f, 0.0f);
	m_pAni->SetShow(false);
}