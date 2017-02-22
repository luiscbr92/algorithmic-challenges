#include <iostream>

#define endl    '\n'
#define MONTHS  12

using namespace std;

int main(){

  int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int cases, day, month, total;
  cin >> cases;
  while(cases--){
    total = 0;
    cin >> day >> month;
    month--;
    for(int i = MONTHS-1; i > month; i--)
      total += days_of_month[i];
    total += days_of_month[month] - day;
    cout << total << endl;
  }

  return 0;
}
