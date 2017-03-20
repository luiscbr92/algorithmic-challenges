#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int cases, platforms, previous_platform, current_platform, jumps_up, jumps_down;

  cin >> cases;
  while(cases--){
    jumps_up = jumps_down = 0;
    cin >> platforms;
    platforms--;
    cin >> previous_platform;
    while(platforms--){
      cin >> current_platform;
      if(previous_platform < current_platform)
        jumps_up++;
      else if(previous_platform > current_platform)
        jumps_down++;
      previous_platform = current_platform;
    }
    cout << jumps_up << ' ' << jumps_down << endl;
  }

  return 0;
}
