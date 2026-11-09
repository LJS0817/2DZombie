#include "stdafx.h"


void CPauseSetting::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();
	stEMVec3 stPos(D_CAMERA->GetPosVec3());

	//====================================================
	// Setting팝업창 윈도우
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/ui/buttons/SettingBG.png");
	m_pBg->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetSize(0.5);
	m_pBg->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "A_SettingPopupBG", m_pBg);

	//===============================================================
	// X 버튼
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/ui/buttons/X.png");
	m_Btns[0].pUI[0]->SetPos(stPos.m_fX + 135.0f, stPos.m_fY + 85.0f, 0.0f);
	m_Btns[0].pUI[0]->SetSize(0.5f);
	m_Btns[0].pUI[0]->SetBlend(true);
	m_Btns[0].pUI[0]->SetBackFaceCulling(true);
	m_Btns[0].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingExitBtn", m_Btns[0].pUI[0]);

	//===============================================================
	// BGM Left Btn
	m_Btns[1].pUI[0] = new CEMPlane();
	m_Btns[1].pUI[0]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[1].pUI[0]->SetMirrorType(E_RIGHT_MIRROR);
	m_Btns[1].pUI[0]->SetPos(stPos.m_fX - 50.0f, stPos.m_fY +45.0f, 0.0f);
	m_Btns[1].pUI[0]->SetSize(0.2f);
	m_Btns[1].pUI[0]->SetBlend(true);
	m_Btns[1].pUI[0]->SetBackFaceCulling(true);
	m_Btns[1].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Setting_BGM_Left_VolumeBtn", m_Btns[1].pUI[0]);


	//===============================================================
	// BGM Right Btn
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[1].pUI[1]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_Btns[1].pUI[1]->SetSize(0.2f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Setting_BGM_Right_VolumeBtn", m_Btns[1].pUI[1]);

	//====================================================
	// BGM Gauge Bar
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/ui/buttons/gauge.png");
	m_pEtcs[0]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pEtcs[0]->SetOffset(85.0f, 0);
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);

	m_pEtcs[2] = new CEMPlane();
	m_pEtcs[2]->SetTexture("Data/Image/ui/buttons/gaugeBack.png");
	m_pEtcs[2]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pEtcs[2]->SetOffset(85.0f, 0);
	m_pEtcs[2]->SetBlend(true);
	m_pEtcs[2]->SetBackFaceCulling(true);
	m_pEtcs[2]->SetBoundingBoxCalc(false);
	m_pEtcs[2]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer + 2, "C_BGMGaugeBarBack", m_pEtcs[2]);
	pScene->Commit(nLayer + 1, "C_BGMGaugeBar", m_pEtcs[0]);

	// 게이지바 설정
	CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
	m_pEtcs[0]->SetSize(D_MNG->GetMusicVolume(), 1.0f);

	//===============================================================
	// Sound Left Btn
	m_Btns[2].pUI[0] = new CEMPlane();
	m_Btns[2].pUI[0]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[2].pUI[0]->SetMirrorType(E_RIGHT_MIRROR);
	m_Btns[2].pUI[0]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_Btns[2].pUI[0]->SetSize(0.2f);
	m_Btns[2].pUI[0]->SetBlend(true);
	m_Btns[2].pUI[0]->SetBackFaceCulling(true);
	m_Btns[2].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Setting_Sound_Left_VolumeBtn", m_Btns[2].pUI[0]);


	//===============================================================
	// Sound Right Btn
	m_Btns[2].pUI[1] = new CEMPlane();
	m_Btns[2].pUI[1]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[2].pUI[1]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_Btns[2].pUI[1]->SetSize(0.2f);
	m_Btns[2].pUI[1]->SetBlend(true);
	m_Btns[2].pUI[1]->SetBackFaceCulling(true);
	m_Btns[2].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Setting_Sound_Right_VolumeBtn", m_Btns[2].pUI[1]);

	//====================================================
	// Sound Gauge Bar
	m_pEtcs[1] = new CEMPlane();
	m_pEtcs[1]->SetTexture("Data/Image/ui/buttons/gauge.png");
	m_pEtcs[1]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pEtcs[1]->SetOffset(85.0f, 0);
	m_pEtcs[1]->SetBlend(true);
	m_pEtcs[1]->SetBackFaceCulling(true);
	m_pEtcs[1]->SetBoundingBoxCalc(false);
	m_pEtcs[1]->SetFrstumCullingFlag(false);

	m_pEtcs[3] = new CEMPlane();
	m_pEtcs[3]->SetTexture("Data/Image/ui/buttons/gaugeBack.png");
	m_pEtcs[3]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pEtcs[3]->SetOffset(85.0f, 0);
	m_pEtcs[3]->SetBlend(true);
	m_pEtcs[3]->SetBackFaceCulling(true);
	m_pEtcs[3]->SetBoundingBoxCalc(false);
	m_pEtcs[3]->SetFrstumCullingFlag(false);


	pScene->Commit(nLayer + 2, "C_BGMGaugeBarBack_1", m_pEtcs[3]);
	pScene->Commit(nLayer + 1, "C_SoundGaugeBar", m_pEtcs[1]);

	// 게이지바 설정
	//CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
	m_pEtcs[1]->SetSize(D_MNG->GetSoundVolume(), 1.0f);

	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CPauseSetting::OnMouseMoveEvent(stMouseInfo stPos)
{
	if (GetCollisionFlag())
	{
		stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

		// 전부 체크
		if (m_pScene != NULL)
		{
			m_pSelectPlane = m_pScene->AABBvsRay(stPos.m_nX, stPos.m_nY, m_nLayer);

			// 마우스 이동시마다 빨간색으로 변경하게 하는 코드 입니다. 
			if (m_pPrevSelectPlane != NULL && m_pSelectPlane != NULL)
			{
				if (m_pSelectPlane != m_pPrevSelectPlane)
				{
					m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
				}
			}

			if (m_pSelectPlane)
			{
				// 선택되어진놈 백업입니다.
				m_pPrevSelectPlane = m_pSelectPlane;

				// B로 시작하는 Plane만 빨간색으로 변경하게 하는 코드 입니다. 
				if (m_pSelectPlane->GetName().c_str()[0] != 'D')
				{
					if (m_pPrevSelectPlane)
						m_pPrevSelectPlane->SetColor(1, 1, 1, 1);
				}
				else
				{
					m_pSelectPlane->SetColor(1, 0, 0, 1);
				}
			}
		}
	}
}

