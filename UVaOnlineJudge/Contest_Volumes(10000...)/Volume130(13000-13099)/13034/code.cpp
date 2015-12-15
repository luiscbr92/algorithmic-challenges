#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, i, problem;
    bool consider;
    string result;

    cin >> cases;

    for(c = 1; c <= cases; c++){
        cout << "Set #" << c;
        consider = true;
        for(i = 0; i < 13; i++){
            cin >> problem;
            if(problem == 0) consider = false;
        }
        if(consider)    cout << ": Yes\n";
        else            cout << ": No\n";
    }

    return 0;
}
