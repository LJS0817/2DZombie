#include "stdafx.h"

void CLogoBase::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	//====================================================
	// 배경
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/Map/No.png");
	m_pBg->SetPos(stEMVec3(0.0f, 0.0f, 0.0f));
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "A_Background", m_pBg);

	////====================================================
	//// Title 배경
	//m_pEtcs[1] = new CEMPlane();
	//m_pEtcs[1]->SetTexture("Data/Image/Logo.png");
	//m_pEtcs[1]->SetPos(stEMVec3(275.0f, -80.0f, 0.0f));
	//m_pEtcs[1]->SetBlend(true);
	//m_pEtcs[1]->SetSize(0.2f);
	//m_pEtcs[1]->SetBackFaceCulling(true);
	//m_pEtcs[1]->SetBoundingBoxCalc(false);
	//m_pEtcs[1]->SetFrstumCullingFlag(false);
	//pScene->Commit(nLayer, "B_TitleBack", m_pEtcs[1]);
	//====================================================
	// Title
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/Logo.png");
	m_pEtcs[0]->SetPos(stEMVec3(275.0f, -70.0f, 0.0f));
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetSize(0.23f);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_Title", m_pEtcs[0]);
	//====================================================
	//버튼 배경
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/ui/buttons/Button.png");
	m_Btns[0].pUI[0]->SetPos(150.0f, -200.0f, 0.0f);
	m_Btns[0].pUI[0]->SetBlend(true);
	m_Btns[0].pUI[0]->SetSize(0.2f);
	m_Btns[0].pUI[0]->SetBackFaceCulling(true);
	m_Btns[0].pUI[0]->SetBoundingBoxCalc(false);
	m_Btns[0].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "C_PlayButton", m_Btns[0].pUI[0]);
	//====================================================
	// Play 글씨
	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/ui/buttons/play.png");
	m_Btns[0].pUI[1]->SetPos(m_Btns[0].pUI[0]->GetPosVec2().m_fX, m_Btns[0].pUI[0]->GetPosVec2().m_fY - 1.0f, 0.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(-22.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(22.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(4.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(-4.0f);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetSize(0.35f);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_PlayTxt", m_Btns[0].pUI[1]);
	//====================================================
	//버튼 배경
	m_Btns[1].pUI[0] = new CEMPlane();
	m_Btns[1].pUI[0]->SetTexture("Data/Image/ui/buttons/Button.png");
	m_Btns[1].pUI[0]->SetPos(275.0f, -200.0f, 0.0f);
	m_Btns[1].pUI[0]->SetBlend(true);
	m_Btns[1].pUI[0]->SetSize(0.2f);
	m_Btns[1].pUI[0]->SetBackFaceCulling(true);
	m_Btns[1].pUI[0]->SetBoundingBoxCalc(false);
	m_Btns[1].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "C_SettingButton", m_Btns[1].pUI[0]);
	//====================================================
	// Setting 글씨
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/ui/buttons/setting.png");
	m_Btns[1].pUI[1]->SetPos(m_Btns[1].pUI[0]->GetPosVec2().m_fX, m_Btns[1].pUI[0]->GetPosVec2().m_fY - 2.0f, 0.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTLB_Size(-8.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_RTRB_Size(8.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTRT_Size(6.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LBRB_Size(-6.0f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetSize(0.35f);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "D_SettingTxt", m_Btns[1].pUI[1]);
	//====================================================
	//버튼 배경
	m_Btns[2].pUI[0] = new CEMPlane();
	m_Btns[2].pUI[0]->SetTexture("Data/Image/ui/buttons/Button.png");
	m_Btns[2].pUI[0]->SetPos(400.0f, -200.0f, 0.0f);
	m_Btns[2].pUI[0]->SetBlend(true);
	m_Btns[2].pUI[0]->SetSize(0.2f);
	m_Btns[2].pUI[0]->SetBackFaceCulling(true);
	m_Btns[2].pUI[0]->SetBoundingBoxCalc(false);
	m_Btns[2].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "C_QuitButton", m_Btns[2].pUI[0]);
	//====================================================
	// Quit 글씨
	m_Btns[2].pUI[1] = new CEMPlane();
	m_Btns[2].pUI[1]->SetTexture("Data/Image/ui/buttons/quit.png");
	m_Btns[2].pUI[1]->SetPos(m_Btns[2].pUI[0]->GetPosVec2().m_fX, m_Btns[2].pUI[0]->GetPosVec2().m_fY - 2.0f, 0.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LTLB_Size(-25.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_RTRB_Size(25.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LTRT_Size(6.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LBRB_Size(-6.0f);
	m_Btns[2].pUI[1]->SetBlend(true);
	m_Btns[2].pUI[1]->SetSize(0.35f);
	m_Btns[2].pUI[1]->SetBackFaceCulling(true);
	m_Btns[2].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_QuitTxt", m_Btns[2].pUI[1]);

	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CLogoBase::OnMouseMoveEvent(stMouseInfo stPos)
{
	if (GetCollisionFlag())
	{
		stEMVec2 stPosVec2 = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);
		if (m_pScene != NULL)
		{
			// 전부 체크
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

void CLogoBase::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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

				if (m_pSelectPlane->GetName() == "D_PlayTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					D_SCENE->ChangeSceneFade("menu");
				}

				if (m_pSelectPlane->GetName() == "D_SettingTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					SetCollisionFlag(false);

					CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
					pLogoScene->m_SettingPopupWin.SetShow(true);
				}

				if (m_pSelectPlane->GetName() == "D_QuitTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					SetCollisionFlag(false);

					CLogoScene* pLogoScene = (CLogoScene*)D_SCENE->GetCurScene();
					pLogoScene->m_ExitPopupWin.SetShow(true);
				}

			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}