#pragma once
class CHp : public CUnit
{
public:
	CEMAnimation* m_pIcon;
	float  m_fAlpha;
public:
	CHp();
	~CHp();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
};