#pragma once
#include "../../../Utils/Feature/Feature.h"
#include "../../Definitions/Types.h"
#include <unordered_map>

struct DormantData
{
	Vec3 Location;
	float LastUpdate = 0.f;
};

class CDormancy
{
public:
	std::unordered_map<int, DormantData> m_mDormancy;
	bool GetDormancy(int iIndex)
	{
		return m_mDormancy.contains(iIndex);
	}

	Vec3 GetDormancyPosition(int iIndex)
	{
		return m_mDormancy[iIndex].Location;
	}
};

ADD_FEATURE_CUSTOM(CDormancy, Dormancy, H)