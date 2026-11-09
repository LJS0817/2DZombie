#pragma once

#include "EM2DEngine.h"

class CGameScene : public CRootScene
{
public:
	CShadow m_CShadow;
	CHero m_CHero;
	CMap m_CMap;
	CMonster m_CMonster;
	CBullet m_CBullet;
	CGun m_CGun;
	CEffect m_CEffect;
	CBlood m_CBlood;
	CUI m_CUI;
	CIntro m_CIntro;
	CMine m_CMine;
public:
	CPausePopup m_CPausePopupWin;
	CPauseSetting m_CSettingPopupWin;
	CPauseExit m_CExitPopupWin;
public:
	eCharacter m_eChar;
	stEMVec3 m_stDestPos;
	SAMPLE_HANDLE m_sndChange;
	SAMPLE_HANDLE m_sndClear;
	SAMPLE_HANDLE m_sndHeartBeat_1;
	SAMPLE_HANDLE m_sndHeartBeat_2;

	float m_fMonCtrlTime;
	float m_fRestTime;
	float m_fBulletTime;
	float m_fColisionTime;
	float m_fShakeCtrlTime;
	float m_fTime;
	float m_fBossTime;

	bool m_bShake;
	bool m_bFire;
	bool m_bChange;
	bool m_bReset;
	bool m_bPause;

	int m_nCount;
	int m_nRange;
	int m_nMonster;
	int m_nGoal;
public:
	CGameScene(void)
	{	
		Init();
	};
	virtual ~CGameScene(void)
	{
		//Init();
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
public:
	void Init();
	void BreakTime();
	void HeroInfoUpdate(float dt);
	void LightSize();
	void Reset();
	void CameraShake();
	void SkillUse();
	void Update_2(float dt);
	void MonsterDisable(int nIndex);
	void Cheat();
	//=============================
	void CreateEffect(stEMVec3 stPos);
	void CreateEffect_Hit(stEMVec3 stPos);
	void CreateShadow(stEMVec3 stPos, int nIndex);
	void CreateMine();
	//========================
	void ShadowUpdate();
	void BloodUpdate();
	void MonsterHpUpdate();
	void MonsterSound();
	//============================
	void CreateBullet();
	void CreateMonster();
	void BigSizeMonster();
	//=============================
	void Bullet_VS_MonsterColision();
	void Grenade_VS_MonsterColision();
	void Hero_VS_MonsterColision();
	void Mine_VS_MonsterColision();
	//=============================
	void Pause();
	void SoundStop();
	void End();
	void HeartBeat();
	//=============================
	void Ending();
	void Story(float dt);
	void Challenge(float dt);
};