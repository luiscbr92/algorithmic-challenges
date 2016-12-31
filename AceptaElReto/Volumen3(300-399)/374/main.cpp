#include <iostream>
#include <climits>

using namespace std;

int main(){

  int cases;
  long long t;

  cin >> cases;
  while(cases--){
    long long min = LLONG_MAX;
    long long max = 0;
    long long min_ap;
    long long max_ap;

    while(cin >> t && t){
      if(t < min){
        min = t;
        min_ap = 1;
      }
      else if(t == min){
        min_ap++;
      }

      if(t > max){
        max = t;
        max_ap = 1;
      }
      else if(t == max){
        max_ap++;
      }
    }
    cout << min << ' ' << min_ap << ' ' << max << ' ' << max_ap << '\n';
  }

  return 0;
}
