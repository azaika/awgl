﻿#pragma once
#define ENABLE_WAWL_ICONBASETYPE

#include "BaseType.hpp"

namespace wawl {
	namespace wnd {
		using IconHandle = ::HICON;

		// default window icon
		struct OEMIcon {
			static constexpr Tchar* App = IDI_APPLICATION;
			static constexpr Tchar* Info = IDI_INFORMATION;
			static constexpr Tchar* Question = IDI_QUESTION;
			static constexpr Tchar* Error = IDI_ERROR;
			static constexpr Tchar* Warning = IDI_WARNING;
			static constexpr Tchar* WinLogo = IDI_WINLOGO;
		};
	}
}