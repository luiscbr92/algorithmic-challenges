#include <iostream>
#include <string>

using namespace std;

int main(){

  int cases, curr_day, curr_month, curr_year, birth_day, birth_month, birth_year, age;
  string curr_date, birth_date;

  cin >> cases;
  for(int c = 1; c <= cases; c++){
    cin >> curr_date >> birth_date;

    curr_day = stoi(curr_date.substr(0, 2));
    curr_month = stoi(curr_date.substr(3, 2));
    curr_year = stoi(curr_date.substr(6, 4));

    birth_day = stoi(birth_date.substr(0, 2));
    birth_month = stoi(birth_date.substr(3, 2));
    birth_year = stoi(birth_date.substr(6, 4));

    age = (curr_year - birth_year) - (curr_month < birth_month || (curr_month == birth_month && curr_day < birth_day));

    if (age < 0)
      cout << "Case #" << c << ": Invalid birth date" << endl;
    else if (age > 130)
      cout << "Case #" << c << ": Check birth date" << endl;
    else
      cout << "Case #" << c << ": " << age << endl;
  }

  return 0;
}
