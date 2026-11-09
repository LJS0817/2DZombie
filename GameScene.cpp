#include "stdafx.h"

void CGameScene::Init()
{
	//========================
	m_CHero.Init();
	m_CIntro.Init();	
	m_CBullet.Init();
	m_CMonster.Init();
	m_CGun.Init();
	m_CEffect.Init();
	m_CBlood.Init();
	m_CUI.Init();
	m_CMap.Init();
	m_CMine.Init();
	//========================
	m_eChar = g_CInfo.m_eHero;

	m_sndHeartBeat_1 = NULL;
	m_sndHeartBeat_2 = NULL;

	m_fMonCtrlTime = 0.0f;
	m_fBulletTime = 0.0f;
	m_fRestTime = 0.0f;
	m_fColisionTime = 0.0f;
	m_fShakeCtrlTime = 0.0f;
	m_fBossTime = 0.0f;
	m_fTime = 0.0f;

	m_bPause = false;
	m_bFire = false;
	m_bChange = false;
	m_bReset = false;
	m_bShake = false;

	m_nGoal = 20;
	m_nCount = 0;
	m_nMonster = 0;
	m_nRange = 70;
}

void CGameScene::Enter(CSceneWork* pSceneWork)
{
	D_CAMERA->SetPos(260.0f, -150.0f, 260.0f);
	m_eChar = g_CInfo.m_eHero;
	g_CInfo.Spawn();
	g_CInfo.NumInit();

	m_sndChange = D_SOUND->FileOpen("Data/Sound/ChangeDay.mp3");
	m_sndHeartBeat_1 = D_SOUND->FileOpen("Data/Sound/Heart_1.mp3");
	m_sndHeartBeat_2 = D_SOUND->FileOpen("Data/Sound/Heart_2.mp3");

	m_CPausePopupWin.CreatePopupWindow(D_MNG->m_ClickSnd, -15, this, false);
	m_CExitPopupWin.CreatePopupWindow(D_MNG->m_ClickSnd, -16, this, false);
	m_CSettingPopupWin.CreatePopupWindow(D_MNG->m_ClickSnd, -17, this, false);

	m_CShadow.CreateObj(this);
	m_CEffect.CreateObj(this);
	m_CBlood.CreateObj(this);
	//===================
	m_CIntro.CreateObj(this);
	if (g_CInfo.m_bMode)
	{
		D_SOUND->Play(m_CIntro.m_Soundsnd, D_MNG->GetSoundVolume());
		m_sndClear = D_SOUND->FileOpen("Data/Sound/Clear.mp3");
	}
	m_CUI.CreateObj(this);
	m_CMap.CreateObj(this);
	g_CInfo.Num(this);
	//===================
	m_CBullet.CreateObj(this);
	m_CMine.CreateObj(this);
	m_CHero.CreateObj(this, m_eChar);
	m_CMonster.CreateObj(this);
	switch (m_eChar)
	{
	case E_BUSINESSMAN:
		m_CGun.CreateObj(this, 0);
		break;
	case E_DOCTOR:
		m_CGun.CreateObj(this, 2);
		break;
	case E_SOLDIER:
		m_CGun.CreateObj(this, 4);
		break;
	}
}

void CGameScene::Update(CSceneWork* pSceneWork, float dt)
{
	if (m_CIntro.m_bUse)
	{
		if (g_CInfo.m_bMode)
		{
			m_CIntro.Update();
		}
		else
		{
			m_CIntro.MapUpdate();
		}
	}
	else
	{
		if (m_bPause == false)
		{
			if (!g_CInfo.m_bMode)
			{
				Challenge(dt);
			}
			else
			{
				Story(dt);
			}
		}
		else
		{
			m_CSettingPopupWin.ESC();
			m_CExitPopupWin.ESC();
		}
	}
	CRootScene::Update(pSceneWork, dt);
}

void CGameScene::Render(CSceneWork* pSceneWork)
{

	CRootScene::Render(pSceneWork);
}

void CGameScene::Exit(CSceneWork* pSceneWork)
{
	Init();
	Destroy();
}

void CGameScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	switch (eButton)
	{
	case E_MOUSE_LEFT:
		if (m_bFire == false)
		{
			m_bFire = true;
		}
		break;
	case E_MOUSE_RIGHT:
		break;
	}
}

void CGameScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	m_CPausePopupWin.OnMouseUpEvent(stPos, eButton);
	m_CExitPopupWin.OnMouseUpEvent(stPos, eButton);
	m_CSettingPopupWin.OnMouseUpEvent(stPos, eButton);
	switch (eButton)
	{
	case E_MOUSE_LEFT:
		if (m_bFire == true)
		{
			m_bFire = false;
		}
		break;
	case E_MOUSE_RIGHT:
		break;
	}
}

void CGameScene::MouseMoveEvent(stMouseInfo stPos)
{
	m_CPausePopupWin.OnMouseMoveEvent(stPos);
	m_CExitPopupWin.OnMouseMoveEvent(stPos);
	m_CSettingPopupWin.OnMouseMoveEvent(stPos);
	if (m_bPause == false)
	{
		m_CHero.See(stPos, m_eChar);
		m_CGun.See(stPos, m_CHero.m_pAni->GetPosVec3());
	}
}

HRESULT CGameScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN:
	{
		int x = 0;
	}break;
	}
	return msg;
}

void CGameScene::CameraShake()
{
	stEMVec3 stCPos = D_CAMERA->GetPosVec3();
	if (m_bShake || m_eChar==E_SOLDIER && m_CHero.m_CSoldier.m_CGrenade.m_pAni->GetShow() && m_CHero.m_CSoldier.m_CGrenade.m_pAni->GetCurFrameNumber() != 0)
	{
		m_fShakeCtrlTime += D_WORLD->GetDeltaTime();
		m_fTime += D_WORLD->GetDeltaTime();
		if (m_fShakeCtrlTime > 0.01f)
		{
			m_fShakeCtrlTime = 0.0f;

			m_stDestPos.m_fX = stCPos.m_fX + CEMMath::RandomFloatInRange(-3, 3);
			m_stDestPos.m_fY = stCPos.m_fY + CEMMath::RandomFloatInRange(-3, 3);
			stCPos = CEMMath::Lerp(stCPos, m_stDestPos, 30.0f*D_WORLD->GetDeltaTime());

			D_CAMERA->SetPos(stCPos.m_fX, stCPos.m_fY, D_CAMERA->GetPosVec3().m_fZ);
		}
		if (m_fTime >= 0.3f)
		{
			m_fTime = 0.0f;
			m_bShake = false;
		}
	}
}

void CGameScene::BigSizeMonster()
{
	if (m_CUI.m_nDate % 5 == 0)
	{
		if (m_CMonster.m_pMonster[0]->GetShow() == true)
		{
			if (m_CMonster.m_pMonster[0]->GetSize() == 0.2f)
			{
				m_CMonster.m_pMonster[0]->SetSize(0.6f);
				m_CMonster.m_fSpeed[0] = 0.3f;
				m_CMonster.m_nHp[0] = m_CUI.m_nDate * 500;
			}
		}
	}
}

void CGameScene::Pause()
{
	if (D_INPUT->IsKeyUp(VK_ESCAPE))
	{
		m_bPause = true;
		m_CPausePopupWin.SetShow(true);
		SoundStop();
	}
}

void CGameScene::BreakTime()
{
	if (m_bReset == true)
	{
		if (m_CUI.m_nTime > 0)
		{
			m_CUI.m_bStart = false;
			m_fRestTime += D_WORLD->GetDeltaTime();
			if (m_fRestTime >= 1.0f)
			{
				m_fRestTime = 0.0f;
				m_CUI.m_nTime -= 1;
			}
		}
		else
		{
			m_nCount = 0;
			m_nMonster = 0;
			m_nGoal += 10;
			m_CUI.m_nMine += 1;
			if (g_CInfo.m_nHp < 5)
			{
				if (m_eChar != E_DOCTOR)
				{
					g_CInfo.m_nHp += 1;
				}
			}
			m_CUI.m_nDate += 1;
			m_bReset = false;
			LightSize();
		}
	}
	else
	{
		if (m_CUI.m_pDate->GetShow() == true)
		{
			if (m_CMap.m_pLight->GetShow() == false)
			{
				m_CMap.m_pLight->SetShow(true);
			}
			m_CUI.DayAlphaUpdate();
			if (m_CUI.m_bStart)
			{
				D_SOUND->Play(m_sndChange, D_MNG->GetSoundVolume());
			}
			m_CUI.m_nTime = 5;
		}
	}
}

