#include "stdafx.h"


void CLogoSetting::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// Setting팝업창 윈도우
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/ui/buttons/SettingBG.png");
	m_pBg->SetPos(stEMVec3(275.0f, -130.0f, 0));
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetSize(0.5f);
	m_pBg->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "A_SettingPopupBG", m_pBg);

	//===============================================================
	// X 버튼
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/ui/buttons/X.png");
	m_Btns[0].pUI[0]->SetPos(stEMVec3(370.0f, -195.0f, 0.0f));
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
	m_Btns[1].pUI[0]->SetPos(stEMVec3(270.0f, -130.0f, 0.0f));
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
	m_Btns[1].pUI[1]->SetPos(stEMVec3(320.0f, -130.0f, 0.0f));
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
	m_pEtcs[0]->SetPos(stEMVec3(207.0f, -110.0f, 0.0f));
	m_pEtcs[0]->SetOffset(85.0f, 0);
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer + 2, "C_BGMGaugeBar", m_pEtcs[0]);

	m_pEtcs[2] = new CEMPlane();
	m_pEtcs[2]->SetTexture("Data/Image/ui/buttons/gaugeBack.png");
	m_pEtcs[2]->SetPos(300.0f, -110.0f, 0.0f);
	m_pEtcs[2]->SetBlend(true);
	m_pEtcs[2]->SetBackFaceCulling(true);
	m_pEtcs[2]->SetBoundingBoxCalc(false);
	m_pEtcs[2]->SetFrstumCullingFlag(false);


	pScene->Commit(nLayer + 3, "C_BGMGaugeBarBack_1", m_pEtcs[2]);
	// 게이지바 설정
	CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
	m_pEtcs[0]->SetSize(D_MNG->GetMusicVolume(), 1.0f);

	//===============================================================
	// Sound Left Btn
	m_Btns[2].pUI[0] = new CEMPlane();
	m_Btns[2].pUI[0]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[2].pUI[0]->SetMirrorType(E_RIGHT_MIRROR);
	m_Btns[2].pUI[0]->SetPos(stEMVec3(270.0f, -175.0f, 0.0f));
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
	m_Btns[2].pUI[1]->SetPos(stEMVec3(320.0f, -175.0f, 0.0f));
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
	m_pEtcs[1]->SetPos(stEMVec3(207.0f, -156.0f, 0.0f));
	m_pEtcs[1]->SetOffset(85.0f, 0);
	m_pEtcs[1]->SetBlend(true);
	m_pEtcs[1]->SetBackFaceCulling(true);
	m_pEtcs[1]->SetBoundingBoxCalc(false);
	m_pEtcs[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer + 2, "C_SoundGaugeBar", m_pEtcs[1]);

	m_pEtcs[4] = new CEMPlane();
	m_pEtcs[4]->SetTexture("Data/Image/ui/buttons/gaugeBack.png");
	m_pEtcs[4]->SetPos(300.0f, -156.0f, 0.0f);
	m_pEtcs[4]->SetBlend(true);
	m_pEtcs[4]->SetBackFaceCulling(true);
	m_pEtcs[4]->SetBoundingBoxCalc(false);
	m_pEtcs[4]->SetFrstumCullingFlag(false);


	pScene->Commit(nLayer + 3, "C_BGMGaugeBarBack_2", m_pEtcs[4]);

	// 게이지바 설정
	//CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
	m_pEtcs[1]->SetSize(D_MNG->GetSoundVolume(), 1.0f);

	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CLogoSetting::OnMouseMoveEvent(stMouseInfo stPos)
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

void CLogoSetting::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
					CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
					pLogoScene->m_BaseMenuWin.SetCollisionFlag(true);
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

void CLogoSetting::ESC()
{
	if (D_INPUT->IsKeyDown(VK_ESCAPE))
	{
		// SettingPoup창을 닫아준다.
		SetShow(false);

		// BaseMenuWin 충돌처리를 가능하게한다.
		CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
		pLogoScene->m_BaseMenuWin.SetCollisionFlag(true);
	}
}