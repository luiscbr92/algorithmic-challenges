#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int cases, n;

  cin >> cases;
  while(cases--){
    cin >> n;
    if(n % 3 == 0 || n % 3 == 2)
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
