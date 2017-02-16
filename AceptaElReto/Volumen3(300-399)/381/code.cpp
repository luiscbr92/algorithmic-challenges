#include <iostream>

#define endl      '\n'

using namespace std;


int gcd(int a, int b) {
  if (b==0) return a;
  else return gcd(b, a%b);
}

int lcm(int a, int b) {
  return a*b/gcd(a,b);
}

int main(){

  int n, sol, a, b;

  while(cin >> n && n){
    cin >> a >> b;
    sol = lcm(a,b);

    n-=2;
    while(n--){
      cin >> a;
      sol = lcm(sol, a);
    }

    cout << sol << endl;
  }


  return 0;
}
