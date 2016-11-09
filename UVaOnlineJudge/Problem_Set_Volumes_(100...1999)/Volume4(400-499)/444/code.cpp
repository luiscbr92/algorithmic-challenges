#include <iostream>
#include <string>

using namespace std;

string encode(string input){
  string output = "";
  int ascii_value;
  string ascii_value_str;
  for(int i = 0; i < input.size(); i++){
    ascii_value = input[i];
    ascii_value_str = to_string(ascii_value);
    for(int j = 0; j < ascii_value_str.size(); j++)
      output = ascii_value_str[j] + output;
  }
  return output;
}

string decode(string input){
  string output = "";
  char ascii;
  int aux;
  string reverse_ascii;
  while(input != ""){
    if(input[1] <= '2'){
      reverse_ascii = input.substr(0, 3);
      if(input.size() == 3)
        input = "";
      else
        input = input.substr(3);
    }
    else{
      reverse_ascii = input.substr(0, 2);
      if(input.size() == 2)
        input = "";
      else
        input = input.substr(2);
    }
    ascii = 0;
    aux = 1;
    for(int i = 0; i < reverse_ascii.size(); i++){
      ascii += (reverse_ascii[i] - '0') * aux;
      aux *= 10;
    }
    output = ascii + output;
  }
  return output;
}

int main(){

  string input;

  while(getline(cin, input)){
    if(input.size() > 0){
      if(input[0] - '0' <= 9 && input[0] - '0' >= 0)
        cout << decode(input) << '\n';
      else
        cout << encode(input) << '\n';
    }
    else
      cout << '\n';
  }

  return 0;
}
