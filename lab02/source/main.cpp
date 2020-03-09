#include <Windows.h>
#include "res.h"
//123
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CLOSE:
      DestroyWindow(hwndDlg);
      PostQuitMessage(0);
      return true;
  case WM_LBUTTONDOWN:
      CHAR szText[200];
      wsprintf(szText, "Kliknales myszka x=%d, y=%d", LOWORD(lParam), HIWORD(lParam));
      MessageBox(hwndDlg, szText, TEXT("Klikniecie"), MB_OK);
      return true;
  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
        case IDC_BUTTON1:
         MessageBox(hwndDlg, TEXT("Test"), TEXT("Klikniecie"), MB_OK);
         HWND hwndEditBox = GetWindowTextLength(hwndEditBox);
       IDC_EDIT1:
         int iTextLength = GetWindowTextLength(hwndEditBox);
         CHAR szText[500];
         GetWindowText(hwndEditBox, szText, iTextLength + 1);
         SetWindowText((HWND)lParam, szText);
         return true;
      }
    }
    return false;
  }
      
  return false;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
  ShowWindow(hwndMainWindow, iCmdShow);

  MSG msg = {};
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }





  return 0;
}