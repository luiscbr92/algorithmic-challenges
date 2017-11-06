#include <iostream>
#include <vector>

using namespace std;

int main(){

  int coin[] = {1, 5, 10, 25, 50};
  int ways[5][7490];
  for(int i = 0; i < 7490; i++) ways[0][i] = 1;
  for(int i = 1; i < 5; i++) ways[i][0] = 1;

  for(int i = 1; i < 5; i++)
    for(int amount = 1; amount < 7490; amount++)
      if(amount >= coin[i])
        ways[i][amount] = ways[i-1][amount] + ways[i][amount-coin[i]];
      else
        ways[i][amount] = max(ways[i][amount-1], ways[i-1][amount]);

  int amount;
  while(cin >> amount)
    cout << ways[4][amount] << endl;

  return 0;
}
