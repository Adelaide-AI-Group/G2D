/*
	Author: Anh-Dzung Doan
*/
#pragma once
#include "..\dependencies\inc\main.h"
#include "script.h"
#include "keyboard.h"
BOOL APIENTRY DllMain( HMODULE hInstance,
                       DWORD  reason,
                       LPVOID lpReserved
                     )
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
		scriptRegister(hInstance, ScriptMain);
		keyboardHandlerRegister(OnKeyboardMessage);
		break;
    case DLL_PROCESS_DETACH:
		scriptUnregister(hInstance);
		keyboardHandlerUnregister(OnKeyboardMessage);
		break;
  
    }
    return TRUE;
}

