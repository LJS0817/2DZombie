#pragma once
class CMan : public CUnit
{
public:
	CEMAnimation* m_pRange;
	int m_nHp;
public:
	CMan();
	~CMan();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Move(float dt);
	virtual void Clipping();
	virtual void Ability();
};