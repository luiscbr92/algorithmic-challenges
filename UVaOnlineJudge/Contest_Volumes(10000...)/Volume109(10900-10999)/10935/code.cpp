#include <iostream>
#include <queue>

#define endl    '\n'

using namespace std;

int main(){

  int n;
  queue<int> cards;
  bool discard;

  while(cin >> n && n){
    while(!cards.empty())
      cards.pop();
    for(int i = 1; i <= n; i++)
      cards.push(i);

    if(n == 1)
      cout << "Discarded cards:" << endl << "Remaining card: 1" << endl;
    else{
      cout << "Discarded cards: " << cards.front();
      discard = false;
      cards.pop();
      while(cards.size() > 1){
        if(discard){
          cout << ", " << cards.front();
          cards.pop();
          discard = false;
        }
        else{
          cards.push(cards.front());
          cards.pop();
          discard = true;
        }
      }
      cout << endl << "Remaining card: " << cards.front() << endl;
    }


  }

  return 0;
}
