#include <iostream>

#define endl        '\n'

using namespace std;

int max_height;

void subtree(int height, int subnodes){
  height++;
  if(max_height < height)
    max_height = height;
  int sbn;
  for(int i = 0; i < subnodes; i++){
    cin >> sbn;
    subtree(height, sbn);
  }
}

int main(){

  int cases, node;

  cin >> cases;
  while(cases--){
    cin >> node;
    max_height = 1;
    subtree(0, node);
    cout << max_height << endl;
  }

  return 0;
}
