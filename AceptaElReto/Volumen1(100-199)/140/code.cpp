#include <iostream>

#define endl        '\n'

using namespace std;

int main(){

  string num;
  int sum;

  while(cin >> num && num[0] != '-'){
    sum = 0;
    cout << num[0] << ' ';
    sum += num[0] - '0';
    for(int i = 1; i < num.size(); i++){
      cout << "+ " << num[i] << ' ';
      sum += num[i] - '0';
    }
    cout << "= " << sum << endl;
  }


  return 0;
}
