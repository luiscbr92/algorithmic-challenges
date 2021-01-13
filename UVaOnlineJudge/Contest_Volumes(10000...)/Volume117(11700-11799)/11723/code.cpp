#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int c, roads, integers, suffixes;

    c = 1;
    while (cin >> roads >> integers && roads && integers) {
      suffixes = roads / integers;
      if(roads % integers == 0)
        suffixes--;
      if(suffixes > 26)
        cout << "Case " << c << ": impossible" << endl;
      else
        cout << "Case " << c << ": " << suffixes << endl;
      c++;
    }

    return 0;
}
