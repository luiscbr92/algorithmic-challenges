#include <iostream>

using namespace std;

int main(){

  int cases, amount_of_cards, card, best;

  cin >> cases;
  for (int c = 1; c <= cases; c++) {
    cin >> amount_of_cards;
    best = 0;
    while(amount_of_cards--){
      cin >> card;
      if(card > best) best = card;
    }

    cout << "Case " << c << ": " << best << endl;
  }

  return 0;
}
