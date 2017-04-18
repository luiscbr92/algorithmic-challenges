#include <iostream>
#include <vector>

#define endl  '\n'

using namespace std;

int main(){

  int n;
  int coins[] = {1, 5, 10, 25, 50};
  vector<long> ways (30001, 1);

  // I don't iterate over the coint '1' because I've initialized the vector with the result of that iteration
  for (int i = 1; i < 5; i++)
    for(int amount = coins[i]; amount < 30001; amount++)
      ways[amount] += ways[amount - coins[i]];

  while(cin >> n)
    if(ways[n] == 1)
      cout << "There is only 1 way to produce " << n << " cents change." << endl;
    else
      cout << "There are " << ways[n] << " ways to produce " << n << " cents change." << endl;
}
