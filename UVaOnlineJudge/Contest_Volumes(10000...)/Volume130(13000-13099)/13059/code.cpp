#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    unsigned long players;
    string output = "";

    while(cin >> players) output += to_string(players-1) + '\n';
    cout << output;

    return 0;
}
