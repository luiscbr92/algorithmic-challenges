#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int get_correct_numbers(string a, string b){
  int size = a.size();
  string sub_a, sub_b;
  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
      if(a[i] == b[j]){
        a.erase(a.begin()+i);
        b.erase(b.begin()+j);
        return (1 + get_correct_numbers(a, b));
      }

  return 0;
}

pair<int,int> get_punctuation(string candidate, string tip){
  int correct_positions = 0;
  string sub_a = "";
  string sub_b = "";
  for(int i = 0; i < 4; i++){
    if(candidate[i] == tip[i])
      correct_positions++;
    else{
      sub_a += candidate[i];
      sub_b += tip[i];
    }
  }

  return make_pair(correct_positions, get_correct_numbers(sub_a, sub_b));
}

int main(){

  int cases, guesses, int_candidate, number_valid_candidates;
  bool valid_candidate;
  string string_results, candidate, last_valid_candidate;
  pair<int,int> punctuation;

  cin >> cases;

  while(cases--){
    cin >> guesses;
    string tip[guesses];
    int correct_positions[guesses];
    int correct_numbers[guesses];
    number_valid_candidates = 0;

    for(int i = 0; i < guesses; i++){
      cin >> tip[i] >> string_results;
      correct_positions[i] = string_results[0] - '0';
      correct_numbers[i] = string_results[2] - '0';
    }

    for(int i = 0; i < 10000; i++){
      int_candidate = i;
      candidate = "";

      while(int_candidate != 0){
        candidate = char(int_candidate % 10 + '0') + candidate;
        int_candidate /= 10;
      }

      while(candidate.size() < 4)
        candidate = '0' + candidate;

      valid_candidate = true;

      for(int j = 0; j < guesses; j++){
        punctuation = get_punctuation(candidate, tip[j]);
        if(correct_positions[j] != punctuation.first || correct_numbers[j] != punctuation.second){
          valid_candidate = false;
          break;
        }
      }

      if(valid_candidate){
        number_valid_candidates++;
        last_valid_candidate = candidate;
      }
    }

    if(number_valid_candidates == 0)
      cout << "impossible\n";
    else if(number_valid_candidates == 1)
      cout << last_valid_candidate << '\n';
    else
      cout << "indeterminate\n";
  }

  return 0;
}
