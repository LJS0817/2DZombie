#pragma once

typedef enum enumcharacter
{
	E_BUSINESSMAN,
	E_SOLDIER,
	E_DOCTOR,
}eCharacter;

typedef enum enumzombie
{
	E_NORMAL_1,
	E_NORMAL_2,
	E_NORMAL_3,
	E_SPITTER
}eZombie;

//////////////////////////////////////////////////////////////////

#define D_BTN_MAX 10
#define D_MNG	CMng::Instance()

#include "EM2DEngine.h"

#include "Define.h"

#include "Mng.h"
#include "Fog.h"
#include "Info.h"

extern CInfo g_CInfo;

#include "PopupWinRoot.h"
#include "LogoBase.h"
#include "LogoExit.h"
#include "LogoSetting.h"
#include "MenuBase.h"
#include "PauseExit.h"
#include "PausePopup.h"
#include "PauseSetting.h"
#include "ResultBase.h"
#include "ResultExit.h"


#include "Unit.h"
#include "Hp.h"
#include "Intro.h"

#include "UI.h"

#include "Magazine.h"
#include "Bullet.h"
#include "Mine.h"
#include "Grenade.h"
#include "Gun.h"

#include "Effect.h"
#include "Shadow.h"
#include "Blood.h"
#include "Man.h"
#include "Doctor.h"
#include "Soldier.h"
#include "Hero.h"

#include "Nor_1.h"
#include "Nor_2.h"
#include "Nor_3.h"
#include "Special.h"

#include "Map.h"
#include "Monster.h"

#include "LoadScene.h"
#include "LogoScene.h"
#include "MenuScene.h"
#include "MethodScene.h"
#include "GameScene.h"
#include "ResultScene.h"
