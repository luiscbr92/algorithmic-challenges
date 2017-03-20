#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int shields, legionnaires, side;

  while(cin >> legionnaires && legionnaires){
    for(side = 1; side * side <= legionnaires; side++);
    side--;
    shields = side * side + side * 4;
    legionnaires -= side * side;
    while(legionnaires > 0){
      while(side * side > legionnaires)
        side--;
      shields += side * side + side * 4;
      legionnaires -= side * side;
    }
    cout << shields << endl;
  }

  return 0;
}
