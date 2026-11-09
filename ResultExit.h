#pragma once

#include "stdafx.h"

class CResultExit : public CPopupWinRoot
{



public:
	CResultExit()
	{
	}

	virtual ~CResultExit()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
public:
	void ESC();
};