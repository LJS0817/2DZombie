#include "stdafx.h"

void CMethodScene::Enter(CSceneWork* pSceneWork)
{
	g_CInfo.m_CFog.Init();
	D_WORLD->SetBackColor(CEMColor(0.0f, 0.0f, 0.0f));

	m_pBack = new CEMPlane();
	m_pBack->SetTexture("Data/Image/ui/Back.png");
	m_pBack->SetBlend(true);
	m_pBack->SetFrstumCullingFlag(false);
	m_pBack->SetPos(270.0f, -130.0f, 0.0f);
	m_pBack->SetSize(0.43f);

	Commit(2, "BackGround", m_pBack);
}

void CMethodScene::Update(CSceneWork* pSceneWork, float dt)
{
	m_fTime += dt;
	if (m_fTime >= 5.0f)
	{
		m_fTime = 0.0f;
		D_SCENE->ChangeScene("game");
	}

	D_CAMERA->SetPos(270.0f, -135.0f, 260.0f);

	CRootScene::Update(pSceneWork, dt);
}

void CMethodScene::Render(CSceneWork* pSceneWork)
{


	CRootScene::Render(pSceneWork);
}

void CMethodScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CMethodScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{
	int x = 0;
	switch(eButton)
	{
 		case E_MOUSE_LEFT:
				x = 0;
	 			break;
		case E_MOUSE_RIGHT:
				x = 0;
				break;
	}	


}

void CMethodScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

}

void CMethodScene::MouseMoveEvent(stMouseInfo stPos)
{

}

HRESULT CMethodScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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