#include <iostream>

#define endl      '\n'
#define modulus   31543

using namespace std;

int main(){

  int x, n, base, solution;
  while(cin >> x >> n && x!=0 || n!=0){
    solution = 1;
    base = x % modulus;

    base %= modulus;
    while (n > 0) {
      if (n & 1)
        solution = (solution * base) % modulus;
      base = (base * base) % modulus;
      n >>= 1;
    }
    cout << solution << endl;
  }

  return 0;
}
