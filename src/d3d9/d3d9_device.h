#pragma once

#include "../dxvk/dxvk_device.h"
#include "../dxvk/dxvk_cs.h"

#include "d3d9_include.h"
#include "d3d9_cursor.h"
#include "d3d9_format.h"
#include "d3d9_multithread.h"

#include <vector>

namespace dxvk {

  constexpr static uint32_t MinFlushIntervalUs = 1250;
  constexpr static uint32_t MaxPendingSubmits = 3;

  class Direct3DSwapChain9Ex;
  class Direct3DCommonTexture9;

  class Direct3DDevice9Ex final : public ComObject<IDirect3DDevice9Ex> {

  public:

    Direct3DDevice9Ex(
      bool extended,
      IDirect3D9Ex* parent,
      UINT adapter,
      Rc<DxvkAdapter> dxvkAdapter,
      Rc<DxvkDevice> dxvkDevice,
      D3DDEVTYPE deviceType,
      HWND window,
      DWORD flags,
      D3DPRESENT_PARAMETERS* presentParams,
      D3DDISPLAYMODEEX* displayMode);

    ~Direct3DDevice9Ex();

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppvObject);

    HRESULT STDMETHODCALLTYPE TestCooperativeLevel();

    UINT    STDMETHODCALLTYPE GetAvailableTextureMem();

    HRESULT STDMETHODCALLTYPE EvictManagedResources();

    HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D9** ppD3D9);

    HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS9* pCaps);

    HRESULT STDMETHODCALLTYPE GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode);

    HRESULT STDMETHODCALLTYPE GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters);

    HRESULT STDMETHODCALLTYPE SetCursorProperties(
      UINT XHotSpot,
      UINT YHotSpot,
      IDirect3DSurface9* pCursorBitmap);

    void    STDMETHODCALLTYPE SetCursorPosition(int X, int Y, DWORD Flags);

    BOOL    STDMETHODCALLTYPE ShowCursor(BOOL bShow);

    HRESULT STDMETHODCALLTYPE CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** ppSwapChain);

    HRESULT STDMETHODCALLTYPE GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain);

    UINT    STDMETHODCALLTYPE GetNumberOfSwapChains();

    HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS* pPresentationParameters);

    HRESULT STDMETHODCALLTYPE Present(
      const RECT* pSourceRect,
      const RECT* pDestRect, HWND hDestWindowOverride,
      const RGNDATA* pDirtyRegion);

    HRESULT STDMETHODCALLTYPE GetBackBuffer(
      UINT iSwapChain,
      UINT iBackBuffer,
      D3DBACKBUFFER_TYPE Type,
      IDirect3DSurface9** ppBackBuffer);

    HRESULT STDMETHODCALLTYPE GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus);

    HRESULT STDMETHODCALLTYPE SetDialogBoxMode(BOOL bEnableDialogs);

    void    STDMETHODCALLTYPE SetGammaRamp(
      UINT iSwapChain,
      DWORD Flags,
      const D3DGAMMARAMP* pRamp);

    void    STDMETHODCALLTYPE GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp);

    HRESULT STDMETHODCALLTYPE CreateTexture(UINT Width,
      UINT Height,
      UINT Levels,
      DWORD Usage,
      D3DFORMAT Format,
      D3DPOOL Pool,
      IDirect3DTexture9** ppTexture,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE CreateVolumeTexture(
      UINT Width,
      UINT Height,
      UINT Depth,
      UINT Levels,
      DWORD Usage,
      D3DFORMAT Format,
      D3DPOOL Pool,
      IDirect3DVolumeTexture9** ppVolumeTexture,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE CreateCubeTexture(
      UINT EdgeLength,
      UINT Levels,
      DWORD Usage,
      D3DFORMAT Format,
      D3DPOOL Pool,
      IDirect3DCubeTexture9** ppCubeTexture,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE CreateVertexBuffer(
      UINT Length,
      DWORD Usage,
      DWORD FVF,
      D3DPOOL Pool,
      IDirect3DVertexBuffer9** ppVertexBuffer,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE CreateIndexBuffer(
      UINT Length,
      DWORD Usage,
      D3DFORMAT Format,
      D3DPOOL Pool,
      IDirect3DIndexBuffer9** ppIndexBuffer,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE CreateRenderTarget(
      UINT Width,
      UINT Height,
      D3DFORMAT Format,
      D3DMULTISAMPLE_TYPE MultiSample,
      DWORD MultisampleQuality,
      BOOL Lockable,
      IDirect3DSurface9** ppSurface,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(
      UINT Width,
      UINT Height,
      D3DFORMAT Format,
      D3DMULTISAMPLE_TYPE MultiSample,
      DWORD MultisampleQuality,
      BOOL Discard,
      IDirect3DSurface9** ppSurface,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE UpdateSurface(
      IDirect3DSurface9* pSourceSurface,
      const RECT* pSourceRect,
      IDirect3DSurface9* pDestinationSurface,
      const POINT* pDestPoint);

    HRESULT STDMETHODCALLTYPE UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture);

    HRESULT STDMETHODCALLTYPE GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface);

    HRESULT STDMETHODCALLTYPE GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface);

    HRESULT STDMETHODCALLTYPE StretchRect(
      IDirect3DSurface9* pSourceSurface,
      const RECT* pSourceRect,
      IDirect3DSurface9* pDestSurface,
      const RECT* pDestRect,
      D3DTEXTUREFILTERTYPE Filter);

    HRESULT STDMETHODCALLTYPE ColorFill(
      IDirect3DSurface9* pSurface,
      const RECT* pRect,
      D3DCOLOR color);

    HRESULT STDMETHODCALLTYPE CreateOffscreenPlainSurface(
      UINT Width,
      UINT Height,
      D3DFORMAT Format,
      D3DPOOL Pool,
      IDirect3DSurface9** ppSurface,
      HANDLE* pSharedHandle);

    HRESULT STDMETHODCALLTYPE SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget);

    HRESULT STDMETHODCALLTYPE GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget);

    HRESULT STDMETHODCALLTYPE SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil);

    HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface);

    HRESULT STDMETHODCALLTYPE BeginScene();

    HRESULT STDMETHODCALLTYPE EndScene();

    HRESULT STDMETHODCALLTYPE Clear(
      DWORD Count,
      const D3DRECT* pRects,
      DWORD Flags,
      D3DCOLOR Color,
      float Z,
      DWORD Stencil);

    HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX* pMatrix);

    HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix);

    HRESULT STDMETHODCALLTYPE MultiplyTransform(D3DTRANSFORMSTATETYPE TransformState, const D3DMATRIX* pMatrix);

    HRESULT STDMETHODCALLTYPE SetViewport(const D3DVIEWPORT9* pViewport);

    HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT9* pViewport);

    HRESULT STDMETHODCALLTYPE SetMaterial(const D3DMATERIAL9* pMaterial);

    HRESULT STDMETHODCALLTYPE GetMaterial(D3DMATERIAL9* pMaterial);

    HRESULT STDMETHODCALLTYPE SetLight(DWORD Index, const D3DLIGHT9* pLight);

    HRESULT STDMETHODCALLTYPE GetLight(DWORD Index, D3DLIGHT9* pLight);

    HRESULT STDMETHODCALLTYPE LightEnable(DWORD Index, BOOL Enable);

    HRESULT STDMETHODCALLTYPE GetLightEnable(DWORD Index, BOOL* pEnable);

    HRESULT STDMETHODCALLTYPE SetClipPlane(DWORD Index, const float* pPlane);

    HRESULT STDMETHODCALLTYPE GetClipPlane(DWORD Index, float* pPlane);

    HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE State, DWORD Value);

    HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue);

    HRESULT STDMETHODCALLTYPE CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB);

    HRESULT STDMETHODCALLTYPE BeginStateBlock();

    HRESULT STDMETHODCALLTYPE EndStateBlock(IDirect3DStateBlock9** ppSB);

    HRESULT STDMETHODCALLTYPE SetClipStatus(const D3DCLIPSTATUS9* pClipStatus);

    HRESULT STDMETHODCALLTYPE GetClipStatus(D3DCLIPSTATUS9* pClipStatus);

    HRESULT STDMETHODCALLTYPE GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture);

    HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture);

    HRESULT STDMETHODCALLTYPE GetTextureStageState(
      DWORD Stage,
      D3DTEXTURESTAGESTATETYPE Type,
      DWORD* pValue);

    HRESULT STDMETHODCALLTYPE SetTextureStageState(
      DWORD Stage,
      D3DTEXTURESTAGESTATETYPE Type,
      DWORD Value);

    HRESULT STDMETHODCALLTYPE GetSamplerState(
      DWORD Sampler,
      D3DSAMPLERSTATETYPE Type,
      DWORD* pValue);

    HRESULT STDMETHODCALLTYPE SetSamplerState(
      DWORD Sampler,
      D3DSAMPLERSTATETYPE Type,
      DWORD Value);

    HRESULT STDMETHODCALLTYPE ValidateDevice(DWORD* pNumPasses);

    HRESULT STDMETHODCALLTYPE SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY* pEntries);

    HRESULT STDMETHODCALLTYPE GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries);

    HRESULT STDMETHODCALLTYPE SetCurrentTexturePalette(UINT PaletteNumber);

    HRESULT STDMETHODCALLTYPE GetCurrentTexturePalette(UINT *PaletteNumber);

    HRESULT STDMETHODCALLTYPE SetScissorRect(const RECT* pRect);

    HRESULT STDMETHODCALLTYPE GetScissorRect(RECT* pRect);

    HRESULT STDMETHODCALLTYPE SetSoftwareVertexProcessing(BOOL bSoftware);

    BOOL    STDMETHODCALLTYPE GetSoftwareVertexProcessing();

    HRESULT STDMETHODCALLTYPE SetNPatchMode(float nSegments);

    float   STDMETHODCALLTYPE GetNPatchMode();

    HRESULT STDMETHODCALLTYPE DrawPrimitive(
      D3DPRIMITIVETYPE PrimitiveType,
      UINT StartVertex,
      UINT PrimitiveCount);

    HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(
      D3DPRIMITIVETYPE PrimitiveType,
      INT BaseVertexIndex,
      UINT MinVertexIndex,
      UINT NumVertices,
      UINT startIndex,
      UINT primCount);

    HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(
      D3DPRIMITIVETYPE PrimitiveType,
      UINT PrimitiveCount,
      const void* pVertexStreamZeroData,
      UINT VertexStreamZeroStride);

    HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP(
      D3DPRIMITIVETYPE PrimitiveType,
      UINT MinVertexIndex,
      UINT NumVertices,
      UINT PrimitiveCount,
      const void* pIndexData,
      D3DFORMAT IndexDataFormat,
      const void* pVertexStreamZeroData,
      UINT VertexStreamZeroStride);

    HRESULT STDMETHODCALLTYPE ProcessVertices(
      UINT SrcStartIndex,
      UINT DestIndex,
      UINT VertexCount,
      IDirect3DVertexBuffer9* pDestBuffer,
      IDirect3DVertexDeclaration9* pVertexDecl,
      DWORD Flags);

    HRESULT STDMETHODCALLTYPE CreateVertexDeclaration(const D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl);

    HRESULT STDMETHODCALLTYPE SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl);

    HRESULT STDMETHODCALLTYPE GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl);

    HRESULT STDMETHODCALLTYPE SetFVF(DWORD FVF);

    HRESULT STDMETHODCALLTYPE GetFVF(DWORD* pFVF);

    HRESULT STDMETHODCALLTYPE CreateVertexShader(const DWORD* pFunction, IDirect3DVertexShader9** ppShader);

    HRESULT STDMETHODCALLTYPE SetVertexShader(IDirect3DVertexShader9* pShader);

    HRESULT STDMETHODCALLTYPE GetVertexShader(IDirect3DVertexShader9** ppShader);

    HRESULT STDMETHODCALLTYPE SetVertexShaderConstantF(
      UINT StartRegister,
      const float* pConstantData,
      UINT Vector4fCount);

    HRESULT STDMETHODCALLTYPE GetVertexShaderConstantF(
      UINT StartRegister,
      float* pConstantData,
      UINT Vector4fCount);

    HRESULT STDMETHODCALLTYPE SetVertexShaderConstantI(
      UINT StartRegister,
      const int* pConstantData,
      UINT Vector4iCount);

    HRESULT STDMETHODCALLTYPE GetVertexShaderConstantI(
      UINT StartRegister,
      int* pConstantData,
      UINT Vector4iCount);

    HRESULT STDMETHODCALLTYPE SetVertexShaderConstantB(
      UINT StartRegister,
      const BOOL* pConstantData,
      UINT BoolCount);

    HRESULT STDMETHODCALLTYPE GetVertexShaderConstantB(
      UINT StartRegister,
      BOOL* pConstantData,
      UINT BoolCount);

    HRESULT STDMETHODCALLTYPE SetStreamSource(
      UINT StreamNumber,
      IDirect3DVertexBuffer9* pStreamData,
      UINT OffsetInBytes,
      UINT Stride);

    HRESULT STDMETHODCALLTYPE GetStreamSource(
      UINT StreamNumber,
      IDirect3DVertexBuffer9** ppStreamData,
      UINT* pOffsetInBytes,
      UINT* pStride);

    HRESULT STDMETHODCALLTYPE SetStreamSourceFreq(UINT StreamNumber, UINT Setting);

    HRESULT STDMETHODCALLTYPE GetStreamSourceFreq(UINT StreamNumber, UINT* pSetting);

    HRESULT STDMETHODCALLTYPE SetIndices(IDirect3DIndexBuffer9* pIndexData);

    HRESULT STDMETHODCALLTYPE GetIndices(IDirect3DIndexBuffer9** ppIndexData);

    HRESULT STDMETHODCALLTYPE CreatePixelShader(const DWORD* pFunction, IDirect3DPixelShader9** ppShader);

    HRESULT STDMETHODCALLTYPE SetPixelShader(IDirect3DPixelShader9* pShader);

    HRESULT STDMETHODCALLTYPE GetPixelShader(IDirect3DPixelShader9** ppShader);

    HRESULT STDMETHODCALLTYPE SetPixelShaderConstantF(
      UINT StartRegister,
      const float* pConstantData,
      UINT Vector4fCount);

    HRESULT STDMETHODCALLTYPE GetPixelShaderConstantF(
      UINT StartRegister,
      float* pConstantData,
      UINT Vector4fCount);

    HRESULT STDMETHODCALLTYPE SetPixelShaderConstantI(
      UINT StartRegister,
      const int* pConstantData,
      UINT Vector4iCount);

    HRESULT STDMETHODCALLTYPE GetPixelShaderConstantI(
      UINT StartRegister,
      int* pConstantData,
      UINT Vector4iCount);

    HRESULT STDMETHODCALLTYPE SetPixelShaderConstantB(
      UINT StartRegister,
      const BOOL* pConstantData,
      UINT BoolCount);

    HRESULT STDMETHODCALLTYPE GetPixelShaderConstantB(
      UINT StartRegister,
      BOOL* pConstantData,
      UINT BoolCount);

    HRESULT STDMETHODCALLTYPE DrawRectPatch(
      UINT Handle,
      const float* pNumSegs,
      const D3DRECTPATCH_INFO* pRectPatchInfo);

    HRESULT STDMETHODCALLTYPE DrawTriPatch(
      UINT Handle,
      const float* pNumSegs,
      const D3DTRIPATCH_INFO* pTriPatchInfo);

    HRESULT STDMETHODCALLTYPE DeletePatch(UINT Handle);

    HRESULT STDMETHODCALLTYPE CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery);

    // Ex Methods

    HRESULT STDMETHODCALLTYPE SetConvolutionMonoKernel(
      UINT width,
      UINT height,
      float* rows,
      float* columns);

    HRESULT STDMETHODCALLTYPE ComposeRects(
      IDirect3DSurface9* pSrc,
      IDirect3DSurface9* pDst,
      IDirect3DVertexBuffer9* pSrcRectDescs,
      UINT NumRects,
      IDirect3DVertexBuffer9* pDstRectDescs,
      D3DCOMPOSERECTSOP Operation,
      int Xoffset,
      int Yoffset);

    HRESULT STDMETHODCALLTYPE GetGPUThreadPriority(INT* pPriority);

    HRESULT STDMETHODCALLTYPE SetGPUThreadPriority(INT Priority);

    HRESULT STDMETHODCALLTYPE WaitForVBlank(UINT iSwapChain);

    HRESULT STDMETHODCALLTYPE CheckResourceResidency(IDirect3DResource9** pResourceArray, UINT32 NumResources);

    HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(UINT MaxLatency);

    HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(UINT* pMaxLatency);

    HRESULT STDMETHODCALLTYPE CheckDeviceState(HWND hDestinationWindow);

    HRESULT STDMETHODCALLTYPE PresentEx(
      const RECT* pSourceRect,
      const RECT* pDestRect,
      HWND hDestWindowOverride,
      const RGNDATA* pDirtyRegion,
      DWORD dwFlags);

    HRESULT STDMETHODCALLTYPE CreateRenderTargetEx(
      UINT Width,
      UINT Height,
      D3DFORMAT Format,
      D3DMULTISAMPLE_TYPE MultiSample,
      DWORD MultisampleQuality,
      BOOL Lockable,
      IDirect3DSurface9** ppSurface,
      HANDLE* pSharedHandle,
      DWORD Usage);

    HRESULT STDMETHODCALLTYPE CreateOffscreenPlainSurfaceEx(
      UINT Width,
      UINT Height,
      D3DFORMAT Format,
      D3DPOOL Pool,
      IDirect3DSurface9** ppSurface,
      HANDLE* pSharedHandle,
      DWORD Usage);

    HRESULT STDMETHODCALLTYPE CreateDepthStencilSurfaceEx(
      UINT Width,
      UINT Height,
      D3DFORMAT Format,
      D3DMULTISAMPLE_TYPE MultiSample,
      DWORD MultisampleQuality,
      BOOL Discard,
      IDirect3DSurface9** ppSurface,
      HANDLE* pSharedHandle,
      DWORD Usage);

    HRESULT STDMETHODCALLTYPE ResetEx(D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDISPLAYMODEEX *pFullscreenDisplayMode);

    HRESULT STDMETHODCALLTYPE GetDisplayModeEx(
      UINT iSwapChain,
      D3DDISPLAYMODEEX* pMode,
      D3DDISPLAYROTATION* pRotation);

    static DxvkDeviceFeatures GetDeviceFeatures(const Rc<DxvkAdapter>& adapter);

    bool IsExtended();

    HWND GetWindow();

    Rc<DxvkDevice> GetDXVKDevice() {
      return m_device;
    }

    D3D9_VK_FORMAT_INFO LookupFormat(
      D3D9Format            Format,
      bool                  srgb) const;

    bool WaitForResource(
      const Rc<DxvkResource>&                 Resource,
            DWORD                             MapFlags);

    /**
     * \brief Locks a subresource of an image
     * 
     * \param [in] Subresource The subresource of the image to lock
     * \param [out] pLockedBox The returned locked box of the image, containing data ptr and strides
     * \param [in] pBox The region of the subresource to lock. This offsets the returned data ptr
     * \param [in] Flags The D3DLOCK_* flags to lock the image with
     * \returns \c D3D_OK if the parameters are valid or D3DERR_INVALIDCALL if it fails.
     */
    HRESULT LockImage(
            Direct3DCommonTexture9* pResource,
            UINT                    Subresource,
            D3DLOCKED_BOX*          pLockedBox,
      const D3DBOX*                 pBox,
            DWORD                   Flags);

    /**
     * \brief Unlocks a subresource of an image
     * 
     * Passthrough to device unlock.
     * \param [in] Subresource The subresource of the image to unlock
     * \returns \c D3D_OK if the parameters are valid or D3DERR_INVALIDCALL if it fails.
     */
    HRESULT UnlockImage(
            Direct3DCommonTexture9* pResource,
            UINT                    Subresource);

    void SynchronizeCsThread();

    void Flush();

    Direct3DDeviceLock9 LockDevice() {
      return m_multithread.AcquireLock();
    }

  private:

    Direct3DMultithread9            m_multithread;

    const D3D9VkFormatTable         m_d3d9Formats;

    Direct3DSwapChain9Ex* getInternalSwapchain(UINT index);

    Com<IDirect3D9Ex> m_parent;

    UINT m_adapter;

    Rc<DxvkAdapter> m_dxvkAdapter;
    Rc<DxvkDevice> m_device;
    Rc<DxvkDataBuffer>          m_updateBuffer;
    DxvkCsChunkPool m_csChunkPool;

    DxvkCsChunkRef              m_csChunk;

    D3DDEVTYPE m_deviceType;
    HWND m_window;
    DWORD m_flags;

    bool m_extended;

    D3DPRESENT_PARAMETERS m_presentParams;

    D3D9Cursor m_cursor;

    std::vector<IDirect3DSwapChain9Ex*> m_swapchains;

    DxvkCsThread m_csThread;
    bool         m_csIsBusy = false;

    std::chrono::high_resolution_clock::time_point m_lastFlush
      = std::chrono::high_resolution_clock::now();

    DxvkCsChunkRef AllocCsChunk() {
      DxvkCsChunk* chunk = m_csChunkPool.allocChunk(DxvkCsChunkFlag::SingleUse);
      return DxvkCsChunkRef(chunk, &m_csChunkPool);
    }

    template<typename Cmd>
    void EmitCs(Cmd&& command) {
      if (!m_csChunk->push(command)) {
        EmitCsChunk(std::move(m_csChunk));

        m_csChunk = AllocCsChunk();
        m_csChunk->push(command);
      }
    }

    void FlushCsChunk() {
      if (m_csChunk->commandCount() != 0) {
        EmitCsChunk(std::move(m_csChunk));
        m_csChunk = AllocCsChunk();
      }
    }

    void SynchronizeDevice();

    void EmitCsChunk(DxvkCsChunkRef&& chunk);

    void FlushImplicit(BOOL StrongHint);

  };

}
