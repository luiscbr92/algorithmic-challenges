#include <iostream>
#include <climits>

#define endl      '\n'
#define DIFF_MIN  -300000
#define MIN_PAG   -300000

using namespace std;

int main(){

  int diff_max, max, cases, pages, current;

  cin >> cases;
  while(cases--){
    cin >> pages;
    diff_max = DIFF_MIN;
    max = MIN_PAG;

    while(pages--){
      cin >> current;
      if(diff_max < max - current)
        diff_max = max - current;
      if(max < current)
        max = current;
    }
    cout << diff_max << endl;
  }

  return 0;
}
