#pragma once

#include "stdafx.h"

class CLogoBase : public CPopupWinRoot
{
public:

public:
	CLogoBase()
	{

	}

	virtual ~CLogoBase()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
};