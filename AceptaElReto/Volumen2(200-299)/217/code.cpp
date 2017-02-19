#include <iostream>

#define endl        '\n'

using namespace std;

int main(){

  int n;
  while(cin >> n && n)
    if(n % 2 == 0)
      cout << "DERECHA" << endl;
    else
      cout << "IZQUIERDA" << endl;

  return 0;
}
