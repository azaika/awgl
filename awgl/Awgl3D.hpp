#pragma once
#define ENABLE_AWGL_3D

#include "Awgl3DBaseType.hpp"

namespace awgl {

	struct SwapChainDesc : ::DXGI_SWAP_CHAIN_DESC1 {
		SwapChainDesc() {
			
		}
	};

	class SwapChain3D {
	public:

	private:
		wrl::ComPtr<::IDXGISwapChain2> swapChain;

	};

	class Device3D {
	public:

	private:
		wrl::ComPtr<::ID3D11Device2> device;

	};

} // ::awgl