void CPauseSetting::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	if (GetCollisionFlag())
	{
		switch (eButton)
		{
		case E_MOUSE_LEFT:
		{
			stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

			// 전부 체크
			m_pSelectPlane = m_pScene->AABBvsRay(stPos.m_nX, stPos.m_nY, m_nLayer);

			if (m_pSelectPlane)
			{
				// 세팅창 Exit
				if (m_pSelectPlane->GetName() == "D_SettingExitBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					// SettingPoup창을 닫아준다.
					SetShow(false);

					// BaseMenuWin 충돌처리를 가능하게한다.
					CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
					pGameScene->m_CPausePopupWin.SetCollisionFlag(true);
					pGameScene->m_CPausePopupWin.SetShow(true);
				}

				if (m_pSelectPlane->GetName() == "D_Setting_BGM_Left_VolumeBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					float fVolume = D_MNG->GetMusicVolume();

					fVolume -= 0.1f;

					if (fVolume < 0)
						fVolume = 0;

					D_MNG->SetMusicVolume(fVolume);
					D_SOUND->SetVolume(D_MNG->m_BGMSnd, fVolume);

					m_pEtcs[0]->SetSize(fVolume, 1.0f);
				}

				if (m_pSelectPlane->GetName() == "D_Setting_BGM_Right_VolumeBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					float fVolume = D_MNG->GetMusicVolume();

					fVolume += 0.1f;

					if (fVolume > 1.0f)
						fVolume = 1.0f;

					D_MNG->SetMusicVolume(fVolume);
					D_SOUND->SetVolume(D_MNG->m_BGMSnd, fVolume);

					m_pEtcs[0]->SetSize(fVolume, 1.0f);
				}

				if (m_pSelectPlane->GetName() == "D_Setting_Sound_Left_VolumeBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					float fVolume = D_MNG->GetSoundVolume();

					fVolume -= 0.1f;

					if (fVolume < 0)
						fVolume = 0;

					D_MNG->SetSoundVolume(fVolume);
					D_SOUND->SetVolume(D_MNG->m_ClickSnd, fVolume);

					m_pEtcs[1]->SetSize(fVolume, 1.0f);
				}

				if (m_pSelectPlane->GetName() == "D_Setting_Sound_Right_VolumeBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					float fVolume = D_MNG->GetSoundVolume();

					fVolume += 0.1f;

					if (fVolume > 1.0f)
						fVolume = 1.0f;

					D_MNG->SetSoundVolume(fVolume);
					D_SOUND->SetVolume(D_MNG->m_ClickSnd, fVolume);

					m_pEtcs[1]->SetSize(fVolume, 1.0f);
				}
			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}

void CPauseSetting::ESC()
{
	if (D_INPUT->IsKeyDown(VK_ESCAPE))
	{
		// SettingPoup창을 닫아준다.
		SetShow(false);

		// BaseMenuWin 충돌처리를 가능하게한다.
		CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
		pGameScene->m_CPausePopupWin.SetCollisionFlag(true);
		pGameScene->m_CPausePopupWin.SetShow(true);
	}
}


void CPauseSetting::PopupUpdate()
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());
	// Setting팝업창 윈도우
	m_pBg->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	// X 버튼
	m_Btns[0].pUI[0]->SetPos(stPos.m_fX, stPos.m_fY - 60.0f, 0.0f);
	// BGM Left Btn
	m_Btns[1].pUI[0]->SetPos(stPos.m_fX - 10.0f, stPos.m_fY, 0.0f);
	// BGM Right Btn
	m_Btns[1].pUI[1]->SetPos(stPos.m_fX + 40.0f, stPos.m_fY, 0.0f);
	// BGM Gauge Bar
	m_pEtcs[0]->SetPos(stPos.m_fX - 60.0f, stPos.m_fY + 20.0f, 0.0f);
	m_pEtcs[2]->SetPos(stPos.m_fX - 60.0f, stPos.m_fY + 20.0f, 0.0f);
	// Sound Left Btn
	m_Btns[2].pUI[0]->SetPos(stPos.m_fX - 10.0f, stPos.m_fY - 40.0f, 0.0f);
	// Sound Right Btn
	m_Btns[2].pUI[1]->SetPos(stPos.m_fX + 40.0f, stPos.m_fY - 40.0f, 0.0f);
	// Sound Gauge Bar
	m_pEtcs[1]->SetPos(stPos.m_fX - 60.0f, stPos.m_fY - 30.0f, 0.0f);
	m_pEtcs[3]->SetPos(stPos.m_fX - 60.0f, stPos.m_fY - 30.0f, 0.0f);
}