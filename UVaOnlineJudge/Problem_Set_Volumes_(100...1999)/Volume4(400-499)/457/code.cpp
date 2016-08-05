#include <iostream>

using namespace std;

void print_dishes(int dish[40]){
  for(int i = 0; i < 40; i++){
    switch(dish[i]){
      case 0:
        cout << ' ';
        break;
      case 1:
        cout << '.';
        break;
      case 2:
        cout << 'x';
        break;
      case 3:
        cout << 'W';
        break;
    }
  }
  cout << '\n';
}

int main(){

  int cases;

  cin >> cases;

  for(int c = 0; c < cases; c++){
    if(c != 0)
      cout << '\n';

    int dna[10];
    for(int i = 0; i < 10; i++)
      cin >> dna[i];

    int curr_dish[40] = {0};
    int prev_dish[40];
    curr_dish[19] = 1;

    print_dishes(curr_dish);

    for(int i = 0; i < 49; i++){
      for(int j = 0; j < 40; j++)
        prev_dish[j] = curr_dish[j];

      for(int j = 0; j < 40; j++){
        if(j == 0)
          curr_dish[j] = dna[prev_dish[j] + prev_dish[j+1]];
        else if(j == 39)
          curr_dish[j] = dna[prev_dish[j-1] + prev_dish[j]];
        else
          curr_dish[j] = dna[prev_dish[j-1] + prev_dish[j] + prev_dish[j+1]];
      }

      print_dishes(curr_dish);
    }
  }

  return 0;
}
