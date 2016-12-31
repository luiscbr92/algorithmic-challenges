#include <iostream>

using namespace std;

int main(){

  int huevos, olla;

  while(cin >> huevos >> olla && huevos>0 || olla>0){
    if(huevos == 0) cout << 0 << '\n';
    else if(huevos%olla==0) cout << huevos/olla*10 <<'\n';
    else cout << huevos/olla*10 +10 << '\n';
  }


  return 0;
}
