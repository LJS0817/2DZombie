#pragma once
class CGrenade : public CUnit
{
public:
	CEMAnimation* m_pMissile;

	SAMPLE_HANDLE m_Explosionsnd;		// 터지는 소리
public:
	stEMVec3	m_stClickDestPos;		// 마우스왼쪽 좌표 클릭 목적지
public:
	CGrenade();
	~CGrenade();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Move(float dt);
	virtual void Clipping();
	virtual void Enable(stEMVec3 stPos, stEMVec3 stClickPos);
	virtual void Disable();
public:
	//void CreateEffect();
};