void CGameScene::HeroInfoUpdate(float dt)
{
	m_CUI.m_nSkillTime = m_CHero.m_nSkillTime;
	m_CUI.m_nSkill = m_CHero.m_nSkill;
	m_CMonster.Update(dt, m_CHero.m_pAni->GetPosVec3());
	m_CGun.Update(dt, m_CHero.m_pAni->GetPosVec3());
	m_CMap.m_pLight->SetPos(m_CHero.m_pAni->GetPosVec3());
	ShadowUpdate();
	m_CShadow.Update(m_CHero.m_pAni, 44);
	stEMVec2 stCameraPos = CEMMath::Lerp(D_CAMERA->GetPosVec2(), m_CHero.m_pAni->GetPosVec2(), 3.0f * dt);
	D_CAMERA->SetPos(stCameraPos.m_fX, stCameraPos.m_fY, 260.0f);
}

void CGameScene::Reset()
{
	if (m_CUI.m_nDate % 5 == 0)
	{
		if (m_CMonster.m_nHp[0] <= 0)
		{
			for (int i = 0; i < D_MONSTER_MAX; i++)
			{
				if (m_CMonster.m_pMonster[i]->GetShow())
				{
					CreateEffect(m_CMonster.m_pMonster[i]->GetPosVec3());
					m_CMonster.m_nHp[i] = 100;
					m_CMonster.Disable(i);
					m_CShadow.Disable(i);
				}
			}
			g_CInfo.m_nMonsterHp += 20;
			m_CMonster.m_pMonster[0]->SetSize(0.2f);
			g_CInfo.m_nScore += 1000;
			if (m_CMap.m_pLight->GetShow() == true)
			{
				m_CMap.m_pLight->SetShow(false);
				m_CUI.m_pDate->SetShow(true);
				m_CUI.m_pDay->SetShow(true);
			}
			m_bReset = true;
		}
		else
		{
			if (m_CMap.m_pLight->GetShow() == false)
			{
				m_CMap.m_pLight->SetShow(true);
			}
			m_bReset = false;
		}
	}
	else
	{
		if (m_nCount >= m_nGoal)
		{
			if (m_CMap.m_pLight->GetShow() == true)
			{
				m_CMap.m_pLight->SetShow(false);
				m_CUI.m_pDate->SetShow(true);
				m_CUI.m_pDay->SetShow(true);
			}
			m_bReset = true;
		}
		else
		{
			m_bReset = false;
		}
	}
}

void CGameScene::LightSize()
{
	if (m_CMap.m_fSize > 1.0f)
	{
		m_nRange -= 5;
		m_CMap.m_fSize -= 0.2f;
		m_CMonster.m_CSpecial.m_fTime -= 0.2f;
		m_CMap.m_pLight->SetSize(m_CMap.m_fSize);
	}
}

void CGameScene::End()
{
	if (m_CUI.m_CHp.m_fAlpha > 2.0f)
	{
		SoundStop();
		D_SCENE->ChangeScene("result");
		Init();
	}
}

