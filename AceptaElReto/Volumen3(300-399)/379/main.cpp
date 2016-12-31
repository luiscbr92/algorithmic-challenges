#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n, t;
  vector<int> v;

  while(cin >> n && n){
    v.clear();
    for(int i = 0; i < n; i++){
      cin >> t;
      v.push_back(t);
    }

    if(n == 1)
      cout << v[0]+1 << '\n';
    else{
      int pos = n-1;
      bool flag = true;
      while(pos > 0 && flag){
        if(v[pos] == v[pos-1]){
          v[pos]++;
          flag = false;
        }
        pos--;
      }
      if(flag){ // Esto es dificil de interpretar del enunciado: (1 2 3) -> (2 2 2)
        cout << v[0]+1;
        for(int i = 1; i < n; i++)
          cout << ' ' << v[0]+1;
        cout << '\n';
      }
      else{
        cout << v[0];
        for(int i = 1; i < n; i++)
          cout << ' ' << v[i];
        cout << '\n';
      }
    }
  }


  return 0;
}
