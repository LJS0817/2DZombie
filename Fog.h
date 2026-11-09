#pragma once
class CFog
{
public:
	CEMAnimation* m_pAni;
	CEMPlane* m_pFog[67];
	int m_nIndex;
	bool m_bUse;
	float m_fTime;
public:
	CFog();
	~CFog();
public:
	void Init();
	void CreateObj(CRootScene* pScene);
	void Update(float dt);
};