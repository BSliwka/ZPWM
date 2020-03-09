#include <Windows.h>
#include <string>

using namespace std;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
  MessageBox(0, "Pomyœl liczbê z zakresu 1-40", "Zgadywanie", MB_OK);

  int iRetKey;
  int max = 40;
  int min = 1;
  int num = 20;

  char q_buff[100];
  char end_buff[100];
  sprintf_s(q_buff, "Czy twoja liczba jest >=%d?", num);

  while (num > min)
  {
    iRetKey = MessageBox(0, q_buff, "Zgadywanie", MB_YESNO);
    if (iRetKey == IDYES)
    {
      min = num;
      if (max - min == 1)
        num = max;
      else
        num += (max - min) / 2;

      sprintf_s(q_buff, "Czy twoja liczba jest >=%d?", num);
      sprintf_s(end_buff, "Twoja liczba to %d!", num);
    }
    else
    {
      max = num;
      if (max - min == 1)
        num = min;
      else
        num -= (max - min) / 2;

      sprintf_s(q_buff, "Czy twoja liczba jest >=%d?", num);
      sprintf_s(end_buff, "Twoja liczba to %d!", num);
    }
  }
  MessageBox(0, end_buff, "Koniec", MB_OK);
  return 0;
}