void CGameScene::CreateBullet()
{
	if (m_CBullet.m_bReload == false)
	{
		if (m_bFire == true)
		{
			if (m_CBullet.m_nBullet > 0)
			{
				stEMVec2 stDesPos(0.0f, 0.0f);
				stMouseInfo stPos(D_INPUT->GetMouseMovePos());

				m_fBulletTime += D_WORLD->GetDeltaTime();
				if (m_fBulletTime >= 0.1f)
				{
					m_fBulletTime = 0.0f;
					for (int i = 0; i < D_BULLET_MAX; i++)
					{
						if (m_CBullet.m_pBullet[i]->GetShow() == false)
						{
							D_SOUND->Play(m_CBullet.m_Bulletsnd, D_MNG->GetSoundVolume());

							// 마우스 좌표를 월드 좌표로 변환합니다.^^
							stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

							m_CBullet.m_stClickDestPos[i] = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);
							m_CBullet.Enable(i, m_CGun.m_pAni->GetPosVec3());

							stEMVec3 stTemp = m_CBullet.m_stClickDestPos[i] - m_CBullet.m_pBullet[i]->GetPosVec3();
							stTemp.Normalize();						
							
							//단위벡터 만드후 길이를 늘려줍니다^^
							stTemp = stTemp * 1000.0f;
							m_CBullet.m_stClickDestPos[i] = stTemp;
							break;
						}
					}
				}
			}
		}
	}
}

void CGameScene::Bullet_VS_MonsterColision()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_CMonster.m_pMonster[i]->GetShow())
		{
			CEMAnimation* pCurAni = NULL;
			CEMAnimation* pColision = NULL;
			pColision = (CEMAnimation*)this->IsCollision(E_BOX_VS_SPHERE, m_CMonster.m_pMonster[i], 2);
			pCurAni = (CEMAnimation*)this->IsCollision(E_SPHERE_VS_SPHERE, m_CMonster.m_pMonster[i], 2);
			if (pCurAni != NULL)
			{
				pCurAni->SetShow(false);
				m_CMonster.m_bHit[i] = true;
				if (m_CMonster.m_nHp[i] > 0)
				{
					m_CBlood.m_stDestPos = m_CHero.m_pAni->GetPosVec3();
					CreateEffect_Hit(m_CMonster.m_pMonster[i]->GetPosVec3());
					m_CMonster.m_nHp[i] -= m_CHero.m_nAttack + 20.0f;
				}
			}
			if (pColision != NULL)
			{
				pColision->SetShow(false);
				m_CMonster.m_bHit[i] = true;
				if (m_CMonster.m_nHp[i] > 0)
				{
					m_CBlood.m_stDestPos = m_CHero.m_pAni->GetPosVec3();
					CreateEffect_Hit(m_CMonster.m_pMonster[i]->GetPosVec3());
					m_CMonster.m_nHp[i] -= m_CHero.m_nAttack;
				}
			}
		}
	}
}

void CGameScene::CreateMonster()
{
	if (m_CUI.m_nDate % 5 == 0)
	{
		m_nMonster = 0;
	}
	if (m_nMonster < m_nGoal)
	{
		m_fMonCtrlTime += D_WORLD->GetDeltaTime();
		if (m_fMonCtrlTime >= 0.5f)
		{
			m_fMonCtrlTime = 0.0f;
			for (int i = 0; i < D_MONSTER_MAX; i++)
			{
				if (m_CMonster.m_pMonster[i]->GetShow() == false)
				{
					m_nMonster += 1;
					int nZombie = CEMMath::RandomIntInRange(0, 100);

					if (m_CMonster.m_CSpecial.m_pAni->GetShow())
						m_nRange = 100;
					else
						m_nRange = 95;

					if (m_CUI.m_nDate % 5 == 0)
						if (i == 0)
							nZombie = 0;

					if (nZombie < m_nRange)
					{
						int nSpawnIndex = CEMMath::RandomIntInRange(0, 4);	//스폰 위치
						g_CInfo.m_eMonster[i] = (eZombie)CEMMath::RandomIntInRange(0, 3);	//몬스터
						m_CMonster.Enable(i, g_CInfo.m_stSpawn[nSpawnIndex]);
					}
					else
					{
						int nSpawnIndex_2 = CEMMath::RandomIntInRange(4, 6);	//스폰 2
						g_CInfo.m_eMonster[i] = E_SPITTER;
						if (nSpawnIndex_2 == 5)
							m_CMonster.m_CSpecial.m_pAni->SetMirrorType(E_RIGHT_MIRROR);
						else
							m_CMonster.m_CSpecial.m_pAni->SetMirrorType(E_LEFT_MIRROR);
						m_CMonster.Enable(i, g_CInfo.m_stSpawn[nSpawnIndex_2]);
					}
					CreateShadow(m_CMonster.m_pMonster[i]->GetPosVec3(), i);
					break;
				}
			}
		}
	}
}

