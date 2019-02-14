#pragma once

#include "d3d9_device_child.h"

namespace dxvk {

  class Direct3DSurface9;

  using Direct3DSwapChain9ExBase = Direct3DDeviceChild9<IDirect3DSwapChain9Ex>;
  class Direct3DSwapChain9Ex final : public Direct3DSwapChain9ExBase {

  public:

    Direct3DSwapChain9Ex(Direct3DDevice9Ex* device, D3DPRESENT_PARAMETERS* presentParams);

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);

    HRESULT STDMETHODCALLTYPE Present(
      const RECT* pSourceRect,
      const RECT* pDestRect,
      HWND hDestWindowOverride,
      const RGNDATA* pDirtyRegion,
      DWORD dwFlags);

    HRESULT STDMETHODCALLTYPE GetFrontBufferData(IDirect3DSurface9* pDestSurface);

    HRESULT STDMETHODCALLTYPE GetBackBuffer(
      UINT iBackBuffer,
      D3DBACKBUFFER_TYPE Type,
      IDirect3DSurface9** ppBackBuffer);

    HRESULT STDMETHODCALLTYPE GetRasterStatus(D3DRASTER_STATUS* pRasterStatus);

    HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE* pMode);

    HRESULT STDMETHODCALLTYPE GetPresentParameters(D3DPRESENT_PARAMETERS* pPresentationParameters);

    HRESULT STDMETHODCALLTYPE GetLastPresentCount(UINT* pLastPresentCount);

    HRESULT STDMETHODCALLTYPE GetPresentStats(D3DPRESENTSTATS* pPresentationStatistics);

    HRESULT STDMETHODCALLTYPE GetDisplayModeEx(D3DDISPLAYMODEEX* pMode, D3DDISPLAYROTATION* pRotation);

    HRESULT Reset(D3DPRESENT_PARAMETERS* parameters);

    HRESULT WaitForVBlank();

  private:

    D3DPRESENT_PARAMETERS m_presentationParameters;

    std::vector<Direct3DSurface9*> m_buffers;

  };

}