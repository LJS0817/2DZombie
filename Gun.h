#pragma once
class CGun : public CUnit
{
public:
	int m_nType;
	float m_fShowCtrlTime;
	float m_fHitCtrlTime;
public:
	CGun();
	~CGun();
public:
	virtual void Init();
	/*nType은 총 종류
	회사원: M4 = 0,
	엔지니어: M1014 = 1,
	군인: R4-C = 2,
	의사: MP5 = 3
	*/
	virtual void CreateObj(CRootScene* pScene, int nType);
	virtual void Update(float dt, stEMVec3 stHeroPos);
	virtual void Enable(stEMVec3 stPos);
	virtual void Disable();
	virtual void See(stMouseInfo stPos, stEMVec3 stHeroPos);
	void Hit();
};