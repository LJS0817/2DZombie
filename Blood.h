#pragma once
class CBlood : public CUnit
{
public:
	CEMAnimation* m_pAni[D_BLOOD_MAX];

public:
	CBlood()
	{
		Init();
	}
	~CBlood()
	{
		Init();
	}
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(stEMVec3 stPos);
	virtual void Enable(stEMVec3 stPos, int nIndex);
	virtual void Disable(int nIndex);
	virtual void See(stEMVec3 stPos);
};