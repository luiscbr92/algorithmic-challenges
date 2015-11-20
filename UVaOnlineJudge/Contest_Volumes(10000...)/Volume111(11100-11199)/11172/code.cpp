#include <iostream>

using namespace std;

int main(){
  int cases, i, a, b;
  cin >> cases;

  for(i=0;i<cases;i++){
    cin >> a >> b;

    if (a>b) cout << ">\n";
    else if (a<b) cout << "<\n";
    else cout << "=\n";

  }
}
