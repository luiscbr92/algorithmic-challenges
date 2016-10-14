#include <iostream>

using namespace std;

int main(){

  int cases, punct, diff, greatest;

  cin >> cases;

  while(cases--){
    cin >> punct >> diff;

    if(diff <= punct && (punct+diff)%2 == 0){
      greatest = punct/2.0 + diff/2.0 + 0.5;
      cout << greatest << ' ' << punct - greatest << '\n';
    }
    else
      cout << "impossible\n";
  }

  return 0;
}
