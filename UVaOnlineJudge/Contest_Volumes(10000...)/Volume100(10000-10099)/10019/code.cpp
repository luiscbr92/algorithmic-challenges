#include <iostream>
#include <string>

using namespace std;

int num_of_ones(int dec_value) {
  int num_of_ones = 0;
  while (dec_value) {
    num_of_ones += dec_value % 2;
    dec_value /= 2;
  }
  return num_of_ones;
}

int main() {

  int cases;
  string m;

  cin >> cases;
  while (cases--) {
    cin >> m;

    cout << num_of_ones(stoi(m)) << ' ' << num_of_ones(stoi(m, 0, 16)) << endl;
  }

  return 0;
}
