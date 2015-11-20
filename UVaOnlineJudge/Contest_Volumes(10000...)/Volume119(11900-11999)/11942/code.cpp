#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);
    int cases, i, j, a, b;
    bool asc, desc;

    cout << "Lumberjacks:" << endl;
    cin >> cases;

    for(i = 0; i < cases; i++){
        asc = true;
        desc = true;
        cin >> a;
        for(j = 1; j < 10; j++){
            cin >> b;
            if(asc && a > b) asc = false;
            if(desc && a < b) desc = false;
            a = b;
        }

        if(asc || desc) cout << "Ordered" << endl;
        else            cout << "Unordered" << endl;
    }

    return 0;
}
