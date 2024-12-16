#include "Spectate.h"

void CSpectate::NetUpdateEnd(CTFPlayer* pLocal)
{
	if (!pLocal)
		return;

	auto pEntity = I::ClientEntityList->GetClientEntity(I::EngineClient->GetPlayerForUserID(m_iTarget))->As<CTFPlayer>();
	if (!pEntity)
	{
		SDK::Output("Spectate", "Null entity", { 175, 150, 255, 255 }, true, false, false, true);
		m_iTarget = -1;
	}
	else if (pEntity == pLocal)
		m_iTarget = -1;
	else if (m_iTarget == -1)
	{
		if (pLocal->IsAlive())
			pLocal->m_iObserverMode() = OBS_MODE_NONE;
		return;
	}

	pLocal->m_iObserverMode() = Vars::Visuals::ThirdPerson::Enabled.Value ? OBS_MODE_THIRDPERSON : OBS_MODE_FIRSTPERSON;
	pLocal->m_hObserverTarget().Set(pEntity);
	pLocal->m_vecViewOffset() = pEntity->GetViewOffset();
	Vars::Visuals::ThirdPerson::Enabled.Value ? I::Input->CAM_ToThirdPerson() : I::Input->CAM_ToFirstPerson();
}

void CSpectate::CreateMove(CTFPlayer* pLocal, CUserCmd* pCmd)
{
	int iButtons = pCmd->buttons & ~IN_SCORE;
	if (iButtons && !I::EngineClient->IsPlayingTimeDemo())
		m_iTarget = -1;
	if (F::Spectate.m_iTarget == -1)
		m_vOldView = pCmd->viewangles;
	else
		pCmd->viewangles = F::Spectate.m_vOldView;
}

void CSpectate::SetTarget(int iTarget)
{
	m_iTarget = m_iTarget == iTarget ? -1 : iTarget;
}