void CGameScene::CreateEffect_Hit(stEMVec3 stPos)
{
	for (int i = 0; i < D_BLOOD_MAX; i++)
	{
		if (!m_CBlood.m_pAni[i]->GetShow())
		{
			m_CBlood.Enable(stPos, i);
			break;
		}
	}
}

void CGameScene::CreateShadow(stEMVec3 stPos, int nIndex)
{
	if (m_CShadow.m_pShadow[nIndex]->GetShow() == false)
	{
		m_CShadow.Enable(stPos, nIndex);
	}
}

void CGameScene::ShadowUpdate()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_CMonster.m_pMonster[i]->GetShow())
		{
			m_CShadow.Update(m_CMonster.m_pMonster[i], i);
		}
	}
}

void CGameScene::CreateEffect(stEMVec3 stPos)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (m_CEffect.m_pEffect[i]->GetShow() == false)
		{
			m_CEffect.Enable(stPos, i);
			break;
		}
	}
}

void CGameScene::Grenade_VS_MonsterColision()
{
	if (m_eChar == E_SOLDIER)
	{
		if (m_CHero.m_CSoldier.m_CGrenade.m_pAni->GetShow() == true)
		{
			for (int i = 0; i < D_MONSTER_MAX; i++)
			{
				if (m_CMonster.m_pMonster[i]->GetShow() == true)
				{
					CEMAnimation* pCurAni = NULL;
					pCurAni = (CEMAnimation*)this->IsCollision(E_SPHERE_VS_SPHERE, m_CMonster.m_pMonster[i], 6);
					if (pCurAni != NULL)
					{
						if (m_CHero.m_CSoldier.m_CGrenade.m_pAni->GetCurFrameNumber() == 1)
						{
							m_CMonster.m_nHp[i] -= 300;
						}
					}
				}
			}
		}
	}
}

void CGameScene::Hero_VS_MonsterColision()
{
	m_fColisionTime += D_WORLD->GetDeltaTime();
	if (m_fColisionTime >= 0.2f)
	{
		m_fColisionTime = 0.0f;
		CEMAnimation* pCurAni = NULL;
		pCurAni = (CEMAnimation*)this->IsCollision(E_SPHERE_VS_BOX, m_CHero.m_pAni, 1);
		if (pCurAni != NULL)
		{
			if (g_CInfo.m_nHp > 0)
			{
				m_CHero.m_bShow = true;
				m_CGun.m_bHit = true;
				m_bShake = true;
				g_CInfo.m_nHp -= 1;
				m_CUI.m_CHp.m_pAni->SetLoopType(E_ANI_ONE, g_CInfo.m_nHp, g_CInfo.m_nHp, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
			}
		}
	}
}

void CGameScene::BloodUpdate()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_CMonster.m_pMonster[i]->GetShow() && m_CMonster.m_bHit[i] && m_CMonster.m_nHp[i] > 50)
		{
			m_CBlood.Update(m_CMonster.m_pMonster[i]->GetPosVec3());
		}
	}
}

void CGameScene::MonsterDisable(int nIndex)
{
	m_CMonster.Disable(nIndex);
	m_CShadow.Disable(nIndex);
	g_CInfo.m_nKill += 1;
	if (m_CUI.m_nDate % 5 != 0)
	{
		g_CInfo.m_nScore += 10;
	}
	m_nCount += 1;
}

void CGameScene::MonsterHpUpdate()
{
	int i;
	if (m_CUI.m_nDate % 5 == 0)
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	for (i; i < D_MONSTER_MAX; i++)
	{
		if (m_CMonster.m_pMonster[i]->GetShow())
		{
			if (m_CMonster.m_nHp[i] <= 0)
			{
				MonsterSound();
				CreateEffect(m_CMonster.m_pMonster[i]->GetPosVec3());
				MonsterDisable(i);
			}
		}
	}
}

