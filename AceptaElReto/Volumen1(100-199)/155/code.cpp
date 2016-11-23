#include <iostream>

using namespace std;

int main(){
  int x, y;

  while(cin >> x >> y && x >= 0 && y >= 0)
    cout << 2*x + 2*y << '\n';

  return 0;
}
