#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int cases, m, n;
  cin >> cases;
  while(cases--){
    cin >> m >> n;
    // Verticals + Horizontals. Simplified:
    cout << 2*m*n + m + n << endl;
  }

  return 0;
}
