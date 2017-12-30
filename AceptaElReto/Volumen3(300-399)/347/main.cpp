#include <iostream>

using namespace std;

int main(){

  int a, b;
  int cuadrados;

  while(cin >> a >> b && a || b){
    cuadrados = 0;
    while(a >= 10 && b >= 10){
      if(a < b){
        cuadrados += b / a;
        b = b % a;
      }
      else{
        cuadrados += a / b;
        a = a % b;
      }
    }
    cout << cuadrados << endl;
  }

  return 0;
}