void CGameScene::MonsterSound()
{
	if (!D_SOUND->IsPlaying(m_CMonster.m_sndDead))
	{
		D_SOUND->Play(m_CMonster.m_sndDead, D_MNG->GetSoundVolume());
	}
	else
	{
		if (!D_SOUND->IsPlaying(m_CMonster.m_sndDead2))
		{
			D_SOUND->Play(m_CMonster.m_sndDead2, D_MNG->GetSoundVolume());
		}
		else
		{
			if (!D_SOUND->IsPlaying(m_CMonster.m_sndDead_2))
			{
				D_SOUND->Play(m_CMonster.m_sndDead_2, D_MNG->GetSoundVolume());
			}
			else
			{
				if (!D_SOUND->IsPlaying(m_CMonster.m_sndDead_3))
				{
					D_SOUND->Play(m_CMonster.m_sndDead_3, D_MNG->GetSoundVolume());
				}
			}
		}
	}
}

void CGameScene::Story(float dt)
{
	if (m_CUI.m_nDate < 15)
	{
		Update_2(dt);
	}
	else
	{
		Ending();
	}
}

void CGameScene::Challenge(float dt)
{
	Update_2(dt);
}

void CGameScene::Update_2(float dt)
{
	if (!m_CUI.m_CHp.m_pPlane->GetShow())
	{
		Pause();
	}
	if (g_CInfo.m_nHp > 0)
	{
		m_CHero.Update(dt, m_eChar);
		SkillUse();
		if (!m_bReset && m_CUI.m_bStart)
		{
			CreateMonster();
			BigSizeMonster();
			Reset();
		}
		HeroInfoUpdate(dt);
		CreateBullet();
		CreateMine();
		m_CMine.Update();
		Mine_VS_MonsterColision();
		CameraShake();
		m_CBullet.Update(dt, m_CHero.m_pAni->GetPosVec3());
		Bullet_VS_MonsterColision();
		Grenade_VS_MonsterColision();
		MonsterHpUpdate();
		BloodUpdate();
		m_CEffect.Update(dt);
		BreakTime();
		Hero_VS_MonsterColision();
		HeartBeat();
		g_CInfo.NumUpdate();
		Cheat();
		//======================================
		m_CPausePopupWin.PopupUpdate();
		m_CSettingPopupWin.PopupUpdate();
		m_CExitPopupWin.PopupUpdate();
	}
	m_CUI.Update();
	End();
}

void CGameScene::Ending()
{
	if (!g_CInfo.m_bClear)
	{
		if (m_eChar == E_SOLDIER && D_SOUND->IsPlaying(m_CHero.m_CSoldier.m_CGrenade.m_Explosionsnd))
		{
			D_SOUND->Stop(m_CHero.m_CSoldier.m_CGrenade.m_Explosionsnd);
		}
		else
		{
			g_CInfo.m_bClear = true;
			D_SOUND->Play(m_sndClear, D_MNG->GetSoundVolume());
		}
	}
	else
	{
		m_CUI.ClearImageUpdate();
		if (!D_SOUND->IsPlaying(m_sndClear))
		{
			if (m_CUI.m_pClear->GetAlpha() >= 2.0f)
			{
				D_SCENE->ChangeScene("result");
				Init();
			}
		}
	}
}

void CGameScene::SoundStop()
{
	switch (m_eChar)
	{
	case E_BUSINESSMAN:
		if (D_SOUND->IsPlaying(m_CHero.m_CMan.m_Soundsnd))
		{
			D_SOUND->Pause(m_CHero.m_CMan.m_Soundsnd, true);
		}
		break;
	case E_DOCTOR:
		if (D_SOUND->IsPlaying(m_CHero.m_CDoctor.m_Soundsnd))
		{
			D_SOUND->Pause(m_CHero.m_CDoctor.m_Soundsnd, true);
		}
		break;
	case E_SOLDIER:
		if (D_SOUND->IsPlaying(m_CHero.m_CSoldier.m_Soundsnd))
		{
			D_SOUND->Pause(m_CHero.m_CSoldier.m_Soundsnd, true);
		}
		if (D_SOUND->IsPlaying(m_CHero.m_CSoldier.m_CGrenade.m_Soundsnd))
		{
			D_SOUND->Pause(m_CHero.m_CSoldier.m_CGrenade.m_Soundsnd, true);
		}
		if (D_SOUND->IsPlaying(m_CHero.m_CSoldier.m_CGrenade.m_Explosionsnd))
		{
			D_SOUND->Pause(m_CHero.m_CSoldier.m_CGrenade.m_Explosionsnd, true);
		}
		break;
	}
}

