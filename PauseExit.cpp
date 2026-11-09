#include "stdafx.h"


void CPauseExit::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();
	stEMVec3 stPos(D_CAMERA->GetPosVec3());

	//====================================================
	// Exit팝업창 윈도우
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/ui/buttons/Exit.png");
	m_pBg->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetSize(0.5);
	m_pBg->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "A_ExitPopup", m_pBg);

	//===============================================================
	// 팝업 Title
	m_pEtcs[0] = new CEMPlane();
	m_pEtcs[0]->SetTexture("Data/Image/ui/buttons/Home_1.png");
	m_pEtcs[0]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pEtcs[0]->SetBlend(true);
	m_pEtcs[0]->SetBackFaceCulling(true);
	m_pEtcs[0]->SetBoundingBoxCalc(false);
	m_pEtcs[0]->SetSize(0.7f);
	m_pEtcs[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_ExitWindowTitle", m_pEtcs[0]);
	//===============================================================
	// 팝업 Title
	m_pEtcs[1] = new CEMPlane();
	m_pEtcs[1]->SetTexture("Data/Image/ui/buttons/Dead.png");
	m_pEtcs[1]->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	m_pEtcs[1]->SetBlend(true);
	m_pEtcs[1]->SetBackFaceCulling(true);
	m_pEtcs[1]->SetBoundingBoxCalc(false);
	m_pEtcs[1]->SetSize(0.35f);
	m_pEtcs[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_DeadDate", m_pEtcs[1]);
	//===============================================================
	// OK 글씨
	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/ui/buttons/OK.png");
	m_Btns[0].pUI[1]->SetPos(stPos.m_fX - 50, stPos.m_fY - 20, 0.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(4.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(-4.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(-4.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(4.0f);
	m_Btns[0].pUI[1]->SetSize(0.4f);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_OkBtn", m_Btns[0].pUI[1]);
	//===============================================================
	// Cancel 글씨
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/ui/buttons/cancel.png");
	m_Btns[1].pUI[1]->SetPos(stPos.m_fX + 50, stPos.m_fY - 20, 0.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTLB_Size(4.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_RTRB_Size(-4.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTRT_Size(-4.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LBRB_Size(4.0f);
	m_Btns[1].pUI[1]->SetSize(0.4f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_CancelBtn", m_Btns[1].pUI[1]);


	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CPauseExit::OnMouseMoveEvent(stMouseInfo stPos)
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

void CPauseExit::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
				//팝업창 OK 버튼 
				if (m_pSelectPlane->GetName() == "D_OkBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					D_SCENE->ChangeSceneFade("logo");
				}

				//팝업창 Cancel
				if (m_pSelectPlane->GetName() == "D_CancelBtn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					//ExitPopupWin를 안보이게한다.
					SetShow(false);

					//BaseMenuWin 충돌처리를 가능하게한다.
					CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
					pGameScene->m_CPausePopupWin.SetCollisionFlag(true);
					pGameScene->m_CPausePopupWin.SetShow(true);
				}
			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}


void CPauseExit::ESC()
{
	if (D_INPUT->IsKeyDown(VK_ESCAPE))
	{
		//ExitPopupWin를 안보이게한다.
		SetShow(false);

		//BaseMenuWin 충돌처리를 가능하게한다.
		CGameScene* pGameScene = (CGameScene*)D_SCENE->GetCurScene();
		pGameScene->m_CPausePopupWin.SetCollisionFlag(true);
		pGameScene->m_CPausePopupWin.SetShow(true);
	}
}

void CPauseExit::PopupUpdate()
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());
	// Exit팝업창 윈도우
	m_pBg->SetPos(stPos.m_fX, stPos.m_fY, 0.0f);
	// 팝업 Title
	m_pEtcs[0]->SetPos(stPos.m_fX, stPos.m_fY + 50.0f, 0.0f);
	m_pEtcs[1]->SetPos(stPos.m_fX, stPos.m_fY , 0.0f);
	// OK 글씨
	m_Btns[0].pUI[1]->SetPos(stPos.m_fX - 50.0f, stPos.m_fY - 40.0f, 0.0f);
	// Cancel 글씨
	m_Btns[1].pUI[1]->SetPos(stPos.m_fX + 50.0f, stPos.m_fY - 40.0f, 0.0f);
}