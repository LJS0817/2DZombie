#pragma once
#include "stdafx.h"

class CInfo
{
public:
	int m_nMonsterHp;
	int m_nScore;
	int m_nKill;
	int m_nHp;
	bool m_bTurn;
	bool m_bClear;
	bool m_bMode;		// 0 = 엔딩 X, 1 = 엔딩 O 
public:
	eCharacter m_eHero;		//캐릭터 정보
	eZombie m_eMonster[D_MONSTER_MAX];
	stEMVec3 m_stSpawn[D_SPAWN_MAX];			//스폰 지역 정보
	stEMVec3 m_stBatGoal;
	CEMNumber* m_pNum;
	CEMNumber* m_pKill;
	CEMPlane* m_pBackground;
	CEMAnimation* m_pBat;
public:
	CFog m_CFog;
public:
	void NumInit();
	void Spawn();
	void Num(CRootScene* pScene);
	void Zombie(CRootScene* pScene);
	void NumUpdate();
	void BackGround(CRootScene* pScene);
	void MoveBat();
public:
	CInfo(void)
	{

	};
	virtual ~CInfo(void)
	{

	};

};
