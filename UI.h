#pragma once
class CUI
{
public:
	CEMNumber* m_pDate;
	CEMNumber* m_pSkillTime;
	CEMNumber* m_pMineNum;
	CEMPlane* m_pDay;
	CEMPlane* m_pScore;
	CEMPlane* m_pKill;
	CEMPlane* m_pClear;
	CEMPlane* m_pUIBar;
	CEMPlane* m_pSkillBlock;

	CEMAnimation* m_pSkill;
	CHp m_CHp;

	int m_nSkillTime;
	int m_nSkill;
	int m_nDate;
	int m_nTime;
	int m_nMine;

	float m_fTime;
	float m_fAlpha;
	float m_fSize;
	float m_fXPos;
	
	bool m_bAlpha;
	bool m_bStart;
public:
	CUI();
	~CUI();
public:
	void Init();
	void NumIcon(CRootScene* pScene);
	void CreateObj(CRootScene* pScene);
	void Update();
	void ClearImageUpdate();
	void DayAlphaUpdate();
};