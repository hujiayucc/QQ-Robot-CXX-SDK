//
// Created by hujiayucc on 25-5-2.
//

#pragma once
#include <cstdio>
#include <windows.h>

typedef void(__stdcall *ApiOutFunc)(const char* text, int color);

int main()
{
    constexpr uintptr_t FUNCTION_RVA = 0x12DD;

    const HMODULE hModule = LoadLibraryA(R"(E:\QQ\C++\test\zzapi.dll)");
    if (!hModule) {
        printf("[Error] DLL load failed. Error code: %d\n", GetLastError());
        return -1;
    }

    const auto baseAddress = reinterpret_cast<uintptr_t>(hModule);
    const uintptr_t functionAddress = baseAddress + FUNCTION_RVA;
    const auto apiOut = reinterpret_cast<ApiOutFunc>(functionAddress);

    if (IsBadCodePtr(reinterpret_cast<FARPROC>(apiOut))) {
        printf("[Error] Invalid function address: 0x%08X\n", functionAddress);
        FreeLibrary(hModule);
        return -2;
    }

    const auto logText = "Test message from C++";

    apiOut(logText, 0x00FF00);

    FreeLibrary(hModule);
    return 0;
}