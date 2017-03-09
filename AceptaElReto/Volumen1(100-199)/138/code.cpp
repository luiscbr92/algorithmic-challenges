#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int cases, n, sol;

  cin >> cases;
  while(cases--){
    cin >> n;
    sol = n / 5;
    n /= 5;
    while(n > 0){
      sol += n/5;
      n /= 5;
    }
    cout << sol << endl;
  }

  return 0;
}
