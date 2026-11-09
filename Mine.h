#pragma once
class CMine : public CUnit
{
public:
	SAMPLE_HANDLE m_Explosionsnd;
public:
	CMine()
	{

	}
	~CMine()
	{

	}
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update();
	virtual void Enable(stEMVec3 stPos);
	virtual void Disable();
};