#include <Windows.h>
#include "res.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;

int num;
int i = 0;

INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch (uMsg)
  {
  case WM_CLOSE:
      DestroyWindow(hwndDlg);
      PostQuitMessage(0);
      return true;

  case WM_COMMAND:
    switch (HIWORD(wParam))
    {
    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
        case IDC_BUTTON1:
         HWND hwndEditBox = GetDlgItem(hwndDlg, IDC_EDIT1);
         int iTextLength = GetWindowTextLength(hwndEditBox);
         CHAR szText[500];
         GetWindowText(hwndEditBox, szText, iTextLength + 1);
         int guess = stoi(szText);

         HWND textBox1 = GetDlgItem(hwndDlg, IDC_STATIC1);
         HWND textBox2 = GetDlgItem(hwndDlg, IDC_STATIC2);
         i++;
         char i_buff[100];
         sprintf_s(i_buff, "Liczba prób: %d", i);
         SetWindowText((HWND)textBox2, i_buff);

         if (guess < num)
         {
             SetWindowText((HWND)textBox1, "Za ma³o!");
         }
         else if (guess > num)
         {
             SetWindowText((HWND)textBox1, "Za du¿o!");
         }
         else
         {
             char w_buff[100];
             sprintf_s(w_buff, "Wygra³eœ! (w liczbie prób: %d)", i);
             MessageBox(0, w_buff, "Gratulacje", MB_OK);
             DestroyWindow(hwndDlg);
             PostQuitMessage(0);
             return true;
         }
        
         return true;
      }
    }
    return false;
  }
      
  return false;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  srand((int)time(0));
  num = rand() % 40;
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