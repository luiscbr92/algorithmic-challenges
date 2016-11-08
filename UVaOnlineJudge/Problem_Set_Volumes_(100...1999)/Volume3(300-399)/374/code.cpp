#include <iostream>

using namespace std;

int main(){

  int base, expo, mod, result;

  while(cin >> base >> expo >> mod){
    base %= mod;
    result = 1;
    while(expo > 0){
      if(expo & 1)
        result = (result * base) % mod;
      base = (base * base) % mod;
      expo >>= 1;
    }
    cout << result << '\n';
  }
}
