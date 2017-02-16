#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int cases, distance, antennas, center, radius, last_coverage;

  cin >> cases;
  while(cases--){
    last_coverage = 0;
    cin >> distance >> antennas;
    while(antennas--){
      cin >> center >> radius;
      if(last_coverage >= center - radius && last_coverage < center + radius)
        last_coverage = center + radius;

    }
    if(last_coverage >= distance)
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
