#include "stdafx.h"
void CLoadScene::Enter(CSceneWork* pSceneWork)
{
	m_pAni = new CEMAnimation(14);
	m_pAni->SetTexture(this, 14, "Data/Image/ui/Zombie/0.png", "Data/Image/ui/Zombie/1.png", "Data/Image/ui/Zombie/2.png"
		, "Data/Image/ui/Zombie/1.png", "Data/Image/ui/Zombie/0.png", "Data/Image/ui/Zombie/5.png", "Data/Image/ui/Zombie/5.png"
		, "Data/Image/ui/Zombie/0.png", "Data/Image/ui/Zombie/1.png", "Data/Image/ui/Zombie/2.png", "Data/Image/ui/Zombie/1.png"
		, "Data/Image/ui/Zombie/0.png", "Data/Image/ui/Zombie/5.png", "Data/Image/ui/Zombie/5.png");
	m_pAni->SetPos(250.0f, -150.0f, 0.0f);
	m_pAni->SetTime(0.115f);
	m_pAni->SetSize(0.7f);
	m_pAni->SetBlend(true);

	m_pPlane = new CEMPlane();
	m_pPlane->SetTexture("Data/Image/Map/1_2.png");
	m_pPlane->SetPos(250.0f, -90.0f, 0.0f);
	m_pPlane->SetSize(0.7f);
	m_pPlane->SetBlend(true);
	m_pPlane->SetFrstumCullingFlag(false);

	m_pGauge = new CEMPlane();
	m_pGauge->SetTexture("Data/Image/ui/gaugebar.png");
	m_pGauge->SetPos(260.0f, -243.0f, 0.0f);
	m_pGauge->SetBlend(true);
	m_pGauge->SetFrstumCullingFlag(false);

	m_pPlane_2 = new CEMPlane();
	m_pPlane_2->SetTexture("Data/Image/ui/gaugebar_On_1.png");
	m_pPlane_2->SetPos(414.0f, -242.0f, 0.0f);
	m_pPlane_2->SetOffset(-156.0f, 0.0f);
	m_pPlane_2->SetBlend(true);
	m_pPlane_2->SetFrstumCullingFlag(false);

	m_pLoading = new CEMAnimation(11);
	m_pLoading->SetTexture(this, 11, "Data/Image/ui/Load/Load.png", "Data/Image/ui/Load/Load_1.png", "Data/Image/ui/Load/Load_2.png", "Data/Image/ui/Load/Load_3.png"
		, "Data/Image/ui/Load/Load_4.png", "Data/Image/ui/Load/Load_5.png", "Data/Image/ui/Load/Load_6.png", "Data/Image/ui/Load/Load_7.png", "Data/Image/ui/Load/Load_8.png"
		, "Data/Image/ui/Load/Load_9.png", "Data/Image/ui/Load/Load_10.png");
	m_pLoading->SetPos(260.0f, -240.0f, 0.0f);
	m_pLoading->SetTime(0.15f);
	m_pLoading->SetSize(0.5f);
	m_pLoading->SetBlend(true);
	m_pLoading->SetFrstumCullingFlag(false);


	Commit(-2, "gaugebar_On", m_pPlane_2);
	//Commit(-1, "Loading", m_pLoading);
	Commit(0, "Gauge", m_pGauge);
	Commit(9, "LoadMap", m_pPlane);
	Commit(1, "Zombie", m_pAni);
}

void CLoadScene::Update(CSceneWork* pSceneWork, float dt)
{
	ZombieDancing();
	Loading();
	D_CAMERA->SetPos(270.0f, -135.0f, 260.0f);
	CRootScene::Update(pSceneWork, dt);
}

void CLoadScene::Render(CSceneWork* pSceneWork)
{
	CRootScene::Render(pSceneWork);
}

void CLoadScene::Exit(CSceneWork* pSceneWork)
{
	Destroy();
}

void CLoadScene::MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton)
{

	switch (eButton)
	{
	case E_MOUSE_LEFT:
	{


	}break;
	}

}

void CLoadScene::MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton)
{

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

void CLoadScene::MouseMoveEvent(stMouseInfo stPos)
{

}

void CLoadScene::OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id)
{

}

HRESULT CLoadScene::WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
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

void CLoadScene::ZombieDancing()
{
	if (m_bTurn)
	{
		if (m_pAni->GetCurFrameNumber() > 12)
		{
			m_pAni->SetPos(263.0f, -150.0f, 0.0f);
			m_pAni->SetMirrorType(E_LEFT_MIRROR);
			m_pAni->SetLoopType(E_ANI_LOOP, 0, 13);
			m_bTurn = false;
		}
	}
	else
	{
		if (m_pAni->GetCurFrameNumber() > 5)
		{
			m_pAni->SetPos(250.0f, -150.0f, 0.0f);
			m_pAni->SetMirrorType(E_RIGHT_MIRROR);
			m_bTurn = true;
		}
	}
}

void CLoadScene::Loading()
{
	m_fTime += D_WORLD->GetDeltaTime();
	if (m_fTime >= 0.02f)
	{
		m_fTime = 0.0f;
		m_fSize -= 0.004f;

		m_pPlane_2->SetSize(m_fSize, 1.0f);
	}
	if (m_fSize <= 0.0f)
	{
		D_SCENE->ChangeScene("logo");
	}
}