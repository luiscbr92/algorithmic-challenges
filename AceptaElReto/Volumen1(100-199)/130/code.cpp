#include <iostream>
#include <cmath>

using namespace std;

int main(){

  long tam, x1, y1, x2, y2, diffx, diffy;

  while(cin >> tam && tam){
    cin >> x1 >> y1 >> x2 >> y2;
    if((x1+y1)%2 == (x2+y2)%2){
      if(x1 == x2 && y1 == y2)
        cout << "0\n";
      else{
        if (abs(x1-x2) == abs(y1-y2))
          cout << "1\n";
        else
          cout << "2\n";
      }
    }
    else
      cout << "IMPOSIBLE\n";
  }

  return 0;
}
