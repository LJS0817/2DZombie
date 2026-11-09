#include "stdafx.h"

void CResultBase::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	CResultScene* pResultScene = (CResultScene*)D_SCENE->GetCurScene();
	//====================================================
	// 배경
	m_pBg = new CEMPlane();
	m_pBg->SetTexture("Data/Image/Map/No.png");
	m_pBg->SetPos(stEMVec3(275.0f, -150.0f, 0.0f));
	m_pBg->SetSize(0.5f);
	m_pBg->SetBlend(true);
	m_pBg->SetBackFaceCulling(true);
	m_pBg->SetBoundingBoxCalc(false);
	m_pBg->SetFrstumCullingFlag(false);

	pScene->Commit(nLayer, "A_Background", m_pBg);
	//====================================================
	// Title 배경
	m_pEtcs[1] = new CEMPlane();
	if (!g_CInfo.m_bClear)
	{
		m_pEtcs[1]->SetTexture("Data/Image/ui/Result_1.png");
	}
	else
	{
		m_pEtcs[1]->SetTexture("Data/Image/ui/Result_2.png");
	}
	m_pEtcs[1]->SetPos(stEMVec3(285.0f, -150.0f, 0.0f));
	m_pEtcs[1]->SetBlend(true);
	m_pEtcs[1]->SetSize(0.5f);
	m_pEtcs[1]->SetBackFaceCulling(true);
	m_pEtcs[1]->SetBoundingBoxCalc(false);
	m_pEtcs[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_ResultBack", m_pEtcs[1]);

	m_pAni = new CEMAnimation(6);
	m_pAni->SetTexture(pScene, 6, "Data/Image/ui/Hand/0.png", "Data/Image/ui/Hand/1.png", "Data/Image/ui/Hand/2.png"
		, "Data/Image/ui/Hand/3.png", "Data/Image/ui/Hand/4.png", "Data/Image/ui/Hand/5.png");
	m_pAni->SetPos(280.0f, -250.0f, 0.0f);
	m_pAni->SetBlend(true);
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetTime(0.15f);
	m_pAni->SetSize(0.5f);
	pScene->Commit(nLayer, "B_ZombieHand", m_pAni);
	//====================================================
	// score
	m_pEtcs[2] = new CEMPlane();
	m_pEtcs[2]->SetTexture("Data/Image/ui/buttons/score.png");
	m_pEtcs[2]->SetPos(stEMVec3(240.0f, -120.0f, 0.0f));
	m_pEtcs[2]->SetBlend(true);
	m_pEtcs[2]->SetSize(0.3f);
	m_pEtcs[2]->SetBackFaceCulling(true);
	m_pEtcs[2]->SetBoundingBoxCalc(false);
	m_pEtcs[2]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "B_Score", m_pEtcs[2]);

	//====================================================
	// kill
	m_pEtcs[3] = new CEMPlane();
	m_pEtcs[3]->SetTexture("Data/Image/ui/buttons/kill.png");
	m_pEtcs[3]->SetPos(stEMVec3(235.0f, -165.0f, 0.0f));
	m_pEtcs[3]->SetBlend(true);
	m_pEtcs[3]->SetSize(0.3f);
	m_pEtcs[3]->SetBackFaceCulling(true);
	m_pEtcs[3]->SetBoundingBoxCalc(false);
	m_pEtcs[3]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer - 1, "B_Kill", m_pEtcs[3]);
	//====================================================
	// Home 글씨
	m_Btns[0].pUI[1] = new CEMPlane();
	m_Btns[0].pUI[1]->SetTexture("Data/Image/ui/buttons/home_1.png");
	m_Btns[0].pUI[1]->SetPos(stEMVec3(240.0f, -215.0f, 0.0f));
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(5.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(-5.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(-5.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(5.0f);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetSize(0.3f);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_HomeTxt", m_Btns[0].pUI[1]);
	//====================================================
	// Quit 글씨
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/ui/buttons/quit.png");
	m_Btns[1].pUI[1]->SetPos(stEMVec3(320.0f, -215.0f, 0.0f));
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetSize(0.3f);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_QuitTxt", m_Btns[1].pUI[1]);
	//==========================================
	//숫자
	g_CInfo.Num(pResultScene);
	g_CInfo.m_pNum->SetPos(245.0f, -140.0f, 0.0f);
	g_CInfo.m_pKill->SetPos(245.0f, -185.0f, 0.0f);

	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CResultBase::OnMouseMoveEvent(stMouseInfo stPos)
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

void CResultBase::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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

				if (m_pSelectPlane->GetName() == "D_HomeTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					D_SCENE->ChangeSceneFade("logo");
				}

				if (m_pSelectPlane->GetName() == "D_QuitTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					//BaseMenuWin충돌처리 못하게 한다.
					SetCollisionFlag(false);

					CResultScene* pResultScene = (CResultScene*)D_SCENE->GetCurScene();
					pResultScene->m_ExitPopupWin.SetShow(true);
				}

			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}