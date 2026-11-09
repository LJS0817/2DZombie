#pragma once
class CShadow : public CUnit
{
public:
	CEMPlane* m_pShadow[D_SHADOW_MAX];
public:
	CShadow()
	{

	}
	~CShadow()
	{

	}
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(CEMAnimation* pAni, int nIndex);
	virtual void Move(CEMAnimation* pAni, int nIndex);
	virtual void Enable(stEMVec3 stPos, int nIndex);
	virtual void Disable(int nIndex);
};