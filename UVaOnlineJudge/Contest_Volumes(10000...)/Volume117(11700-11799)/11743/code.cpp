#include <iostream>
#include <string>

using namespace std;

int main(){

  int cases, checksum, digit;
  string credit_card;

  cin >> cases;
  cin.ignore();
  while(cases--){
    getline(cin, credit_card);
    credit_card.erase(14, 1);
    credit_card.erase(9, 1);
    credit_card.erase(4, 1);
    checksum = 0;

    for(int i = 0; i < 16; i++){
      if(i%2 == 0){
        digit = credit_card[i] - '0';
        digit *= 2;
        checksum += digit % 10;
        digit /= 10;
        checksum += digit % 10;
      }
      else{
        checksum += credit_card[i] - '0';
      }
    }

    if(checksum % 10 == 0)  cout << "Valid\n";
    else                    cout << "Invalid\n";

  }

  return 0;
}
