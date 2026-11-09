#pragma once

#include "stdafx.h"


enum E_BTN_TYPE
{
	E_BTN,
	E_RADIO_BTN,
	E_CHECK_BTN
};

enum E_RADIO_ON_OFF
{
	E_OFF,
	E_ON
};

// 버튼 클래스 입니다 배경과 위에 글씨 때문에 배열 2개 잡음
class CBtn
{
private:
	E_BTN_TYPE m_eType;
	bool	   m_bRadioOnOff;	//ture -- > ON  flase --> OFF

public:
	CEMPlane * pUI[2];		// 버튼 배열 (배경plane, 글씨Plane)

public:
	CBtn()
	{
		Init();
	}

	~CBtn()
	{
		Init();
	}

	void Init()
	{
		m_eType = E_BTN;
		m_bRadioOnOff = true;

		for (int i = 0; i < 2; i++)
			pUI[i] = NULL;
	}

public:
	E_BTN_TYPE GetType() { return m_eType; }
	void SetType(E_BTN_TYPE eType);

	bool GetRadioOnOff() { return m_bRadioOnOff; }
	void SetRadioOnOff(bool bOnOff);

public:
	void SetPos(stEMVec3 stPos);
	void SetShow(bool bFlag);
	void SetColor(CEMColor color = CEMColor(1, 1, 1, 1));
};

class CPopupWinRoot
{
public:
	CEMPlane * m_pBg;					// 팝업윈도우 배경입니다.
	CEMPlane*		m_pEtcs[D_BTN_MAX];		// 기본 10개 입니다. 팝업윈도우안에 출력할 이미지 들입니다.
	CBtn			m_Btns[D_BTN_MAX];		// 기본 10개입니다. 팝업윈도우안에 만들어질 버튼들입니다.

	CRootScene*		m_pScene;				// 
	int				m_nLayer;				// 추가할 레이어

public:
	SAMPLE_HANDLE	m_ClickSnd;				// 클릭음
public:
	CEMPlane * m_pSelectPlane;			// 선택한 메뉴
	CEMPlane*		m_pPrevSelectPlane;		// 그 전에 선택한 메뉴

private:
	bool			m_bCollisionFlag;		// 충돌처리 할건지 말거지^^

public:
	bool GetCollisionFlag() { return m_bCollisionFlag; }
	void SetCollisionFlag(bool bFlag) { m_bCollisionFlag = bFlag; }

public:
	CPopupWinRoot()
	{
		Init();
	}

	virtual ~CPopupWinRoot()
	{
		Init();
	}

public:
	void Init()
	{
		m_bCollisionFlag = true;

		for (int i = 0; i < D_BTN_MAX; i++)
		{
			m_pEtcs[i] = NULL;
		}

		m_ClickSnd = NULL;
		m_nLayer = -1000;
		m_pSelectPlane = NULL;
		m_pPrevSelectPlane = NULL;

		m_pBg = NULL;
		m_pScene = NULL;
	}

	// 씬변경시^^
	virtual void Reset()
	{
		Init();
	}

	virtual void SetPos(stEMVec3 stPos);
	virtual void SetShow(bool bFlag);
	//virtual void SetRadioUpdate(int nRadioIndex, bool bFlag);
	virtual void SetColor(CEMColor color = CEMColor(1, 1, 1, 1));

public:
	virtual void CreatePopupWindow(SAMPLE_HANDLE ClickSnd, int nLayer, CRootScene* pScene, bool bShow = true);
	virtual void OnMouseMoveEvent(stMouseInfo stPos) = 0;
	virtual void OnMouseUpEvent(stMouseInfo stPos, enumMouseButton eButton) = 0;
};