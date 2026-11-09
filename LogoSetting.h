#pragma once

#include "stdafx.h"

class CLogoSetting : public CPopupWinRoot
{



public:
	CLogoSetting()
	{
	}

	virtual ~CLogoSetting()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
	void ESC();
};