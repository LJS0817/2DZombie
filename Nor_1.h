#pragma once
class CNormal_1 : public CUnit
{
public:
	CEMAnimation* m_pMonster[D_MONSTER_MAX];

	int m_nHp[D_MONSTER_MAX];					//체력
	int m_nAttack[D_MONSTER_MAX];			//공격력

	//stEMVec3 m_stHeroDirVec3[D_MONSTER_MAX];			// 주인공 Up벡터
	//stEMVec3 m_stHeroPosToDestPosDir[D_MONSTER_MAX];	// 주인공이 목적지를 바라보는 벡터 구하기
	//stEMVec3 m_stHeroRightVec3[D_MONSTER_MAX];			// 주인공 우벡터 
public:
	CNormal_1();
	~CNormal_1();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene, int nIndex);
	virtual void Update(float dt, int nIndex, float fSpeed, stEMVec3 stHeroPos, bool bHit);
	virtual void Move(float dt, int nIndex, float fSpeed, stEMVec3 stHeroPos, bool bHit);
	virtual void Enable(int nIndex, stEMVec3 stPos);
	virtual void Disable(int nIndex);
	virtual void See(stEMVec3 stPos, int nIndex);
};