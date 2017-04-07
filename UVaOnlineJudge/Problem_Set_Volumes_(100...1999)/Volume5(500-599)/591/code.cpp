#include <iostream>

#define endl    '\n'

using namespace std;

int main(){

  int dataset = 1;
  int number_of_stacks;
  int number_of_boxes;
  int moves;

  while(cin >> number_of_stacks && number_of_stacks){
    cout << "Set #" << dataset << endl;
    dataset++;

    int stack[number_of_stacks];
    number_of_boxes = 0;
    for(int i = 0; i < number_of_stacks; i++){
      cin >> stack[i];
      number_of_boxes += stack[i];
    }

    number_of_boxes /= number_of_stacks;
    moves = 0;
    for(int i = 0; i < number_of_stacks; i++)
      if(stack[i] < number_of_boxes)
        moves += number_of_boxes - stack[i];

    cout << "The minimum number of moves is " << moves << '.' << endl << endl;

  }


  return 0;
}
