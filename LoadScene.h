#pragma once
#include "EM2DEngine.h"

class CLoadScene : public CRootScene, public UIEvent
{
public:
	CEMAnimation* m_pAni;
	CEMPlane* m_pPlane;
	CEMPlane* m_pGauge;
	CEMAnimation* m_pLoading;
	CEMPlane* m_pPlane_2;
	float m_fSize;
	float m_fTime;
	bool m_bTurn;
public:
	CLoadScene(void)
	{
		m_bTurn = false;
		m_fSize = 1.0f;
		m_fTime = 0.0f;
	};
	virtual ~CLoadScene(void)
	{

	};

public:
	virtual void Enter(CSceneWork* pSceneWork);							//!< 진입(로딩)
	virtual void Update(CSceneWork*, float dt);							//!< Update
	virtual void Render(CSceneWork*);										//!< Render
	virtual void Exit(CSceneWork* pSceneWork);							//!< 탈출(메모리 해제등)
	virtual void MouseDownEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
	virtual void MouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
	virtual void MouseMoveEvent(stMouseInfo stPos);								//!< 마우스 이동 이벤트
	virtual HRESULT WindowMessage(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//!< 윈도우 이벤트

	virtual void CALLBACK OnEvent(stdEMString sWindowName, enumDialogType eType, UINT id);
public:
	void ZombieDancing();
	void Loading();
};