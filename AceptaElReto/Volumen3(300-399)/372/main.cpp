#include <iostream>

using namespace std;

int main(){

  int cases;
  string line, output;
  cin >> cases;

  while(cases--){
    cin >> line;
    output = "";
    for(int i = 0; i < line.size(); i++)
      output = line[i] + output;
    if(line[0] < 'a'){
      output[0] -= 32;
      output[output.size()-1] += 32;
    }
    cout << output << '\n';
  }

  return 0;
}
