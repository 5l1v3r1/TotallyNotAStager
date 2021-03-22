// NotANEXEStager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
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


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    fnNotAStagerLib();
    return 0;

}

