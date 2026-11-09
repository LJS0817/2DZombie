#pragma once
class CBullet : public CUnit
{
public:
	CEMAnimation* m_pBullet[D_BULLET_MAX];
	CEMNumber* m_pBulletNum;
	SAMPLE_HANDLE m_Bulletsnd;
public:
	stEMVec3	m_stClickDestPos[D_BULLET_MAX];		// 마우스왼쪽 좌표 클릭 목적지
	CMagazine m_CMagazine;

	bool m_bReload;
	float m_fReload;
	int m_nBullet;
public:
	CBullet();
	~CBullet();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt, stEMVec3 stPos);
	virtual void Move(float dt);
	virtual void Clipping();
	virtual void Enable(int nIndex, stEMVec3 stPos);
	virtual void Disable(int nIndex);
	virtual void See(int nIndex);
	void ReloadBullet(stEMVec3 stPos);
	void CreateMagazine(stEMVec3 stPos);
};