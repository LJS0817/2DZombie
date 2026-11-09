#pragma once
class CNormal_2 : public CUnit
{
public:
	CEMAnimation* m_pMonster[D_MONSTER_MAX];

	int m_nHp[D_MONSTER_MAX];					//체력
	int m_nAttack[D_MONSTER_MAX];			//공격력
public:
	CNormal_2();
	~CNormal_2();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene, int nIndex);
	virtual void Update(float dt, int nIndex, float fSpeed, stEMVec3 stHeroPos, bool bHit);
	virtual void Move(float dt, int nIndex, float fSpeed, stEMVec3 stHeroPos, bool bHit);
	virtual void Enable(int nIndex, stEMVec3 stPos);
	virtual void Disable(int nIndex);
	virtual void See(stEMVec3 stPos, int nIndex);
};