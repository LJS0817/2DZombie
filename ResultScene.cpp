#include "stdafx.h"
void CResultScene::Enter(CSceneWork* pSceneWork)
{
	D_WORLD->SetBackColor(CEMColor(255, 255, 255));
	//====================================================

	D_MNG->CreateSound();
	g_CInfo.m_CFog.CreateObj(this);
	g_CInfo.BackGround(this);
	m_BaseMenuWin.CreatePopupWindow(D_MNG->m_ClickSnd, 0, this, true);
	m_ExitPopupWin.CreatePopupWindow(D_MNG->m_ClickSnd, -11, this, false);
}

void CResultScene::Update(CSceneWork* pSceneWork, float dt)
{
	g_CInfo.MoveBat();
	g_CInfo.m_CFog.Update(dt);
	D_CAMERA->SetPos(270.0f, -135.0f, 260.0f);
	CRootScene::Update(pSceneWork, dt);
}

void CResultScene::Render(CSceneWork* pSceneWork)
{
	m_ExitPopupWin.ESC();
	CRootScene::Render(pSceneWork);
}

void CResultScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CResultScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{ 
	int x = 0;
	switch(eButton)
	{
	case E_MOUSE_LEFT:
		x = 0;
		break;
	case E_MOUSE_RIGHT:
		x = 5;
		break;
	}	


}
void CResultScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

	m_BaseMenuWin.OnMouseUpEvent(stPos, eButton);
	m_ExitPopupWin.OnMouseUpEvent(stPos, eButton);

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

void CResultScene::MouseMoveEvent(stMouseInfo stPos)
{
	m_BaseMenuWin.OnMouseMoveEvent(stPos);
	m_ExitPopupWin.OnMouseMoveEvent(stPos);
}

HRESULT CResultScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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
void CResultScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{

}