#include <iostream>
#include <set>

#define endl    '\n'

using namespace std;

int main(){

  int jack, jill, a;

  while (cin >> jack >> jill && jack || jill) {

    set<int> jackCd;

    for (int i = 0; i < jack; i++){
      cin >> a;
      jackCd.insert(a);
    }

    int sellableCds = 0;
    for(int i = 0; i < jill; i++){
      cin >> a;
      if(jackCd.find(a) != jackCd.end()){
        sellableCds++;
      }
    }

    cout << sellableCds << endl;
  }

  return 0;
}
