#include <iostream>

using namespace std;

int main(){

  unsigned int x, y, z, a, b, c;

  while(cin >> x >> y >> z && x!=0 && y!=0 && z!=0){
    a = max(x, max(y,z));
    c = min(x, min(y,z));
    b = x+y+z-a-c;

    if(a*a == b*b+c*c)
      cout << "right\n";
    else
      cout << "wrong\n";
  }

  return 0;
}
