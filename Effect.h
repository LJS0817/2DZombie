#pragma once
class CEffect : public CUnit
{
public:
	CEMAnimation* m_pEffect[D_EFFECT_MAX];

	float m_fEffectTime[D_EFFECT_MAX];
	float m_fAlpha[D_EFFECT_MAX];
	bool m_bDisappear[D_EFFECT_MAX];
public:
	CEffect();
	~CEffect();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Enable(stEMVec3 stPos, int nIndex);
	virtual void Disable(int nIndex);
};