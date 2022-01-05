#include <windows.h>
#include <detours.h>
#include <iostream>

#pragma comment(lib, "detours.lib")

/*
MessageBoxA Signature
*/
int HookMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
    std::wcout << L"Detour MessageBoxA, Title: " << lpCaption << L" - Text: " << lpText << std::endl;
    return IDOK;
}



BOOL WINAPI DllMain(HINSTANCE const instance, DWORD const reason, LPVOID const reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        DetourRestoreAfterWith();
        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());

        PVOID func = DetourFindFunction("user32.dll", "MessageBoxA");
        DetourAttach(&(PVOID&)func, (PVOID)HookMessageBoxA);
        DetourTransactionCommit();

        std::wcout << L"Attached." << std::endl;


        break;
    }

    return TRUE;
}