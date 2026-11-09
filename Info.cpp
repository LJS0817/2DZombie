#include"stdafx.h"

void CInfo::NumInit()
{
	m_nMonsterHp = 0;
	m_bTurn = false;
	m_bClear = false;
	m_nHp = 3;
	m_nScore = 0;
	m_nKill = 0;
}
void CInfo::Spawn()
{
	m_stSpawn[0] = stEMVec3(630.0f, -374.0f, 0.0f);		//오른쪽 아래
	m_stSpawn[1] = stEMVec3(630.0f, 74.0f, 0.0f);			//오른쪽 위
	m_stSpawn[2] = stEMVec3(-125.0f, 74.0f, 0.0f);		//왼쪽 위
	m_stSpawn[3] = stEMVec3(-125.0f, -374.0f, 0.0f);	//왼쪽 아래

	m_stSpawn[4] = stEMVec3(30.0f, -150, 0.0f);	//왼쪽
	m_stSpawn[5] = stEMVec3(490.0f, -150, 0.0f);	//오른쪽
}
void CInfo::Num(CRootScene* pScene)
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());

	m_pNum = new CEMNumber(11);
	m_pNum->SetTexture(pScene, 11, "Data/Image/ui/Num/0.png", "Data/Image/ui/Num/1.png"
		, "Data/Image/ui/Num/2.png", "Data/Image/ui/Num/3.png", "Data/Image/ui/Num/4.png"
		, "Data/Image/ui/Num/5.png", "Data/Image/ui/Num/6.png", "Data/Image/ui/Num/7.png"
		, "Data/Image/ui/Num/8.png", "Data/Image/ui/Num/9.png", "Data/Image/ui/Num/10.png");
	m_pNum->SetPos(stPos.m_fX - 180.0f, stPos.m_fY + 130.0f, 0.0f);
	m_pNum->SetBlend(true);
	m_pNum->SetNumber(m_nScore);
	m_pNum->SetSize(0.14f, 0.14f);


	m_pKill = new CEMNumber(11);
	m_pKill->SetTexture(pScene, 11, "Data/Image/ui/Num/0.png", "Data/Image/ui/Num/1.png"
		, "Data/Image/ui/Num/2.png", "Data/Image/ui/Num/3.png", "Data/Image/ui/Num/4.png"
		, "Data/Image/ui/Num/5.png", "Data/Image/ui/Num/6.png", "Data/Image/ui/Num/7.png"
		, "Data/Image/ui/Num/8.png", "Data/Image/ui/Num/9.png", "Data/Image/ui/Num/10.png");
	m_pKill->SetPos(stPos.m_fX - 180.0f, stPos.m_fY + 110.0f, 0.0f);
	m_pKill->SetBlend(true);
	m_pKill->SetNumber(m_nKill);
	m_pKill->SetSize(0.14f, 0.14f);

	pScene->Commit(-10, "Score", m_pNum);
	pScene->Commit(-10, "Kill", m_pKill);
}
void CInfo::BackGround(CRootScene* pScene)
{
	m_pBackground = new CEMPlane();
	m_pBackground->SetTexture("Data/Image/ui/Background_4.png");
	m_pBackground->SetBlend(true);
	m_pBackground->SetFrstumCullingFlag(false);
	m_pBackground->SetBoundingBoxCalc(true);
	m_pBackground->SetPos(270.0f, -135.0f, 0.0f);
	m_pBackground->SetSize(0.4f, 0.45f);

	m_pBat = new CEMAnimation(7);
	m_pBat->SetPos(260.0f , -80.0f, 0.0f);
	m_pBat->SetTexture(pScene, 7, "Data/Image/ui/Bat/0.png", "Data/Image/ui/Bat/1.png", "Data/Image/ui/Bat/2.png",
		"Data/Image/ui/Bat/3.png", "Data/Image/ui/Bat/4.png", "Data/Image/ui/Bat/5.png", "Data/Image/ui/Bat/6.png");
	m_pBat->SetBlend(true);
	m_pBat->SetBoundingBoxCalc(true);
	m_pBat->SetSize(0.5f);
	m_pBat->SetTime(0.1f);

	pScene->Commit(1, "Bat", m_pBat);

	pScene->Commit(2, "Background_1", m_pBackground);
}
void CInfo::NumUpdate()
{
	stEMVec3 stPos(D_CAMERA->GetPosVec3());
	m_pNum->SetPos(stPos.m_fX - 168.0f, stPos.m_fY + 130.0f, 0.0f);

	m_pKill->SetPos(stPos.m_fX - 185.0f, stPos.m_fY + 110.0f, 0.0f);
	m_pNum->SetNumber(m_nScore);
	m_pKill->SetNumber(m_nKill);
}
void CInfo::MoveBat()
{
	//m_CFog.Update(D_WORLD->GetDeltaTime());
	if (m_stBatGoal == NULL)
	{
		m_stBatGoal.m_fX = CEMMath::RandomFloatInRange(50.0f, 400.0f);
		m_stBatGoal.m_fY = CEMMath::RandomFloatInRange(-50.0f, -250.0f);
		m_stBatGoal.m_fZ = 0.0f;
	}
	if (m_pBat->GetPosVec2().m_fX > m_stBatGoal.m_fX)
	{
		m_pBat->SetMirrorType(E_RIGHT_MIRROR);
	}
	else
	{
		m_pBat->SetMirrorType(E_LEFT_MIRROR);
	}
	stEMVec3 stCalsPos = m_pBat->GetPosVec3();
	stCalsPos = CEMMath::Lerp(stCalsPos, m_stBatGoal, D_WORLD->GetDeltaTime() * 0.5f);
	m_pBat->SetPos(stCalsPos);
	if (m_pBat->GetPosVec3().m_fX <= m_stBatGoal.m_fX + 20.0f && m_pBat->GetPosVec3().m_fX >= m_stBatGoal.m_fX - 20.0f)
	{
		if (m_pBat->GetPosVec3().m_fY <= m_stBatGoal.m_fY + 20.0f && m_pBat->GetPosVec3().m_fY >= m_stBatGoal.m_fY - 20.0f)
		{
			m_stBatGoal = NULL;
		}
	}
}