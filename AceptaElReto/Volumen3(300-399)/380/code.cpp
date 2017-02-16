#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int n, s, t;

  while(cin >> n && n){
    s = 0;
    while(n--){
      cin >> t;
      s += t;
    }
    cout << s << endl;
  }

  return 0;
}
