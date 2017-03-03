#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

#define endl '\n'

using namespace std;

int main(){

  string tri, lenght_str, iter_str;
  double lenght, iter, sol;

  while(cin >> tri >> lenght_str >> iter_str){
    lenght_str = lenght_str.substr(7);
    iter_str = iter_str.substr(11);

    //cout << "STRINGS: " << lenght_str << ' ' << iter_str << endl;

    lenght = 0;
    for(int i = 0; i < lenght_str.size(); i++)
      lenght = lenght * 10 + (lenght_str[i] - '0');
    iter = 0;
    for(int i = 0; i < iter_str.size(); i++)
      iter = iter * 10 + (iter_str[i] -'0');

    //cout << lenght << ' ' << iter << endl;

    sol = lenght * 3;
    for(int i = 0; i < iter; i++)
      sol = sol * 4 / 3;
    cout << fixed;
    cout << setprecision(0);
    cout << sol << endl;
  }



  return 0;
}
