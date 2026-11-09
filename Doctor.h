#pragma once
class CDoctor : public CUnit
{
public:
	CEMAnimation* m_pHeal;
	float m_fHpCtrlTime;
public:
	CDoctor();
	~CDoctor();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Move(float dt);
	virtual void Clipping();
	virtual void Ability();
	void CalcTime();
};