// dllmain.cpp : Defines the entry point for the DLL application.

#include "pch.h"
#include "..\NotAStagerLib\NotAStagerLib.h"


#ifdef _WIN64

#if DEBUG
#pragma comment(lib, "..\\Output\\NotAStagerLibx64_Debug.lib")

#else

#pragma comment(lib, "..\\Output\\NotAStagerLibx64.lib")

#endif


#else

#if DEBUG
#pragma comment(lib, "..\\Output\\NotAStagerLibx86_Debug.lib")

#else

#pragma comment(lib, "..\\Output\\NotAStagerLibx86.lib")

#endif

#endif

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{

    fnNotAStagerLib();
    return TRUE;

}

