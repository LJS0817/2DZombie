#include "stdafx.h"


CMng* CMng::Instance()
{
	static CMng instance;
	return &instance;
}

void CMng::CreateSound()
{
	if (!m_bSndLoading)
	{
		//====================================================
		// »ç¿îµå 
		m_BGMSnd = D_SOUND->FileOpen("Data/sound/0.mp3");
		m_ClickSnd = D_SOUND->FileOpen("Data/sound/click.ogg");

		D_SOUND->Play(m_BGMSnd, D_MNG->GetMusicVolume(), true);

		m_bSndLoading = true;
	}
}

void CMng::SetMusicVolume(float fVolume)
{
	m_fMusicVolume = fVolume;
}

void CMng::SetSoundVolume(float fVolume)
{
	m_fSoundVolume = fVolume;
}