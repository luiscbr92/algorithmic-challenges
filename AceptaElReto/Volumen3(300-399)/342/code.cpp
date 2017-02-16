#include <iostream>

#define endl      '\n'
#define spc       ' '

using namespace std;

int main(){

  int ini, fin, n, k, attempt;
  bool objective, following;

  while(cin >> ini >> fin >> n && ini || fin || n){
    cin >> k;
    objective = following = false;
    if(n == fin)
      following = true;
    if(n == ini)
      objective = true;
    while(k--){
      cin >> attempt;
      if(!objective && attempt == n)
        objective = true;
      else if(!following && attempt == n+1)
        following = true;
    }

    if(objective && following)
      cout << "LO SABE" << endl;
    else
      cout << "NO LO SABE" << endl;
  }

  return 0;
}
