#pragma once
// D3D12AppParam.h
//  
//   written by Akiko Kawai
// ===========================================
#define WIN32_LEAN_AND_MEAN
#include <d3d12.h>
#include <wrl/client.h>
#include <dxgi1_6.h>

class D3D12AppParam
{
public:
    D3D12AppParam();
    virtual  ~D3D12AppParam();

    void Initialize(HWND hWnd);

private:
    const UINT FrameBufferCount = 2;

    Microsoft::WRL::ComPtr<IDXGIFactory3> pDxgiFactory_;

    Microsoft::WRL::ComPtr<ID3D12Device> pDevice_;
    Microsoft::WRL::ComPtr<ID3D12CommandQueue> pCommandQueue_;
    Microsoft::WRL::ComPtr<IDXGISwapChain4> pSwapchain_;

    void init_search_hardware_adapter(HWND hwnd);
    void init_direct3d_device(HWND hwnd);
    void create_command_que(HWND hwnd);
    void create_swap_chain(HWND hwnd);
};
// ===========================================
// End of file