#include <Windows.h>
#include "res.h"

HINSTANCE g_hInstance;

INT_PTR CALLBACK DialogProc1(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_KAJKO));
        SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

        HMENU hMenu = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_KAJKO_MENU));
        SetMenu(hwndDlg, hMenu);

        return FALSE;
    }
    case WM_CLOSE:
        DestroyWindow(hwndDlg);
        PostQuitMessage(0);
        return TRUE;
    }
    return FALSE;
}

INT_PTR CALLBACK DialogProc2(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
    {
        HICON hIcon = LoadIcon(g_hInstance, MAKEINTRESOURCE(IDI_KOKOSZ));
        SendMessage(hwndDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);

        HMENU hMenu = LoadMenu(g_hInstance, MAKEINTRESOURCE(IDR_KOKOSZ_MENU));
        SetMenu(hwndDlg, hMenu);

        return FALSE;
    }
    case WM_CLOSE:
        DestroyWindow(hwndDlg);
        PostQuitMessage(0);
        return TRUE;
    }
    return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    g_hInstance = hInstance;
    HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_KAJKO_VIEW), NULL, DialogProc1);
    ShowWindow(hwndMainWindow, iCmdShow);

    HWND hwndMainWindow2= CreateDialog(hInstance, MAKEINTRESOURCE(IDD_KOKOSZ_VIEW), NULL, DialogProc2);
    ShowWindow(hwndMainWindow2, iCmdShow);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}