#pragma once
class CSpecial : public CUnit
{
public:
	stEMVec3 m_stDestination;
	int m_nHp;
	float m_fTime;
public:
	CSpecial()
	{
		Init();
	}
	~CSpecial()
	{
		Init();
	}
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(stEMVec3 stPos);
	virtual void Enable(stEMVec3 stPos);
	virtual void Disable();
	virtual void See(stEMVec3 stPos);
public:
	void CreateBullet(stEMVec3 stPos);
	void BulletDisable();
};