#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int x1, y1, x2, y2;

  while(cin >> x1 >> y1 >> x2 >> y2 && x1 <= x2 && y1 <= y2)
    cout << (x2 - x1) * (y2 - y1) << endl;

  return 0;
}
