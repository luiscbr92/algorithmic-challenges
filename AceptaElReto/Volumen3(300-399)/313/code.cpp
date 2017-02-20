#include <iostream>

#define endl '\n'

using namespace std;

int main(){

  int cases, a, b;
  cin >> cases;
  while(cases--){
    cin >> a >> b;
    if(a+b < 0)
      cout << "NO" << endl;
    else
      cout << "SI" << endl;
  }

  return 0;
}
