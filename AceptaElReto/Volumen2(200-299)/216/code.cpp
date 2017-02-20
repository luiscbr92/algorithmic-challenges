#include <iostream>

using namespace std;

int main(){

  int cases, total;

  cin >> cases;
  while(cases--){
    cin >> total;
    printf("%02d:%02d:%02d\n", total /3600, total /60 %60, total %60);
  }

  return 0;
}
