#pragma once

#include "stdafx.h"

class CResultBase : public CPopupWinRoot
{
public:
	CEMAnimation* m_pAni;


public:
	CResultBase()
	{
	}

	virtual ~CResultBase()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};