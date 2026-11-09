#include "stdafx.h"

void CMenuBase::CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow)
{
	Reset();

	CMenuScene* pMenuScene = (CMenuScene*)D_SCENE->GetCurScene();
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
	//====================================================
	m_pModeAni[0] = new CEMAnimation(3);
	m_pModeAni[0]->SetTexture(pScene, 3, "Data/Image/ui/buttons/story_0.png", "Data/Image/ui/buttons/story.png", "Data/Image/ui/buttons/story.png");
	m_pModeAni[0]->SetBlend(true);
	m_pModeAni[0]->SetBoundingBox_LTLB_Size(3.0f);
	m_pModeAni[0]->SetBoundingBox_RTRB_Size(-10.0f);
	m_pModeAni[0]->SetBoundingBox_LTRT_Size(-4.0f);
	m_pModeAni[0]->SetBoundingBox_LBRB_Size(4.0f);
	m_pModeAni[0]->SetLoopType(E_ANI_ONE, 1, 1, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pModeAni[0]->SetPos(170.0f, -60.0f, 0.0f);
	m_pModeAni[0]->SetSize(0.4f);

	pScene->Commit(nLayer, "Mode_Story", m_pModeAni[0]);
	//====================================================
	m_pModeAni[1] = new CEMAnimation(3);
	m_pModeAni[1]->SetTexture(pScene, 3, "Data/Image/ui/buttons/Challenge_0.png", "Data/Image/ui/buttons/Challenge.png", "Data/Image/ui/buttons/Challenge_0.png");
	m_pModeAni[1]->SetBlend(true);
	m_pModeAni[1]->SetBoundingBox_LTLB_Size(20.0f);
	m_pModeAni[1]->SetBoundingBox_RTRB_Size(-20.0f);
	m_pModeAni[1]->SetBoundingBox_LTRT_Size(-15.0f);
	m_pModeAni[1]->SetBoundingBox_LBRB_Size(15.0f);
	m_pModeAni[1]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pModeAni[1]->SetPos(370.0f, -60.0f, 0.0f);
	m_pModeAni[1]->SetSize(0.4f);

	pScene->Commit(nLayer, "Mode_Challenge", m_pModeAni[1]);
	//===============================================================
	m_pPlane[0] = new CEMPlane();
	m_pPlane[0]->SetTexture("Data/Image/ui/buttons/Select.png");
	m_pPlane[0]->SetBlend(true);
	m_pPlane[0]->SetPos(270.0f, -10.0f, 0.0f);
	m_pPlane[0]->SetSize(0.5f);

	pScene->Commit(nLayer, "Selection", m_pPlane[0]);
	//===============================================================
	// 캐릭터 일러스트
	m_pAni[0] = new CEMAnimation(4);
	m_pAni[0]->SetPos(270.0f, -140.0f, 0.0f);
	m_pAni[0]->SetTexture(pMenuScene, 4, "Data/Image/Hero/Illust/0.png", "Data/Image/Hero/Illust/1.png",
	     "Data/Image/Hero/Illust/2.png", "Data/Image/Hero/Illust/3.png");
	m_pAni[0]->SetBlend(true);
	m_pAni[0]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni[0]->SetSize(0.6f, 0.6f);
	m_pAni[0]->SetBoundingBoxCalc(false);
	
	pScene->Commit(nLayer, "CharIllust", m_pAni[0]);

	//===============================================================
	// 캐릭터 스탯
	m_pAni[1] = new CEMAnimation(4);
	m_pAni[1]->SetPos(400.0f, -140.0f, 0.0f);
	m_pAni[1]->SetTexture(pMenuScene, 4, "Data/Image/Hero/Stats/회사원.png", "Data/Image/Hero/Stats/군인.png",
	        "Data/Image/Hero/Stats/의사.png", "Data/Image/Hero/Stats/엔지니어.png");
	m_pAni[1]->SetBlend(true);
	m_pAni[1]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni[1]->SetSize(0.6f);
	m_pAni[1]->SetBoundingBoxCalc(false);
	
	pScene->Commit(nLayer, "CharStats", m_pAni[1]);

	//===============================================================
	// 캐릭터 능력설명
	m_pAni[2] = new CEMAnimation(4);
	m_pAni[2]->SetPos(145.0f, -140.0f, 0.0f);
	m_pAni[2]->SetTexture(pMenuScene, 4, "Data/Image/Hero/Stats/회사원 능력.png", "Data/Image/Hero/Stats/군인 능력.png",
		"Data/Image/Hero/Stats/의사 능력.png", "Data/Image/Hero/Stats/엔지니어 능력.png");
	m_pAni[2]->SetBlend(true);
	m_pAni[2]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni[2]->SetSize(0.19f);
	m_pAni[2]->SetBoundingBoxCalc(false);

	pScene->Commit(nLayer, "CharExplain", m_pAni[2]);
	//====================================================
   //버튼 배경
	m_Btns[0].pUI[0] = new CEMPlane();
	m_Btns[0].pUI[0]->SetTexture("Data/Image/ui/buttons/Button.png");
	m_Btns[0].pUI[0]->SetPos(275.0f, -250.0f, 0.0f);
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
	m_Btns[0].pUI[1]->SetPos(m_Btns[0].pUI[0]->GetPosVec2().m_fX, m_Btns[0].pUI[0]->GetPosVec2().m_fY -2.0f, 0.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTLB_Size(-22.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_RTRB_Size(22.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LTRT_Size(4.0f);
	m_Btns[0].pUI[1]->SetBoundingBox_LBRB_Size(-4.0f);
	m_Btns[0].pUI[1]->SetBlend(true);
	m_Btns[0].pUI[1]->SetBackFaceCulling(true);
	m_Btns[0].pUI[1]->SetSize(0.4f);
	m_Btns[0].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[0].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_PlayTxt", m_Btns[0].pUI[1]);
	//====================================================
	// Home 글씨
	m_Btns[1].pUI[1] = new CEMPlane();
	m_Btns[1].pUI[1]->SetTexture("Data/Image/ui/buttons/home.png");
	m_Btns[1].pUI[1]->SetPos(stEMVec3(450.0f, -10.0f, 0.0f));
	m_Btns[1].pUI[1]->SetBoundingBox_LTLB_Size(5.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_RTRB_Size(-5.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LTRT_Size(-4.0f);
	m_Btns[1].pUI[1]->SetBoundingBox_LBRB_Size(4.0f);
	m_Btns[1].pUI[1]->SetBlend(true);
	m_Btns[1].pUI[1]->SetSize(0.3f);
	m_Btns[1].pUI[1]->SetBackFaceCulling(true);
	m_Btns[1].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[1].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_HomeTxt", m_Btns[1].pUI[1]);

	//===============================================================
	// Charactor Left Btn
	m_Btns[2].pUI[0] = new CEMPlane();
	m_Btns[2].pUI[0]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[2].pUI[0]->SetMirrorType(E_RIGHT_MIRROR);
	m_Btns[2].pUI[0]->SetPos(stEMVec3(147, -250, 0));
	m_Btns[2].pUI[0]->SetBoundingBox_LTLB_Size(5.0f);
	m_Btns[2].pUI[0]->SetBoundingBox_RTRB_Size(-5.0f);
	m_Btns[2].pUI[0]->SetBoundingBox_LTRT_Size(-4.0f);
	m_Btns[2].pUI[0]->SetBoundingBox_LBRB_Size(4.0f);
	m_Btns[2].pUI[0]->SetSize(0.4f);
	m_Btns[2].pUI[0]->SetBlend(true);
	m_Btns[2].pUI[0]->SetBackFaceCulling(true);
	m_Btns[2].pUI[0]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[0]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Menu_Char_Left_Btn", m_Btns[2].pUI[0]);


	//===============================================================
	// Charactor Right Btn
	m_Btns[2].pUI[1] = new CEMPlane();
	m_Btns[2].pUI[1]->SetTexture("Data/Image/ui/buttons/Arrow.png");
	m_Btns[2].pUI[1]->SetPos(stEMVec3(403, -250, 0));
	m_Btns[2].pUI[1]->SetBoundingBox_LTLB_Size(5.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_RTRB_Size(-5.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LTRT_Size(-4.0f);
	m_Btns[2].pUI[1]->SetBoundingBox_LBRB_Size(4.0f);
	m_Btns[2].pUI[1]->SetSize(0.4f);
	m_Btns[2].pUI[1]->SetBlend(true);
	m_Btns[2].pUI[1]->SetBackFaceCulling(true);
	m_Btns[2].pUI[1]->SetBoundingBoxCalc(true);
	m_Btns[2].pUI[1]->SetFrstumCullingFlag(false);
	pScene->Commit(nLayer, "D_Menu_Char_Right_Btn", m_Btns[2].pUI[1]);

	m_PlaySnd = D_SOUND->FileOpen("Data/Sound/click_1.ogg");
	CPopupWinRoot::CreatePopupWindow(ClickSnd, nLayer, pScene, bShow);
}

void CMenuBase::OnMouseMoveEvent(stMouseInfo stPos)
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

void CMenuBase::OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
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
				if (m_pSelectPlane->GetName() == "Mode_Story")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					g_CInfo.m_bMode = 1;
					m_pModeAni[0]->SetLoopType(E_ANI_ONE, 1, 1, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					m_pModeAni[1]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
				}

				if (m_pSelectPlane->GetName() == "Mode_Challenge")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());
					m_pModeAni[0]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					m_pModeAni[1]->SetLoopType(E_ANI_ONE, 1, 1, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					g_CInfo.m_bMode = 0;
				}

				if (m_pSelectPlane->GetName() == "D_PlayTxt")
				{
					D_SOUND->Play(m_PlaySnd, D_MNG->GetSoundVolume());

					g_CInfo.m_eHero = (eCharacter)m_nAniNum;
					D_SCENE->ChangeSceneFade("way");
				}

				if (m_pSelectPlane->GetName() == "D_HomeTxt")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					D_SCENE->ChangeSceneFade("logo");
				}

				if (m_pSelectPlane->GetName() == "D_Menu_Char_Left_Btn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					m_nAniNum -= 1;
					if (m_nAniNum < 0)
					{
						m_nAniNum = 2;
					}
					m_pAni[0]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					m_pAni[1]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					m_pAni[2]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
				}

				if (m_pSelectPlane->GetName() == "D_Menu_Char_Right_Btn")
				{
					D_SOUND->Play(m_ClickSnd, D_MNG->GetSoundVolume());

					m_nAniNum += 1;
					if (m_nAniNum > 2)
					{
						m_nAniNum = 0;
					}
					m_pAni[0]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					m_pAni[1]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
					m_pAni[2]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
				}

			}
		}break;

		case E_MOUSE_RIGHT:
		{

		}break;
		}
	}

}

void CMenuBase::Left_Right()
{
	if (D_INPUT->IsKeyUp(VK_A))
	{
		m_nAniNum -= 1;
		if (m_nAniNum < 0)
		{
			m_nAniNum = 2;
		}
		m_pAni[0]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pAni[1]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pAni[2]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	}

	if (D_INPUT->IsKeyUp(VK_D))
	{
		m_nAniNum += 1;
		if (m_nAniNum > 2)
		{
			m_nAniNum = 0;
		}
		m_pAni[0]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pAni[1]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pAni[2]->SetLoopType(E_ANI_ONE, m_nAniNum, m_nAniNum, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	}

}