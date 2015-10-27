#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  long n, x, f;
  while (cin >> n) {
    x = (n-1)/2;
    f = 6*x*(x-1) + 18*x - 3;
    cout << f << endl;
  }
  return 0;
}
