#include <iostream>

#define MAXN 10001

using namespace std;

int main(){

  int n_of_marbles, n_of_queries, marble, query, cumulative;
  int cases = 0;

  while(cin >> n_of_marbles >> n_of_queries && n_of_marbles || n_of_queries){
    cases++;
    cout << "CASE# " << cases << ":\n";

    int amount_of_marble[MAXN] = {0};
    int position_of_marble[MAXN] = {0};

    while(n_of_marbles--){
      cin >> marble;
      amount_of_marble[marble]++;
    }
    cumulative = 0;
    for(int i = 0; i < MAXN; i++)
      if(amount_of_marble[i] != 0){
        position_of_marble[i] = cumulative+1;
        cumulative += amount_of_marble[i];
      }

    while(n_of_queries--){
      cin >> query;
      if(position_of_marble[query] == 0)
        cout << query << " not found\n";
      else
        cout << query << " found at " << position_of_marble[query] << endl;
    }
  }

  return 0;
}
