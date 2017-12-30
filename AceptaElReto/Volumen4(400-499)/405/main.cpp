#include <iostream>

using namespace std;

int main(){

  int n, anterior, primera_rango;
  bool en_rango;

  while(cin >> n && n){
    cout << n;
    anterior = n;
    en_rango = false;
    while(cin >> n && n){
      if(en_rango){
        if(anterior + 1 != n){
          en_rango = false;
          cout << anterior << ',' << n;
        }
      }
      else{
        if(anterior + 1 == n){
          en_rango = true;
          cout << '-';
        }
        else{
          cout << ',' << n;
        }
      }
      anterior = n;
    }
    if(en_rango)
      cout << anterior;
    cout << '\n';
  }

  return 0;
}
