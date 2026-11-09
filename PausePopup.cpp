#include "stdafx.h"


void CPausePopup::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();
	stEMVec3 stPos = stEMVec3(260.0f, -150.0f, 0.0f);

	//====================================================
	// Pause팝업창 윈도우
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/ui/buttons/Exit.png");
	m_pBg->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetSize(0.6f, 0.5f);
	m_pBg->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "A_PausePopupBG", m_pBg);

	//====================================================
	// Title
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/ui/buttons/PauseTitle.png");
	m_pEtcs[0]->SetPos(stPos.m_fX, stPos.m_fY + 90, 0.0f);
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetSize(0.6f);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_Title", m_pEtcs[0]);
	//====================================================
	// Dead
	m_pEtcs[1] = new CEMPlane();
	m_pEtcs[1]->SetTexture("Data/Image/ui/buttons/Dead_1.png");
	m_pEtcs[1]->SetPos(stPos.m_fX, stPos.m_fY + 20.0f, 0.0f);
	m_pEtcs[1]->SetBlend(true);
	m_pEtcs[1]->SetSize(0.3f);
	m_pEtcs[1]->SetBackFaceCulling(true);
	m_pEtcs[1]->SetBoundingBoxCalc(false);
	m_pEtcs[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_Dead", m_pEtcs[1]);
	//====================================================
	// Play 글씨
	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/ui/buttons/play.png");
	m_Btns[0].pUI[1]->SetPos(stPos.m_fX, stPos.m_fY + 50, 0.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(6.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(-6.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(-5.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(5.0f);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetSize(0.5f);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_PlayTxt", m_Btns[0].pUI[1]);
	//====================================================
	// Setting 글씨
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/ui/buttons/setting.png");
	m_Btns[1].pUI[1]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTLB_Size(6.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_RTRB_Size(-6.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTRT_Size(-5.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LBRB_Size(5.0f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetSize(0.42f);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_SettingTxt", m_Btns[1].pUI[1]);
	//====================================================
	// Quit 배경
	//m_Btns[2].pUI[0] = new CEMPlane();
	//m_Btns[2].pUI[0]->SetTexture("Data/Image/ui/buttons/BGButton.png");
	//m_Btns[2].pUI[0]->SetPos(stPos.m_fX, stPos.m_fY - 50, 0.0f);
	//m_Btns[2].pUI[0]->SetBlend(true);
	//m_Btns[2].pUI[0]->SetBackFaceCulling(true);
	//m_Btns[2].pUI[0]->SetBoundingBoxCalc(false);
	//m_Btns[2].pUI[0]->SetSize(0.6f);
	//m_Btns[2].pUI[0]->SetFrstumCullingFlag(false);
	//pScene->Commit(nLayer, "C_QuitBg", m_Btns[2].pUI[0]);

	//====================================================
	// Quit 글씨
	m_Btns[2].pUI[1] = new CEMPlane();
	m_Btns[2].pUI[1]->SetTexture("Data/Image/ui/buttons/Home_1.png");
	m_Btns[2].pUI[1]->SetPos(stPos.m_fX, stPos.m_fY - 50, 0.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LTLB_Size(6.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_RTRB_Size(-6.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LTRT_Size(-5.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LBRB_Size(5.0f);
	m_Btns[2].pUI[1]->SetBlend(true);
	m_Btns[2].pUI[1]->SetSize(0.5f);
	m_Btns[2].pUI[1]->SetBackFaceCulling(true);
	m_Btns[2].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_QuitTxt", m_Btns[2].pUI[1]);


	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CPausePopup::OnMouseMoveEvent(stMouseInfo stPos)
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

void CPausePopup::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
				// Play
				if (m_pSelectPlane->GetName() == "D_PlayTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					SetShow(false);

					CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
					pGameScene->m_bPause = false;

				}

				if (m_pSelectPlane->GetName() == "D_SettingTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					//BaseMenuWin충돌처리 못하게 한다.
					SetCollisionFlag(false);
					SetShow(false);

					CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
					pGameScene->m_CSettingPopupWin.SetShow(true);
				}

				if (m_pSelectPlane->GetName() == "D_QuitTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					//BaseMenuWin충돌처리 못하게 한다.
					SetCollisionFlag(false);
					SetShow(false);

					CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
					pGameScene->m_CExitPopupWin.SetShow(true);
				}
			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}


void CPausePopup::PopupUpdate()
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());
	// Pause팝업창 윈도우
	m_pBg->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	// Title
	m_pEtcs[0]->SetPos(stPos.m_fX, stPos.m_fY + 60.0f, 0.0f);
	m_pEtcs[1]->SetPos(stPos.m_fX, stPos.m_fY + 10.0f, 0.0f);
	// Play 글씨
	m_Btns[0].pUI[1]->SetPos(stPos.m_fX - 100.0f, stPos.m_fY - 40.0f, 0.0f);
	// Setting 글씨
	m_Btns[1].pUI[1]->SetPos(stPos.m_fX, stPos.m_fY - 40.0f, 0.0f);
	// Quit 글씨
	m_Btns[2].pUI[1]->SetPos(stPos.m_fX+ 100.0f, stPos.m_fY - 40.0f, 0.0f);
}