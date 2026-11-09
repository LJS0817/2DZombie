#pragma once
#include "stdafx.h"

class CLogoExit : public CPopupWinRoot
{



public:
	CLogoExit()
	{
	}

	virtual ~CLogoExit()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
public:
	void ESC();
};