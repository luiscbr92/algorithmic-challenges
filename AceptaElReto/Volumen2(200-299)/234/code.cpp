#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  int cases, n_batteries, voltage, tmp, left_pointer, right_pointer, cars_working;
  bool finished;
  vector<int> batteries;

  cin >> cases;

  while(cases--){
    cin >> n_batteries >> voltage;
    batteries.clear();
    vector<bool> used(n_batteries, false);
    cars_working = 0;

    for(int i = 0; i < n_batteries; i++){
      cin >> tmp;
      batteries.push_back(tmp);
    }

    sort(batteries.begin(), batteries.end());

    finished = false;
    right_pointer = n_batteries - 1;
    left_pointer = 0;
    while(!finished && left_pointer < right_pointer){
      finished = true;
      while(left_pointer < right_pointer){
        if(!used[left_pointer] && !used[right_pointer])
          if(batteries[left_pointer] + batteries[right_pointer] >= voltage){
            used[left_pointer] = true;
            used[right_pointer] = true;
            finished = false;
            cars_working++;
            break;
          }
          left_pointer++;
      }
      right_pointer--;
    }

    cout << cars_working << '\n';
  }

  return 0;
}
