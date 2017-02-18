#include <iostream>
#include <vector>

#define endl        '\n'

using namespace std;

int gcd(int a, int b){
  if (b==0)
    return a;
  else
    return gcd(b, a%b);
}

int lcm(int a, int b){
  return a*b/gcd(a,b);
}

int main(){

  int n, moves, next, solution;
  vector<int> lengths;

  while(cin >> n && n){
    lengths.clear();
    int description[n];
    bool visited[n];
    for(int i = 0; i < n; i++){
      cin >> description[i];
      description[i]--;
      visited[i] = false;
    }

    for(int initial = 0; initial < n; initial++){
      if(!visited[initial]){
        visited[initial] = true;
        next = initial;
        moves = 1;
        visited[description[next]] = true;
        while(initial != description[next]){
          moves++;
          visited[description[next]] = true;
          next = description[next];
        }
        lengths.push_back(moves);
      }
    }

    solution = 1;
    for(int i = 0; i < lengths.size(); i++)
      solution = lcm(solution, lengths[i]);

    cout << solution << endl;
  }

  return 0;
}
