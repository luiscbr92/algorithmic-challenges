#include <iostream>
#include <vector>

using namespace std;

int main(){

  long input;
  while(cin >> input && input >=0){
    cout << (2*input) + (input-1)*(input-2)/2 << endl;
  }

  return 0;
}
