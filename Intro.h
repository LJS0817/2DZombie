#pragma once

class CIntro : public CUnit
{
public:
	float m_fAlpha;
	float m_fTime;
	bool m_bMove;
	bool m_bSkip;
	stEMVec2 m_stPos;
	CEMAnimation* m_pEffect;
	CEMAnimation* m_pMap;
	CEMPlane* m_pText;
public:
	CIntro()
	{
		Init();
	}
	~CIntro()
	{

	}
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update();
	virtual void Enable();
	virtual void Disable();
	virtual void Move();
public:
	void Skip();
	void SkipText();
	void MapUpdate();
};