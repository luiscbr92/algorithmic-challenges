#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

  map<char, char> letter_to_number;
  letter_to_number['-'] = '-';
  letter_to_number['0'] = '0';
  letter_to_number['1'] = '1';
  letter_to_number['A'] = '2';
  letter_to_number['B'] = '2';
  letter_to_number['C'] = '2';
  letter_to_number['D'] = '3';
  letter_to_number['E'] = '3';
  letter_to_number['F'] = '3';
  letter_to_number['G'] = '4';
  letter_to_number['H'] = '4';
  letter_to_number['I'] = '4';
  letter_to_number['J'] = '5';
  letter_to_number['K'] = '5';
  letter_to_number['L'] = '5';
  letter_to_number['M'] = '6';
  letter_to_number['N'] = '6';
  letter_to_number['O'] = '6';
  letter_to_number['P'] = '7';
  letter_to_number['Q'] = '7';
  letter_to_number['R'] = '7';
  letter_to_number['S'] = '7';
  letter_to_number['T'] = '8';
  letter_to_number['U'] = '8';
  letter_to_number['V'] = '8';
  letter_to_number['W'] = '9';
  letter_to_number['X'] = '9';
  letter_to_number['Y'] = '9';
  letter_to_number['Z'] = '9';

  string expression, number;

  while (cin >> expression) {
    number = "";
    for(int i = 0; i < expression.size(); i++)
      number = number + letter_to_number[expression[i]];

    cout << number << endl;
  }

  return 0;
}
