#include "stdafx.h"
void CLogoScene::Enter(CSceneWork* pSceneWork)
{
	g_CInfo.m_CFog.Init();
	//====================================================
	D_MNG->CreateSound();
	
	g_CInfo.m_CFog.CreateObj(this);
	//g_CInfo.Zombie(this);
	g_CInfo.BackGround(this);
	m_BaseMenuWin.CreatePopupWindow(D_MNG->m_ClickSnd, 0, this, true);
	m_ExitPopupWin.CreatePopupWindow(D_MNG->m_ClickSnd, -3, this, false);
	m_SettingPopupWin.CreatePopupWindow(D_MNG->m_ClickSnd, -4, this, false);

}

void CLogoScene::Update(CSceneWork* pSceneWork, float dt)
{
	g_CInfo.m_CFog.Update(dt);
	g_CInfo.MoveBat();
	D_CAMERA->SetPos(270.0f, -135.0f, 260.0f);
	CRootScene::Update(pSceneWork, dt);
}

void CLogoScene::Render(CSceneWork* pSceneWork)
{
	m_ExitPopupWin.ESC();
	m_SettingPopupWin.ESC();
	CRootScene::Render(pSceneWork);
}

void CLogoScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CLogoScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}

}

void CLogoScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

	m_BaseMenuWin.OnMouseUpEvent(stPos, eButton);
	m_ExitPopupWin.OnMouseUpEvent(stPos, eButton);
	m_SettingPopupWin.OnMouseUpEvent(stPos, eButton);

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

void CLogoScene::MouseMoveEvent(stMouseInfo stPos)
{
	m_BaseMenuWin.OnMouseMoveEvent(stPos);
	m_ExitPopupWin.OnMouseMoveEvent(stPos);
	m_SettingPopupWin.OnMouseMoveEvent(stPos);
}

void CLogoScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{

}

HRESULT CLogoScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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