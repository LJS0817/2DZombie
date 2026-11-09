#pragma once

#include "EM2DEngine.h"

class CMethodScene : public CRootScene
{
public:
	CEMPlane* m_pBack;
public:
	float m_fTime;
public:
	CMethodScene(void)
	{	
		m_fTime = 0.0f;
	};
	virtual ~CMethodScene(void)
	{
		
	};

public:
	virtual void Enter			(CSceneWork* pSceneWork);							//!< 진입(로딩)
	virtual void Update			(CSceneWork*, float dt);							//!< Update
	virtual void Render			(CSceneWork*);										//!< Render
	virtual void Exit			(CSceneWork* pSceneWork);							//!< 탈출(메모리 해제등)
	virtual void MouseDownEvent (stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 다운 이벤트
	virtual void MouseUpEvent	(stMouseInfo stPos, enumMouseButton eButton);		//!< 마우스 업 이벤트
	virtual void MouseMoveEvent (stMouseInfo stPos);								//!< 마우스 이동 이벤트
	virtual HRESULT WindowMessage	(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//!< 윈도우 이벤트
};