#include "../SDK/SDK.h"

#include "../Features/CameraWindow/CameraWindow.h"

MAKE_HOOK(CViewRender_RenderView, U::Memory.GetVFunc(I::ViewRender, 6), void,
	void* rcx, const CViewSetup& view, ClearFlags_t nClearFlags, RenderViewInfo_t whatToDraw)
{
	if (G::Unload)
		return;

	CALL_ORIGINAL(rcx, view, nClearFlags, whatToDraw);
	if (Vars::Visuals::UI::CleanScreenshots.Value && I::EngineClient->IsTakingScreenshot())
		return;

	F::CameraWindow.RenderView(rcx, view);
}