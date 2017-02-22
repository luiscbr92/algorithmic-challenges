#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int n_bulls, bull, fastest_bull;

  while(cin >> n_bulls){
    fastest_bull = 0;
    while(n_bulls--){
      cin >> bull;
      if(bull > fastest_bull)
        fastest_bull = bull;
    }
    cout << fastest_bull << endl;
  }

  return 0;
}
