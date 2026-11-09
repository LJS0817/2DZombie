#include "stdafx.h"
CMagazine::CMagazine()
{
	Init();
}
CMagazine::~CMagazine()
{
	Init();
}
void CMagazine::Init()
{
	m_fTime = 0.0f;
}
void CMagazine::CreateObj(CRootScene* pScene)
{
	m_pMagazine = new CEMPlane();
	m_pMagazine->SetPos(
		000.0f, -1000.0f, 0.0f);
	m_pMagazine->SetTexture("Data/Image/Effect/Magazine.png");
	m_pMagazine->SetSize(0.3f);
	m_pMagazine->SetBlend(true);
	m_pMagazine->SetBackFaceCulling(true);
	m_pMagazine->SetShow(false);
	m_pMagazine->SetBoundingBoxCalc(true);
	m_pMagazine->SetFrstumCullingFlag(false);

	pScene->Commit(7, "Magazine", m_pMagazine);
}
void CMagazine::Update(float dt)
{
	if (m_pMagazine->GetShow() == true)
	{
		m_fTime += dt;
		if (m_fTime >= 2.0f)
		{
			m_fTime = 0.0f;
			Disable();
		}
	}
}

void CMagazine::Enable(stEMVec3 stPos)
{
	m_pMagazine->SetShow(true);
	m_pMagazine->SetPos(stPos.m_fX, stPos.m_fY, stPos.m_fZ);
}

void CMagazine::Disable()
{
	m_pMagazine->SetShow(false);
	m_pMagazine->SetPos(-1000.0f, -1000.0f, 0.0f);
}