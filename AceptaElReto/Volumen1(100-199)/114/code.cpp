#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, input;

    cin >> cases;
    while(cases--){
        cin >> input;
        if(input <= 1)      cout << 1 << "\n";
        else if(input == 2) cout << 2 << "\n";
        else if(input == 3) cout << 6 << "\n";
        else if(input == 4) cout << 4 << "\n";
        else                cout << 0 << "\n";
    }

    return 0;
}
