#include <iostream>
#include <vector>
#include <algorithm>

#define endl        '\n'

using namespace std;

bool is_repdigits(int n){
  int remain = n % 10;
  n /= 10;
  for(int i = 0; i < 3; i++){
    if(remain != n % 10)
      return false;
    n /= 10;
  }
  return true;
}

int main(){

  int cases, n, iterations, ordered, rev_ordered;
  vector<int> digits;

  cin >> cases;
  while(cases--){
    cin >> n;
    if(is_repdigits(n)){
      cout << 8 << endl;
      continue;
    }

    iterations = 0;
    while(n != 6174){
      iterations++;
      digits.clear();
      for(int i = 0; i < 4; i++){
        digits.push_back(n % 10);
        n /= 10;
      }
      sort(digits.begin(), digits.end());
      ordered = 0;
      rev_ordered = 0;
      for(int i = 0; i < 4; i++){
        ordered *= 10;
        ordered += digits[i];
        rev_ordered *= 10;
        rev_ordered += digits[4-i-1];
      }
      n = rev_ordered - ordered;
    }

    cout << iterations << endl;
  }

  return 0;
}
