#pragma once

#include <Windows.h>

HWND g_DeskTopWindowHandle;

BOOL EnumWindowFunc(HWND WindowHandle, LPARAM)
{
    HWND TempWindowsHandle = FindWindowEx(WindowHandle, 0, L"SHELLDLL_DefView", NULL);

    if (TempWindowsHandle != NULL)
    {
        g_DeskTopWindowHandle = FindWindowEx(0, WindowHandle, L"WorkerW", 0);
    }

    return TRUE;
}


VOID setWindowToWallPaper(HWND WindowHandle)
{
    //
    DWORD Ret;
    HWND DesktopWindowHandle = FindWindowW(L"Progman", NULL);
    SendMessageTimeoutW(DesktopWindowHandle, 0x52c, 0, 0, SMTO_NORMAL, 0x3e8, (PDWORD_PTR)&Ret);

    //寻找桌面窗口获得窗口句柄
    EnumWindows(EnumWindowFunc, (LPARAM)NULL);
    //隐藏桌面
    ShowWindow(g_DeskTopWindowHandle, SW_HIDE);
    //
    SetParent(WindowHandle, DesktopWindowHandle);

}
