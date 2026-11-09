#pragma once
class CMonster
{
public:
	CEMAnimation* m_pMonster[D_MONSTER_MAX];

	stEMVec3 m_stPos[D_MONSTER_MAX];

	float m_fTime[D_MONSTER_MAX];
	float m_fSpeed[D_MONSTER_MAX];
	bool m_bHit[D_MONSTER_MAX];
	int m_nHp[D_MONSTER_MAX];					//체력
	int m_nAttack[D_MONSTER_MAX];			//공격력
public:
	CNormal_1 m_CNor_1;
	CNormal_2 m_CNor_2;
	CNormal_3 m_CNor_3;
	CSpecial m_CSpecial;
public:
	SAMPLE_HANDLE m_sndDead;
	SAMPLE_HANDLE m_sndDead_2;
	SAMPLE_HANDLE m_sndDead_3;
	SAMPLE_HANDLE m_sndDead2;
public:
	CMonster();
	~CMonster();
public:
	void Init();
	void CreateObj(CRootScene* pScene);
	void Update(float dt, stEMVec3 stHeroPos);
	void Enable(int nIndex, stEMVec3 stPos);
	void Disable(int nIndex);
	void CalcTime();
};