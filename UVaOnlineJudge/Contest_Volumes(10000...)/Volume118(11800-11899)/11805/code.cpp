#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, players, first_player, passes, last_player;

    cin >> cases;

    for (c = 1; c <= cases; c++) {
      cin >> players >> first_player >> passes;
      last_player = (first_player - 1 + passes) % players + 1;
      cout << "Case " << c << ": " << last_player << endl;
    }

    return 0;
}
