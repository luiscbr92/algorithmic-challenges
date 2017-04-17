#include <iostream>
#include <cstring>

#define endl    '\n'

using namespace std;

int M, C, price[25][25];
int memo[210][25];

int shop(int money, int g){
  if(money < 0)
    return -1000;

  if(g == C)
    return M - money;

  int &ans = memo[money][g];
  if(ans != -1)
    return memo[money][g];

  for(int model = 1; model <= price[g][0]; model++)
    ans = max(ans, shop(money - price[g][model], g + 1));
  return ans;
}

int main(){
  int cases, money;
  cin >> cases;
  while(cases--){
    cin >> M >> C;
    for(int i = 0; i < C; i++){
      cin >> price[i][0]; //store K in price[i][0]
      for(int j = 1; j <= price[i][0]; j++)
        cin >> price[i][j];
    }
    memset(memo, -1, sizeof memo);
    money = shop(M, 0);
    if(money < 0)
      cout << "no solution" << endl;
    else
      cout << money << endl;
  }


  return 0;
}
