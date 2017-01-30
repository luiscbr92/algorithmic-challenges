#include <iostream>

using namespace std;

int main(){

  int cases, char_at_i;
  string input;
  unsigned long solution;

  cin >> cases;
  for(int c = 1; c <= cases; c++){
    int char_occurrences[26] = {0};
    cin >> input;
    solution = 1;

    for(int i = 0; i < input.size(); i++){
      char_at_i = input[i] - 'A';
      char_occurrences[char_at_i]++;
      solution *= i+1;
      solution /= char_occurrences[char_at_i];
    }

    cout << "Data set " << c << ": " << solution << '\n';
  }

  return 0;
}
