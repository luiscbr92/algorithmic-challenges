#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> p1, pair<int, int> p2){
  if(p1.first == p2.first)
    return p1.second < p2.second;
  return p1.first < p2.first;
}

int main(){

  int nciudades, dinero, premio;
  vector<pair<int,int>> l;

  while(cin >> nciudades && nciudades){
    l.clear();
    while(nciudades--){
      cin >> dinero >> premio;
      l.push_back(make_pair(dinero, premio));
    }

    sort(l.begin(), l.end(), comp);

    bool flag = true;
    for(int i=1; i < l.size(); i++){
      if(l[i-1].first < l[i].first && l[i-1].second >= l[i].second){
        flag = false;
        break;
      }
    }
    if(flag) cout << "SI\n";
    else  cout << "NO\n";
  }

  return 0;
}
