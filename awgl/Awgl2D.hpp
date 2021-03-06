#pragma once
#define ENABLE_AWGL_2D

#include <d2d1_2.h>
#include "BaseType.hpp"

#pragma comment(lib, "d2d1_2.lib")

namespace awgl {

	class Device2D {
	public:
		
	private:
		wrl::ComPtr<::ID2D1Device1> device;

	};

	class Factory2D {
	public:
		Factory2D() = default;
		Factory2D(Factory2D&& f) {
			factory = f.factory;
			f.factory.Detach();
		}
		Factory2D& operator = (Factory2D&& f) {
			factory = f.factory;
			f.factory.Detach();

			return *this;
		}

		Factory2D(const Factory2D&) = delete;
		Factory2D& operator = (const Factory2D&) = delete;

		bool init() {
			//::D3D11CreateDevice();
			if (
				FAILED(
					::D2D1CreateFactory(
						::D2D1_FACTORY_TYPE_MULTI_THREADED,
						factory.GetAddressOf()
					)
				))
				return false;

			return true;
		}

		bool isAlive() const {
			return factory != 0;
		}
		explicit operator bool() const {
			return factory != 0;
		}

		::ID2D1Factory2* get() {
			return factory.Get();
		}
		::ID2D1Factory2* operator -> () {
			return get();
		}

	private:
		wrl::ComPtr<::ID2D1Factory2> factory = nullptr;

	};

} // ::awgl