#include <iostream>
#include <vector>

#define endl      '\n'
#define DIGITS    10

using namespace std;

int main(){

  int raffles, winner, max_winner, max_wons;
  bool several;

  while(cin >> raffles && raffles){
    vector<int> stat (DIGITS, 0);
    max_wons = 0;
    several = true;
    while(raffles--){
      cin >> winner;
      winner %= DIGITS;
      stat[winner]++;
      if(stat[winner] == max_wons)
        several = true;
      else if(stat[winner] > max_wons){
        several = false;
        max_winner = winner;
        max_wons = stat[winner];
      }
    }
    if(several)
      cout << "VARIAS" << endl;
    else
      cout << max_winner << endl;
  }

  return 0;
}
