#include <iostream>

using namespace std;

int main(){
  int cases, cx, cy, px, py, i;

  cin >> cases;

  while(cases != 0){
    cin >> cx >> cy;

    for(i=0;i<cases;i++){
      cin >> px >> py;

      if(px == cx || py == cy) cout << "divisa\n";
      else if(px > cx && py > cy) cout << "NE\n";
      else if(px > cx && py < cy) cout << "SE\n";
      else if(px < cx && py > cy) cout << "NO\n";
      else cout << "SO\n";
    }

    cin >> cases;
  }
}
