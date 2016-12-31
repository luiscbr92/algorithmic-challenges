#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n, t, picos;
  vector<int> altura;
  while(cin >> n && n){
    altura.clear();
    picos = 0;
    while(n--){
      cin >> t;
      altura.push_back(t);
    }
    for(int i = 1; i < altura.size()-1; i++)
      if(altura[i] > altura[i-1] && altura[i] > altura[i+1])
        picos++;
    if(altura[0] > altura[1] && altura[0] > altura[altura.size()-1])
      picos++;
    if(altura[altura.size()-1] > altura[0] && altura[altura.size()-1] > altura[altura.size()-2])
      picos++;

    cout << picos << '\n';
  }

  return 0;
}
