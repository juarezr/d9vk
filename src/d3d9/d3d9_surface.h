#pragma once

#include "d3d9_subresource.h"

#include "d3d9_common_texture.h"

namespace dxvk {

  using Direct3DSurface9Base = Direct3DSubresource9<IDirect3DSurface9>;
  class Direct3DSurface9 final : public Direct3DSurface9Base {

  public:

    Direct3DSurface9(
            Direct3DDevice9Ex*        device,
      const D3D9TextureDesc*          desc);

    Direct3DSurface9(
            Direct3DDevice9Ex*         device,
            Rc<Direct3DCommonTexture9> texture,
            UINT                       subresource,
            IUnknown*                  container);

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);

    D3DRESOURCETYPE STDMETHODCALLTYPE GetType() final;

    HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC *pDesc) final;

    HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT* pLockedRect, CONST RECT* pRect, DWORD Flags) final;

    HRESULT STDMETHODCALLTYPE UnlockRect() final;

    HRESULT STDMETHODCALLTYPE GetDC(HDC *phdc) final;

    HRESULT STDMETHODCALLTYPE ReleaseDC(HDC hdc) final;

  };
}