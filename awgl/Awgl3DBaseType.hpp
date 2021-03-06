#pragma once
#define ENABLE_AWGL_3DBASETYPE

#include <d3d11_2.h>
#include "BaseType.hpp"

namespace awgl {

	enum class AlphaMode : wawl::Int32 {
		Unspecified = ::DXGI_ALPHA_MODE_UNSPECIFIED,
		PreMultiplied = ::DXGI_ALPHA_MODE_PREMULTIPLIED,
		Straight = ::DXGI_ALPHA_MODE_STRAIGHT,
		Ignore = ::DXGI_ALPHA_MODE_IGNORE
	};

	enum class SwapEffect {
		Discard = ::DXGI_SWAP_EFFECT_DISCARD,
		Sequential = ::DXGI_SWAP_EFFECT_SEQUENTIAL,
		FlipSequential = ::DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL
	};

} // ::awgl