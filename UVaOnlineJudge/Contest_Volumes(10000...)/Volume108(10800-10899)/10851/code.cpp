#include <iostream>
#include <string>

using namespace std;

int main(){

  int cases, text_size, temp;
  string input, output;

  cin >> cases;
  while(cases--){
    cin >> input;
    text_size = input.size() - 2;
    temp = 1;
    char hidden_text[text_size] = {0};
    for(int i = 0; i < 8; i++){
      cin >> input;
      for(int j = 0; j < text_size; j++)
        if(input[j+1] == '\\')
          hidden_text[j] += temp;
      temp <<= 1;
    }
    cin >> input;

    output = "";
    for(int i = 0; i < text_size; i++)
      output += hidden_text[i];

    cout << output << '\n';
  }

  return 0;
}