void CGameScene::CreateMine()
{
	if (m_CUI.m_nMine > 0)
	{
		if (!D_SOUND->IsPlaying(m_CMine.m_Soundsnd) || D_SOUND->IsPaused(m_CMine.m_Soundsnd))
		{
			if (D_INPUT->IsKeyDown(VK_E))
			{
				if (!m_CMine.m_pAni->GetShow())
				{
					m_CUI.m_nMine -= 1;
					m_CMine.Enable(m_CHero.m_pAni->GetPosVec3());
				}
			}
		}
	}
}

void CGameScene::Mine_VS_MonsterColision()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_CMonster.m_pMonster[i]->GetShow())
		{
			if (m_CMine.m_pAni->GetShow())
			{
				CEMAnimation* pCurAni = NULL;
				pCurAni = (CEMAnimation*)this->IsCollision(E_BOX_VS_SPHERE, m_CMonster.m_pMonster[i], 3);
				if (pCurAni != NULL)
				{
					if (m_CMine.m_pAni->GetCurFrameNumber() <= 1)
					{
						m_CMine.m_pAni->SetTime(0.13f);
						m_CMine.m_pAni->SetBoundingSphereRadius(5.0f);
						m_CMine.m_pAni->SetLoopType(E_ANI_ONE, 2, 7, E_ANI_ENDING_TYPE_SHOW_FALSE);
						if (D_SOUND->IsPlaying(m_CMine.m_Soundsnd))
						{
							D_SOUND->Pause(m_CMine.m_Soundsnd, true);
						}
						D_SOUND->Play(m_CMine.m_Explosionsnd, D_MNG->GetSoundVolume());
					}
					else
					{
						if (m_CMine.m_pAni->GetCurFrameNumber() == 2)
						{
							if (m_CUI.m_nDate % 5 == 0)
							{
								m_CMonster.m_nHp[0] -= 100;
								if(i !=0)
									m_CMonster.m_nHp[i] -= 500;
							}
							else
								m_CMonster.m_nHp[i] -= 500;
						}
					}
				}
			}
		}
	}
}

void CGameScene::HeartBeat()
{
	if (g_CInfo.m_nHp == 2)
	{
		if (!D_SOUND->IsPlaying(m_sndHeartBeat_1))
		{
			D_SOUND->Play(m_sndHeartBeat_1, D_MNG->GetSoundVolume());
		}
	}
	if (g_CInfo.m_nHp == 1)
	{
		if (!D_SOUND->IsPlaying(m_sndHeartBeat_2))
		{
			D_SOUND->Play(m_sndHeartBeat_2, D_MNG->GetSoundVolume());
		}
	}
}

void CGameScene::SkillUse()
{
	if (m_CHero.m_bUse)
	{
		if (!m_CUI.m_pSkillBlock->GetShow())
		{
			m_CUI.m_pSkillBlock->SetShow(true);
		}
	}
	else
	{
		if (m_CUI.m_pSkillBlock->GetShow() && m_CUI.m_nSkillTime < 1.0f)
		{
			m_CUI.m_pSkillBlock->SetShow(false);
		}
	}
}

void CGameScene::Cheat()
{
	if (D_INPUT->IsKeyDown(VK_Y))
	{
		for (int i = 0; i < D_MONSTER_MAX; i++)
		{
			if (m_CMonster.m_pMonster[i]->GetShow())
			{
				m_CMonster.m_nHp[i] -= 1000;
			}
		}
	}
	if (D_INPUT->IsKeyDown(VK_T))
	{
		g_CInfo.m_nHp = 3;
	}
	if (D_INPUT->IsKeyDown(VK_U))
	{
		g_CInfo.m_nHp = 0;
	}
}