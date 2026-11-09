#pragma once
//캐릭터 관리 클래스
class CHero
{
public:
	float m_fHitCtrlTime;
	float m_fShowCtrlTime;
	bool m_bShow;
	bool m_bUse;
	int m_nSkill;
	int m_nSkillTime;
	CEMAnimation* m_pAni;
public:
	CMan m_CMan;	//회사원
	CDoctor m_CDoctor;		//의사
	CSoldier m_CSoldier;	//군인
public:
	int m_nAttack;
public:
	CHero();
	~CHero();
public:
	void Init();
	void CreateObj(CRootScene* pScene, eCharacter eChar);
	void Update(float dt, eCharacter eChar);
	void See(stMouseInfo stPos, eCharacter eChar);
	void Hit();

	template<typename Hero>
	void HeroInfoUpdate(Hero cHero)
	{
		m_bUse = cHero.m_bUse;
		m_nSkill = cHero.m_nAmount;
		m_pAni = cHero.m_pAni;
		cHero.m_bHit = m_bShow;
		m_nSkillTime = (int)cHero.m_fSkillTime;
	}
};