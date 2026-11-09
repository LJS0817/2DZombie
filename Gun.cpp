#include "stdafx.h"
CGun::CGun()
{
	Init();
}
CGun::~CGun()
{
	Init();
}
void CGun::Init()
{
	m_fHitCtrlTime = 0.0f;
	m_fShowCtrlTime = 0.0f;
	m_bHit = false;
	m_nType = 0;
	m_fSpeed = 0.0f;
	//m_pAni = NULL;		//m_pAni로 총 관리
	//m_pPlane = NULL;

	m_stDestPos = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroDirVec3 = stEMVec3(0.0f, 1.0f, 0.0f);
	m_stHeroPosToDestPosDir = stEMVec3(0.0f, 0.0f, 0.0f);
	m_stHeroRightVec3 = stEMVec3(0.0f, 1.0f, 0.0f);

	m_fDot = 0.0f;
	m_fRadian = 0.0f;
}
void CGun::CreateObj(CRootScene* pScene,  int nType)
{
	m_pAni = new CEMAnimation(8);
	m_pAni->SetTexture(pScene, 8,  "Data/Image/Gun/0.png", "Data/Image/Gun/1.png"
		, "Data/Image/Gun/2.png", "Data/Image/Gun/3.png", "Data/Image/Gun/4.png", "Data/Image/Gun/5.png", "Data/Image/Gun/6.png", "Data/Image/Gun/6.png");
	m_pAni->SetPos(260.0f, -150.0f, 0.0f);
	m_pAni->SetSize(0.2f, 0.2f);
	m_pAni->SetOffset(0, 49);
	m_nType = nType;
	m_pAni->SetBoundingBoxCalc(true);
	m_pAni->SetFrstumCullingFlag(false);
	m_pAni->SetLoopType(E_ANI_ONE, m_nType, m_nType, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
	m_pAni->SetBlend(true);
	
	pScene->Commit(-2, "Gun", m_pAni);
}
void CGun::Update(float dt, stEMVec3 stHeroPos)
{
	m_pAni->SetPos(stHeroPos.m_fX, stHeroPos.m_fY - 5.0f, stHeroPos.m_fZ);
	Hit();
}
void CGun::Enable(stEMVec3 stPos)
{

}
void CGun::Disable()
{

}
void CGun::See(stMouseInfo stPos, stEMVec3 stHeroPos)
{
	stEMVec2 stDesPos(0.0f, 0.0f);

	// 마우스 좌표를 월드 좌표로 변환합니다.^^
	stDesPos = CEMMath::ScreenToWorld(stPos.m_nX, stPos.m_nY);

	m_stDestPos = stEMVec3(stDesPos.m_fX, stDesPos.m_fY, 0.0f);

	// 방향벡터 = 목적지 벡터 - 주인공 벡터
	m_stHeroPosToDestPosDir = m_stDestPos - m_pAni->GetPosVec3();

	// 단위벡터로 변경
	//방향만 나옴
	m_stHeroPosToDestPosDir.Normalize();
	m_stHeroDirVec3.Normalize();
	// 내적 계산
	m_fDot = stEMVec3::Dot(m_stHeroDirVec3, m_stHeroPosToDestPosDir);

	// 각도 구하기^^
	m_fRadian = (float)acos(m_fDot);

	// 주인공의 우향? 벡터 구하기
	m_stHeroRightVec3 = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));			//외적
	float fDotProduct = stEMVec3::Dot(m_stHeroRightVec3, m_stHeroPosToDestPosDir);			//양 옆 구분 내적
	/*			     0
				    ㅣ
	 1 --------+---------- -1
				    ㅣ
					 0
	*/

	stEMVec3 stCross = m_stHeroDirVec3.Cross(stEMVec3(0.0f, 0.0f, -1.0f));			//외적 
	stEMVec3 stTemp(stCross.m_fY, stCross.m_fX, stCross.m_fZ);		//X축 Y축 바꿈
	float fUpDot = stEMVec3::Dot(stTemp, m_stHeroPosToDestPosDir);		//위 아래 구분 내적

	/*			    -1
					ㅣ
	 0 --------+---------- 0
					ㅣ
					 1
	*/

	if (fDotProduct > 0.5f)			//왼쪽 보고있을 때
	{
		m_fDegree = CEMMath::ToDegrees(m_fRadian);
		//m_pAni->SetZRot(CEMMath::ToDegrees(m_fRadian));
		m_pAni->SetLoopType(E_ANI_ONE, m_nType + 1, m_nType + 1, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		m_pAni->SetMirrorType(E_RIGHT_MIRROR);
	}
	else
	{
		if (fDotProduct > 0.0f)			//정면 왼쪽 아래
		{
			m_fDegree = CEMMath::ToDegrees(m_fRadian);
			m_pAni->SetMirrorType(E_RIGHT_MIRROR);
			m_pAni->SetLoopType(E_ANI_ONE, m_nType, m_nType, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
		}
		if (fDotProduct < -0.5f)			// 오른쪽 보고있을 때
		{
			m_fDegree = CEMMath::ToDegrees(-m_fRadian);
			m_pAni->SetLoopType(E_ANI_ONE, m_nType + 1, m_nType + 1, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
			m_pAni->SetMirrorType(E_LEFT_MIRROR);
		}
		else
		{
			if (fDotProduct < 0.0f)			//정면 오른쪽 아래
			{
				m_pAni->SetMirrorType(E_RIGHT_MIRROR);
				m_pAni->SetLoopType(E_ANI_ONE, m_nType, m_nType, E_ANI_ENDING_TYPE_LASTFRAMEOUTPUT);
				m_fDegree = CEMMath::ToDegrees(-m_fRadian);
			}
			if (fUpDot < -0.5f)		//뒤 돌았을 때
			{
				m_pAni->SetLoopType(E_ANI_ONE, 6, 6, E_ANI_ENDING_TYPE_SHOW_FALSE);
			}
		}
	}
	m_pAni->SetZRot(m_fDegree);
}

void CGun::Hit()
{
	if (m_bHit)
	{
		m_fHitCtrlTime += D_WORLD->GetDeltaTime();
		m_fShowCtrlTime += D_WORLD->GetDeltaTime();
		if (m_fHitCtrlTime >= 0.2f)
		{
			m_pAni->SetShow(!m_pAni->GetShow());
			m_fHitCtrlTime = 0.0f;
		}
		if (m_fShowCtrlTime >= 0.6f)
		{
			m_fShowCtrlTime = 0.0f;
			m_pAni->SetShow(true);
			m_bHit = false;
		}
	}
	else
	{
		if (m_pAni->GetCurFrameNumber() != 6)
		{
			if (!m_pAni->GetShow())
			{
				m_pAni->SetShow(true);
			}
		}
	}
}