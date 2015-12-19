#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio (false);

    int cases, c, wheels, w, steps, tmp;
    string initial, target;

    cin >> cases;
    for(c = 1; c <= cases; c++){
        steps = 0;
        cin >> wheels >> initial >> target;

        for(w = 0; w < wheels; w++){
            tmp = abs(initial[w] - target[w]);
            if(tmp > 5){
                tmp = tmp - 5;
                tmp = 5 - tmp;
            }
            steps += tmp;
        }

        cout << "Case " << c << ": " << steps << "\n";
    }

    return 0;
}
