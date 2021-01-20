#include <iostream>
#include <string>

using namespace std;

int main(){

  char keypad[10][5] = {
    {NULL, ' ', NULL, NULL},
    {NULL, '.', ',', '?', '\"'},
    {NULL, 'a', 'b', 'c', NULL},
    {NULL, 'd', 'e', 'f', NULL},
    {NULL, 'g', 'h', 'i', NULL},
    {NULL, 'j', 'k', 'l', NULL},
    {NULL, 'm', 'n', 'o', NULL},
    {NULL, 'p', 'q', 'r', 's'},
    {NULL, 't', 'u', 'v', NULL},
    {NULL, 'w', 'x', 'y', 'z'}
  };

  int cases, length, times_pressed;
  string message;

  cin >> cases;
  while (cases--) {
    cin >> length;

    int keys_pressed[length];
    message = "";

    for (int i = 0; i < length; i++)
      cin >> keys_pressed[i];

    for (int i = 0; i < length; i++){
      cin >> times_pressed;
      message = message + keypad[keys_pressed[i]][times_pressed];
    }

    cout << message << endl;
  }

  return 0;
}
