#include <iostream>
#include <set>

using namespace std;

bool is_palindrome(string s){
  int i = 0;
  int size = s.size();
  while(i <= size / 2){
    if(s[i] != s[size - i -1])
      return false;
    i++;
  }
  return true;
}

int main(){

  string input, candidate;
  set<string> palindromes;
  int length, initial_position, size;

  while(cin >> input){
    size = input.size();
    palindromes.clear();
    for(length = 1; length <= size; length++){
      for(initial_position = 0; initial_position <= size - length; initial_position++){
        candidate = input.substr(initial_position, length);
        //cout << "Checking '" << candidate << "' ";
        if(is_palindrome(candidate)){
          palindromes.insert(candidate);
          //cout << "OK";
        }
        //cout << endl;
      }
    }

    cout << "The string '" << input <<"' contains " << palindromes.size() <<" palindromes.\n";
  }

  return 0;
}
