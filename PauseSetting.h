#pragma once

#include "stdafx.h"

class CPauseSetting : public CPopupWinRoot
{



public:
	CPauseSetting()
	{
	}

	virtual ~CPauseSetting()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);

public:
	void PopupUpdate();
	void ESC();
};