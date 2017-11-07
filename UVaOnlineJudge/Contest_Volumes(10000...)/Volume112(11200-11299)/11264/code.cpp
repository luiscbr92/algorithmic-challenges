#include <iostream>

using namespace std;

int main(){

  int cases, number_of_coins, used_coins, amount;
  cin >> cases;
  while(cases--){
    cin >> number_of_coins;
    int coins[number_of_coins];
    for(int i = 0; i < number_of_coins; i++){
      cin >> coins[i];
    }

    amount = 1;
    used_coins = 2; // Lowest and greatest coin values are used
    for(int i = 1; i < number_of_coins-1; i++)
      if(amount+coins[i] < coins[i+1]){
        amount += coins[i];
        used_coins++;
      }

    cout << used_coins << endl;
  }

  return 0;
}
