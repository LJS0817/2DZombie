#pragma once
class CUnit
{
public:
	bool m_bUse;		//능력 사용 유무
	bool m_bHit;
	bool m_bMoveAni;
	float m_fDuration;			//지속시간
	float m_fSkillTime;			//쿨타임
	float m_fSpeed;			//이동속도
	int m_nAmount;			//사용가능한 횟수
	int m_nAttack;			//공격력

	CEMPlane* m_pPlane;
	CEMAnimation* m_pAni;
	SAMPLE_HANDLE m_Soundsnd;		//사운드
public:
	float m_fDot;						// 내적값
	float m_fRadian;					// 최종계산되어진 각도(도로변경하여넣어야함)
	float m_fDegree;					// 최종계산되어진 각도(디그리값)

	stEMVec3	m_stDestPos;			// 마우스 이동 목적지좌표(회전시사용)
	stEMVec3 m_stHeroDirVec3;			// 주인공 Up벡터
	stEMVec3 m_stHeroPosToDestPosDir;	// 주인공이 목적지를 바라보는 벡터 구하기
	stEMVec3 m_stHeroRightVec3;			// 주인공 우벡터 
public:
	CUnit();
	~CUnit();
public:
	virtual void Init();
	virtual void CreateObj(CRootScene* pScene);
	virtual void Update(float dt);
	virtual void Move(float dt);
	virtual void Clipping();
	virtual void Enable(stEMVec3 stPos, int nIndex);
	virtual void Disable(int nIndex);
	virtual void See(stMouseInfo stPos);
	virtual void Ability();
	virtual void MoveAnimation();
private:
	void StopHeroAnimation();
	void HeroAnimation();
};