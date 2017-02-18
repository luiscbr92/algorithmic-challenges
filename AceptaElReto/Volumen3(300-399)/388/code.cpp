#include <iostream>

#define endl        '\n'
#define MIN         -1
#define MAX         10001

using namespace std;

int main(){

  int n, x, y;
  while(cin >> n && n){
    int upper_left_value = MAX + MAX;
    int upper_right_value = MAX - MIN;
    int lower_left_value = MIN - MAX;
    int lower_right_value = MIN + MIN;

    while(n--){
      cin >> x >> y;
      if(x + y < upper_left_value){
        upper_left_value = x + y;
      }
      if(x + y > lower_right_value){
        lower_right_value = x + y;
      }
      if(x - y < upper_right_value){
        upper_right_value = x - y;
      }
      if(x - y > lower_left_value){
        lower_left_value = x - y;
      }
    }
    cout << max(lower_left_value - upper_right_value, lower_right_value - upper_left_value) << endl;
  }

  return 0;
}
