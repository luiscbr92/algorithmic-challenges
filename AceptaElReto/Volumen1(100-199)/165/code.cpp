#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  string number;
  bool hypereven;

  while(cin >> number && number[0] != '-'){
    hypereven = true;
    for(int i = 0; i < number.size(); i++)
      if(number[i] % 2 != 0){
        hypereven = false;
        break;
      }
    if(hypereven)
      cout << "SI" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
