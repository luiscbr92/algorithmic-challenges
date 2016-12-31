#include <iostream>

using namespace std;

int main(){

  long long cases, n;
  cin >> cases;
  while(cases--){
    cin >> n;
    cout << n*n*n - (n-2)*(n-2)*(n-2) << '\n';
  }

  return 0;
}
