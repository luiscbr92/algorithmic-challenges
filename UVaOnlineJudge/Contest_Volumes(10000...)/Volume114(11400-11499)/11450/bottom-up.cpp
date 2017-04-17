#include <iostream>
#include <cstring>

#define endl    '\n'

using namespace std;


int main(){
  int M, C, money, price[25][25];
  bool reachable[25][210];
  int cases, g, k;

  cin >> cases;
  while(cases--){
    cin >> M >> C;
    for(g = 0; g < C; g++){
      cin >> price[g][0];
      for(int money = 1; money <= price[g][0]; money++)
        cin >> price[g][money];
    }

    memset(reachable, false, sizeof reachable);
    for(g = 1; g <= price[0][0]; g++)
      if(M - price[0][g] >= 0)
        reachable[0][M - price[0][g]] = true;

    for(g = 1; g < C; g++)
      for(money = 0; money < M; money++)
        if(reachable[g-1][money])
          for(k = 1; k <= price[g][0]; k++)
            if(money - price[g][k] >= 0)
              reachable[g][money - price[g][k]] = true;

    for(money = 0; money <= M && !reachable[C-1][money]; money++);

    if(money == M + 1)
      cout << "no solution" << endl;
    else
      cout << M - money << endl;


  }


  return 0;
}
