#include <iostream>
#include <string>

using namespace std;

int main(){

  string input;

  while(cin >> input){
    string num_str = input.substr(0, 2);
    int num = stoi(num_str);
    int rev_num = num - 18;
    if(rev_num <= 0) rev_num += 36;
    if(rev_num < 10)
      cout << '0' << rev_num;
    else
      cout << rev_num;
    if(input.size() == 3){
      if(input[2] == 'R')
        cout << 'L';
      else if(input[2] == 'L')
        cout << 'R';
      else
        cout << 'C';
    }
    cout << '\n';
  }

  return 0;
}
