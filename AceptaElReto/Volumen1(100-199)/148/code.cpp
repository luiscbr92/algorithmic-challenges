#include <iostream>

#define endl '\n'

using namespace std;

int main(){

  string clk;
  int hour, minute;

  while(cin >> clk && clk != "00:00"){
    hour = (clk[0] - '0') * 10 + (clk[1] - '0');
    minute = (clk[3] - '0') * 10 + (clk[4] - '0');

    cout << (23 - hour) * 60 + 60 - minute << endl;
  }

  return 0;
}
