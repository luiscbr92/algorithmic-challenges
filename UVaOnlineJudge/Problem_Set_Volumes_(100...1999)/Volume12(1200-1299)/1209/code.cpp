#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define ALPHABET_RANGE 26

using namespace std;

int minimum_distance_method(string s){
  int length = s.size();
  int minimum_distance = ALPHABET_RANGE;
  int distance;
  for(int i = 1; i < length; i++){
    distance = s[i-1] - s[i];
    if(distance < 0)
      distance *= -1;
    if(distance < minimum_distance)
      minimum_distance = distance;
  }
  return minimum_distance;
}

int main(){

  string username, permuting_backwards, permuting_forwards, password;
  int distance, largest_minimum, minimum_distance, length;
  vector<string> dictionary;

  while(cin >> username){
    dictionary.clear();
    largest_minimum = -1;
    length = username.size();

    dictionary.push_back(username);

    permuting_backwards = username;
    for(int i = 0; i < 10; i++){
      prev_permutation(permuting_backwards.begin(), permuting_backwards.end());
      dictionary.push_back(permuting_backwards);
    }

    permuting_forwards = username;
    for(int i = 0; i < 10; i++){
      next_permutation(permuting_forwards.begin(), permuting_forwards.end());
      dictionary.push_back(permuting_forwards);
    }

    sort(dictionary.begin(), dictionary.end());
    for(int i = 0; i < 21; i++){
      minimum_distance = minimum_distance_method(dictionary[i]);
      if(minimum_distance > largest_minimum){
        password = dictionary[i];
        largest_minimum = minimum_distance;
      }
    }

    cout << password << largest_minimum << '\n';
  }

  return 0;
}
