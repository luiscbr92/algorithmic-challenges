#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool my_comp(long long a, long long b){
  return a < b;
}

int main(){
  long long cases;
  long long tmp;
  vector<long long> v;

  cin >> cases;
  while(cases--){
    v.clear();
    cin >> tmp;
    v.push_back(tmp);
    cin >> tmp;
    v.push_back(tmp);
    cin >> tmp;
    v.push_back(tmp);
    sort(v.begin(), v.end(), my_comp);
    cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
  }

  return 0;
}
