#pragma once
class CSoldier : public CUnit
{
public:
	CGrenade m_CGrenade;
public:
	stEMVec3	m_stClickDestPos;		// 마우스왼쪽 좌표 클릭 목적지
public:
	CSoldier();
	~CSoldier();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Move(float dt);
	virtual void Clipping();
	virtual void Ability();
};