#include <iostream>
#include <vector>

using namespace std;

int main(){

  int n_nodes, n_edges, origin, destination, odd;

  while(cin >> n_edges && n_edges){
    cin >> n_nodes;

    vector<int> grade(n_nodes, 0);
    while(n_edges--){
      cin >> origin >> destination;
      grade[origin-1]++;
      grade[destination-1]++;
    }

    odd = 0;
    for(int i = 0; i < n_nodes; i++)
      if(grade[i] % 2 != 0)
        odd++;

    if(odd == 0 || odd == 2)
      cout << "SI\n";
    else
      cout << "NO\n";
  }

  return 0;
}
