#include <iostream>

using namespace std;

int main(){

  int n;
  long long dalton1, dalton2;
  bool solved, increasing, decreasing;

  while(cin >> n && n){
    solved = false;
    increasing = false;
    decreasing = false;
    cin >> dalton1;
    n--;
    while(n--){
      cin >> dalton2;
      if(!solved){
        if(dalton1 > dalton2){
          if(increasing){
            cout << "DESCONOCIDOS\n";
            solved = true;
          }
          else{
            decreasing = true;
          }
        }
        else if(dalton1 < dalton2){
          if(decreasing){
            cout << "DESCONOCIDOS\n";
            solved = true;
          }
          else
          increasing = true;
        }
        else{
          cout << "DESCONOCIDOS\n";
          solved = true;
        }
        dalton1 = dalton2;
      }
    }
    if(!solved)
      cout << "DALTON\n";
  }

  return 0;
}
