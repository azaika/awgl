﻿#pragma once
#define ENABLE_WAWL_SECURITYOBJECTS

#include "BaseType.hpp"

namespace wawl {
	namespace fs {

		// security descriptor
		using SecurityDesc = ::SECURITY_DESCRIPTOR;
		// make an initialized SecurityDesc
		SecurityDesc makeSecurityDesc() {
			SecurityDesc sd;
			::InitializeSecurityDescriptor(
				&sd,
				SECURITY_DESCRIPTOR_REVISION
				);

			return sd;
		}

		// security attributes
		using SecurityAttr = ::SECURITY_ATTRIBUTES;
		// make an initialized SecurityAttr
		SecurityAttr makeSecurityAttr(bool doInheritHandle) {
			SecurityAttr sa;

			sa.nLength = sizeof(SecurityAttr);
			sa.bInheritHandle = doInheritHandle;
			sa.lpSecurityDescriptor = nullptr;

			return sa;
		}
		SecurityAttr makeSecurityAttr(bool doInheritHandle, SecurityDesc& secDesc) {
			SecurityAttr sa;

			sa.nLength = sizeof(SecurityAttr);
			sa.bInheritHandle = doInheritHandle;
			sa.lpSecurityDescriptor = &secDesc;

			return sa;
		}

	} // ::wawl::fs
} // ::wawl