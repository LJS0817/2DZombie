#include "stdafx.h"
CMap::CMap()
{
	Init();
}
CMap::~CMap()
{
	Init();
}
void CMap::Init()
{
	m_fSize = 5.0f;
	m_pMap = NULL;
	m_pLight = NULL;
}
void CMap::CreateObj(CRootScene* pScene)
{
	m_pLight = new CEMPlane();
	m_pLight->SetTexture("Data/Image/Map/Light_1.png");
	m_pLight->SetPos(260.0f, -150.0f, 0.0f);
	m_pLight->SetSize(m_fSize);
	m_pLight->SetBlend(true);
	m_pLight->SetFrstumCullingFlag(false);
	m_pLight->SetBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_DST_ALPHA);

	m_pMap = new CEMPlane();
	m_pMap->SetTexture("Data/Image/Map/1_1.png");
	m_pMap->SetPos(260.0f, -150.0f, 0.0f);
	m_pMap->SetSize(0.5f);
	m_pMap->SetBlend(true);
	m_pMap->SetFrstumCullingFlag(false);

	m_pLimitedMap = new CEMPlane();
	m_pLimitedMap->SetTexture("Data/Image/Map/Light.png");
	m_pLimitedMap->SetPos(260.0f, -150.0f, 0.0f);
	m_pLimitedMap->SetSize(0.5f);
	m_pLimitedMap->SetBlend(true);
	m_pLimitedMap->SetFrstumCullingFlag(false);
	m_pLimitedMap->SetBoundingBoxCalc(true);
	m_pLimitedMap->SetBoundingBox_LTLB_Size(120.0f);
	m_pLimitedMap->SetBoundingBox_RTRB_Size(-120.0f);
	m_pLimitedMap->SetBoundingBox_LTRT_Size(-210.0f);
	m_pLimitedMap->SetBoundingBox_LBRB_Size(210.0f);

	pScene->Commit(-2, "Light", m_pLight);
	pScene->Commit(-1, "LimitedMap", m_pLimitedMap);

	pScene->Commit(11, "Map", m_pMap);
}