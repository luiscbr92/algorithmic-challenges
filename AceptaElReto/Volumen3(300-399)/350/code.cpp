#include <iostream>

using namespace std;

int main(){

  int base, height;

  while(cin >> base >> height && base || height)
    printf("%.1f\n", base * height /2.0);
}
