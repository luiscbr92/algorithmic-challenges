#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

  vector<int> morning;
  vector<int> evening;
  int n, d, r, overtime_payment, route;

  while(cin >> n >> d >> r && n || d || r){
    morning.clear();
    evening.clear();
    for(int i = 0; i < n; i++){
      cin >> route;
      morning.push_back(route);
    }
    for(int i = 0; i < n; i++){
      cin >> route;
      evening.push_back(route);
    }

    sort(morning.begin(), morning.end());
    sort(evening.begin(), evening.end());

    overtime_payment = 0;
    for(int i = 0; i < n; i++){
      if((route = morning[i] + evening[n-1-i]) > d)
        overtime_payment += route - d;
    }

    cout << overtime_payment * r << endl;
  }
  return 0;
}
