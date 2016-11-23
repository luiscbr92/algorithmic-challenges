#include <iostream>

using namespace std;

int main(){

  int n, v1, v2;
  bool sorted;

  while(cin >> n && n){
    sorted = true;
    cin >> v1;
    n--;
    while(n--){
      cin >> v2;
      if(sorted){
        if(v1 < v2)
          v1 = v2;
        else
          sorted = false;
      }
    }

    if(sorted)
      cout << "SI\n";
    else
      cout << "NO\n";
  }

  return 0;
}
