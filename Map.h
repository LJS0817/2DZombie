#pragma once
class CMap
{
public:
	float m_fSize;
	CEMPlane* m_pLight;			//불빛
	CEMPlane* m_pMap;		//배경
	CEMPlane* m_pLimitedMap;		//배경 제한
public:
	CMap();
	~CMap();
public:
	void CreateObj(CRootScene* pScene);
	void Init();
};