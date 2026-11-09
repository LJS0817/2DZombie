#pragma once

#include "stdafx.h"

/**
@file    : Mng.h
@author  : hwang
@version : 1.0f
@brief   : 메니져 클래스
*/
class CMng
{
private:
	float	m_fMusicVolume;		// 배경음
	float	m_fSoundVolume;		// 효과음
	bool	m_bSndLoading;		// 로딩

public:
	SAMPLE_HANDLE m_BGMSnd;		// 배경음
	SAMPLE_HANDLE m_ClickSnd;		// 클릭음

public:


private:
	CMng()
	{
		m_bSndLoading = false;
		m_BGMSnd = NULL;
		m_ClickSnd = NULL;
		m_fSoundVolume = 1.0f;
		m_fMusicVolume = 1.0f;
	}

public:
	static CMng* Instance();

	~CMng()
	{

	}

public:
	void CreateSound();

public:
	float GetMusicVolume() { return m_fMusicVolume; }
	void SetMusicVolume(float fVolume);

	float GetSoundVolume() { return m_fSoundVolume; }
	void SetSoundVolume(float fVolume);
};
