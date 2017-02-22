#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int cases, n_compartiments, max_capacity, difference;
  cin >> cases;

  while(cases--){
    cin >> n_compartiments >> max_capacity >> difference;
    cout << n_compartiments * max_capacity - difference * (n_compartiments*(n_compartiments-1))/2 << endl;
  }

  return 0;
}
