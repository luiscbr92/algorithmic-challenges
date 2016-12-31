#include <iostream>

using namespace std;

int main(){

  int n;
  while(cin >> n && n)
    cout << n*(n+1)/2 *3 << '\n';

  return 0;
}
