#include "stdafx.h"

void CMenuScene::Enter(CSceneWork* pSceneWork)
{
	g_CInfo.m_CFog.Init();
	g_CInfo.m_bMode = 1;
	//====================================================

	D_MNG->CreateSound();
	g_CInfo.m_CFog.CreateObj(this);
	g_CInfo.BackGround(this);
	m_BaseMenuWin.CreatePopupWindow(D_MNG->m_ClickSnd, 0, this, true);
	HeroInit();
}

void CMenuScene::Update(CSceneWork* pSceneWork, float dt)
{
	g_CInfo.MoveBat();
	g_CInfo.m_CFog.Update(dt);
	m_BaseMenuWin.Left_Right();
	D_CAMERA->SetPos(270.0f, -135.0f, 260.0f);
	CRootScene::Update(pSceneWork, dt);
}

void CMenuScene::Render(CSceneWork* pSceneWork)
{

	CRootScene::Render(pSceneWork);
}

void CMenuScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CMenuScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}
}

void CMenuScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	m_BaseMenuWin.OnMouseUpEvent(stPos, eButton);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{

	}break;

	case E_MOUSE_RIGHT:
	{

	}break;
	}
}

void CMenuScene::MouseMoveEvent(stMouseInfo stPos)
{
	m_BaseMenuWin.OnMouseMoveEvent(stPos);
}

HRESULT CMenuScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
	case WM_LBUTTONDOWN:
		{
			int x = 0;
		}break;
	}
	return msg;
}

void CMenuScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{

}

void CMenuScene::HeroInit()
{
	g_CInfo.m_eHero = E_BUSINESSMAN;

	m_BaseMenuWin.m_nAniNum = 0;
	m_BaseMenuWin.m_pAni[0]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_BaseMenuWin.m_pAni[1]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_BaseMenuWin.m_pAni[2]->SetLoopType(E_ANI_ONE, 0, 0, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
}