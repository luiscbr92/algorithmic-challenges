#include <iostream>
#include <vector>
#include <algorithm>

#define endl    '\n'

using namespace std;

int main(){

  vector<int> beads;
  int bead;
  bool symmetric;

  while(cin >> bead && bead){
    beads.clear();
    symmetric = true;
    beads.push_back(bead);
    while(cin >> bead && bead)
      beads.push_back(bead);

    if(beads.size() % 2 == 0)
      cout << "NO" << endl;
    else{
      sort(beads.begin(), beads.end());

      for(int i = 1; i < beads.size(); i += 2)
        if(beads[i] != beads[i-1]){
          symmetric = false;
        }

      if(symmetric){
        cout << beads[0];
        for(int i = 2; i < beads.size(); i += 2)
          cout << ' ' << beads[i];
        for(int i = beads.size() -2; i >= 0; i -= 2)
          cout << ' ' << beads[i];
        cout << endl;
      }
      else
        cout << "NO" << endl;

    }
  }

  return 0;
}
