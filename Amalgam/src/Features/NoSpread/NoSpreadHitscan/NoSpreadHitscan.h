#pragma once
#include "../../../SDK/SDK.h"

class CNoSpreadHitscan
{
private:
	int GetSeed(CUserCmd* pCmd);
	float CalcMantissaStep(float val);
	std::string GetFormat(int m_ServerTime);

	bool m_bWaitingForPlayerPerf = false;
	int m_bSynced = 0;
	double m_dRequestTime = 0.0;
	float m_flServerTime = 0.f;
	double m_dTimeDelta = 0.0;
	std::deque<double> m_vTimeDeltas = {};

public:
	void Reset();
	bool ShouldRun(CTFPlayer* pLocal, CTFWeaponBase* pWeapon, bool bCreateMove = false);

	void AskForPlayerPerf();
	bool ParsePlayerPerf(bf_read& msgData);

	void Run(CTFPlayer* pLocal, CTFWeaponBase* pWeapon, CUserCmd* pCmd);
	void Draw(CTFPlayer* pLocal);

	int m_iSeed = 0;
	float m_flMantissaStep = 0.f;
};

ADD_FEATURE(CNoSpreadHitscan, NoSpreadHitscan)