#pragma once

#include <dxgi1_3.h>
#include <wrl.h>
#include <wawl/WawlBase.hpp>

namespace awgl {
	
	namespace wrl = Microsoft::WRL;

	template <typename EnumType>
	auto& unpackEnum = wawl::unpackEnum<EnumType>;

} // ::awgl