#pragma once
class CMagazine : public CUnit
{
public:
	CEMPlane* m_pMagazine;
	float m_fTime;
public:
	CMagazine();
	~CMagazine();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Enable(stEMVec3 stPos);
	virtual void Disable();
};