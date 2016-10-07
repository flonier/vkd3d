/*
 * Copyright 2016 Józef Kucia for CodeWeavers
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "vkd3d_utils_private.h"

HRESULT WINAPI D3D12GetDebugInterface(REFIID riid, void **debug)
{
    FIXME("riid %s, debug %p stub!\n", debugstr_guid(riid), debug);

    return E_NOTIMPL;
}

HRESULT WINAPI D3D12CreateDevice(IUnknown *adapter,
        D3D_FEATURE_LEVEL minimum_feature_level, REFIID riid, void **device)
{
    struct vkd3d_device_create_info create_info;

    TRACE("adapter %p, minimum_feature_level %#x, riid %s, device %p.\n",
            adapter, minimum_feature_level, debugstr_guid(riid), device);

    if (adapter)
        FIXME("Ignoring adapter %p.\n", adapter);

    create_info.minimum_feature_level = minimum_feature_level;
    create_info.signal_event_pfn = VKD3DSignalEvent;

    return vkd3d_create_device(&create_info, riid, device);
}