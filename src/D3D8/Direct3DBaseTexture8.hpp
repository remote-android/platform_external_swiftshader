// Copyright 2016 The SwiftShader Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef D3D8_Direct3DBaseTexture8_hpp
#define D3D8_Direct3DBaseTexture8_hpp

#include "Direct3DResource8.hpp"

#include <d3d8.h>

namespace sw
{
	class Resource;
}

namespace D3D8
{
	class Direct3DBaseTexture8 : public IDirect3DBaseTexture8, public Direct3DResource8
	{
	public:
		Direct3DBaseTexture8(Direct3DDevice8 *device, D3DRESOURCETYPE type, unsigned long levels, unsigned long usage);

		virtual ~Direct3DBaseTexture8();

		// IUnknown methods
		long __stdcall QueryInterface(const IID &iid, void **object);
		unsigned long __stdcall AddRef();
		unsigned long __stdcall Release();

		// IDirect3DResource8 methods
		long __stdcall FreePrivateData(const GUID &guid);
		long __stdcall GetPrivateData(const GUID &guid, void *data, unsigned long *size);
		void __stdcall PreLoad();
		long __stdcall SetPrivateData(const GUID &guid, const void *data, unsigned long size, unsigned long flags);
		long __stdcall GetDevice(IDirect3DDevice8 **device);
		unsigned long __stdcall SetPriority(unsigned long newPriority);
		unsigned long __stdcall GetPriority();
		D3DRESOURCETYPE __stdcall GetType();

		// IDirect3DBaseTexture8 methods
		unsigned long __stdcall GetLevelCount();
		unsigned long __stdcall GetLOD();
		long __stdcall SetLOD(long newLOD);

		// Intenal methods
		sw::Resource *getResource() const;
		unsigned long getInternalLevelCount();

	protected:
		// Creation paramters
		unsigned long levels;   // Recalculated when 0
		const unsigned long usage;

		sw::Resource *resource;

	private:
		D3DTEXTUREFILTERTYPE filterType;
		unsigned long LOD;
	};
}

#endif // D3D8_Direct3DBaseTexture8_hpp
