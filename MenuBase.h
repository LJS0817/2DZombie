#pragma once
class CMenuBase : public CPopupWinRoot
{
public:
	int m_nAniNum;
	CEMAnimation* m_pAni[3];
	CEMPlane* m_pPlane[2];
	CEMAnimation* m_pModeAni[2];
	SAMPLE_HANDLE m_PlaySnd;

public:
	CMenuBase()
	{
		m_nAniNum = 0;
		m_PlaySnd = NULL;
	}

	virtual ~CMenuBase()
	{

	}

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos);
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton);
public:
	void Left_Right();
};