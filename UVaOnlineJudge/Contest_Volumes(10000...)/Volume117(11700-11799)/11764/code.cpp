#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, walls, a, b, high, low, i, j;

    cin >> cases;

    for(i = 1; i <= cases; i++){
        cout << "Case " << i << ": ";
        high = 0;
        low = 0;

        cin >> walls;
        //Read first wall
        cin >> a;

        for(j = 1; j < walls; j++){
            cin >> b;
            if(a < b)       high += 1;
            else if(a > b)  low += 1;
            a=b;
        }

        cout << high << " " << low << endl;
    }

    return 0;
}
