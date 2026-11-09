#include "stdafx.h"
CBullet::CBullet()
{
	Init();
}
CBullet::~CBullet()
{
	Init();
}
void CBullet::Init()
{
	m_fReload = 0.0f;
	m_nBullet = D_LIMITBULLET_MAX;
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_pBullet[i] = NULL;
		m_stClickDestPos[i] = NULL;
	}
	m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
	m_stHeroPosToDestPosDir = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroRightVec3 = stEMVec3(0.0f, 1.0f, 0.0f);

	m_fDegree = 0.0f;
	m_fDot = 0.0f;
	m_fRadian = 0.0f;

	m_bReload = false;
	m_fSpeed = 100.0f;
	m_Bulletsnd = NULL;
}
void CBullet::CreateObj(CRootScene* pScene)
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_pBullet[i] = new CEMAnimation(4);
		m_pBullet[i]->SetPos(
			000.0f, -1000.0f, 0.0f);
		m_pBullet[i]->SetTexture(pScene, 4, "Data/Image/Bullet/0.png", "Data/Image/Bullet/2.png", "Data/Image/Bullet/1.png", "Data/Image/Bullet/2.png");
		m_pBullet[i]->SetLoopType(E_ANI_LOOP, g_CInfo.m_eHero, g_CInfo.m_eHero, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pBullet[i]->SetSize(0.3f);
		m_pBullet[i]->SetBlend(true);
		m_pBullet[i]->SetBackFaceCulling(true);
		m_pBullet[i]->SetShow(false);
		m_pBullet[i]->SetBoundingBoxCalc(true);
		m_pBullet[i]->SetFrstumCullingFlag(false);

		stdEMString stTemp = "Bullet" + IntToEMString(i);
		pScene->Commit(2, stTemp, m_pBullet[i]);
	}
	m_pBulletNum = new CEMNumber(11);
	m_pBulletNum->SetTexture(pScene, 11, "Data/Image/ui/Num/0.png", "Data/Image/ui/Num/1.png"
		, "Data/Image/ui/Num/2.png", "Data/Image/ui/Num/3.png", "Data/Image/ui/Num/4.png"
		, "Data/Image/ui/Num/5.png", "Data/Image/ui/Num/6.png", "Data/Image/ui/Num/7.png"
		, "Data/Image/ui/Num/8.png", "Data/Image/ui/Num/9.png", "Data/Image/ui/Num/10.png");
	m_pBulletNum->SetPos(D_CAMERA->GetPosVec2().m_fX - 60.0f, D_CAMERA->GetPosVec2().m_fY + 125.0f, 0.0f);
	m_pBulletNum->SetNumber(m_nBullet);
	m_pBulletNum->SetBlend(true);
	m_pBulletNum->SetBoundingBoxCalc(true);
	m_pBulletNum->SetSize(0.14f);

	m_CMagazine.CreateObj(pScene);
	pScene->Commit(-10, "B_LimitBullet", m_pBulletNum);
	m_Bulletsnd = D_SOUND->FileOpen("Data/Sound/Gun.mp3");
	m_Soundsnd = D_SOUND->FileOpen("Data/Sound/Reload.mp3");
}
void CBullet::Update(float dt, stEMVec3 stPos)
{
	Move(dt);
	Clipping();
	ReloadBullet(stPos);
	m_CMagazine.Update(dt);
}
void CBullet::Move(float dt)
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_pBullet[i]->GetShow() == true)
		{
			// 목직지 방향으로 총알 이동
			m_pBullet[i]->Move(0.5f, m_stClickDestPos[i]);
		}
	}
}
void CBullet::Clipping()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		// 화면을 벗어나는거 체크^^
		if (m_pBullet[i]->GetShow() == true)
		{
			if (!D_FRUSTUM->PointInFrustum(m_pBullet[i]->GetPosVec3(), -50.0f))
			{
				Disable(i);
			}
		}
	}
}

void CBullet::Enable(int nIndex, stEMVec3 stPos)
{
	m_pBullet[nIndex]->SetShow(true);
	m_nBullet -= 1;
	m_pBullet[nIndex]->SetPos(stPos.m_fX, stPos.m_fY + 3.0f, stPos.m_fZ);
	See(nIndex);
}

void CBullet::Disable(int nIndex)
{
	m_pBullet[nIndex]->SetShow(false);
	m_pBullet[nIndex]->SetPos(-1000.0f, -1000.0f, 0.0f);
}

void CBullet::ReloadBullet(stEMVec3 stPos)
{
	m_pBulletNum->SetPos(D_CAMERA->GetPosVec2().m_fX - 60.0f, D_CAMERA->GetPosVec2().m_fY - 125.0f, 0.0f);

	m_pBulletNum->SetNumber(m_nBullet);
	if (m_bReload == false)
	{
		if (m_nBullet <= 0)
		{
			m_bReload = true;
			D_SOUND->Play(m_Soundsnd, D_MNG->GetSoundVolume());
		}
		else
		{
			if (D_INPUT->IsKeyDown(VK_R))
			{
				if (m_nBullet < D_LIMITBULLET_MAX)
				{
					D_SOUND->Play(m_Soundsnd, D_MNG->GetSoundVolume());
					m_bReload = true;
				}
			}
		}
	}
	else
	{
		m_fReload += D_WORLD->GetDeltaTime();
		if (m_fReload >= 2.0f)
		{
			CreateMagazine(stPos);
			m_fReload = 0.0f;
			m_bReload = false;
			m_nBullet = D_LIMITBULLET_MAX;
		}
	}
}

void CBullet::CreateMagazine(stEMVec3 stPos)
{
	if (m_CMagazine.m_pMagazine->GetShow() == false)
	{
		m_CMagazine.Enable(stPos);
	}
}

void CBullet::See(int nIndex)
{
	// 방향벡터 = 목적지 벡터 - 주인공 벡터
	m_stHeroPosToDestPosDir = m_stClickDestPos[nIndex] - m_pBullet[nIndex]->GetPosVec3();

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
	m_pBullet[nIndex]->SetZRot(m_fDegree);
}