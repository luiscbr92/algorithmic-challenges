#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){

  int cases;
  double d, v, u, res;
  cout << fixed;
  cout << setprecision(3);

  cin >> cases;

  for(int c = 1; c <= cases; c++){
    cin >> d >> v >> u;
    cout << "Case " << c << ": ";
    if(v != 0 && v < u){
      res = (d/sqrt(u*u-v*v)) - (d/u);
      cout << res << '\n';
    }
    else{
      cout << "can't determine\n";
    }
  }

  return 0;
}
